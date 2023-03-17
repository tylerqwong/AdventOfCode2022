#include <iostream>
#ifndef STRINGVECTOR
#define STRINGVECTOR
#include <string>
#include <vector>
#endif // STRINGVECTOR
#include <fstream>
//User Includes and static variables
#include "filetree.h"
#define TOTAL_SPACE     70000000
#define CURRENT_SPACE   22129546
#define NEEDED_SPACE    (30000000 - CURRENT_SPACE)

static int file_acc = 0;    // Used by getFolderSize (which recursively gets the size of each folder) to accumulate

using namespace std;

// "filetree.txt" contains a list of console commands and responses which represent a traversal through
// a large file system:
//      $ cd x  // Move in to directory 'x'
//      $ cd .. // Move to the directory which contains the current directory
//      $ ls    // List the objects contained within the current directory such as...
//      123 abc // ...a file with name "abc" and size "123"
//      dir xyz // ...a directory with name "xyz"

// Our end-goal is to find sum size of all directories with size<100000 (individual files can be counted more than once)
// That sum turns out to be 1667443

// Our part 2 goal is to find the smallest folder to delete given our current '/' size, TOTAL_SPACE, and CURRENT_SPACE
// That folder turns out to be "bjlcfcfq" of size 8998590

/* Class Method Definitions */

void dir::addDir(std::string newName){
    // Adds a folder to this directory with a name
    class dir tempDir(newName);
    dir_dirs.push_back(tempDir);
    return;
}

void dir::addFile(int size_in, std::string name_in){
    // Adds a file to this directory with a name and a size
    class file tempFile(size_in, name_in);
    dir_files.push_back(tempFile);
    return;
}

int main()
{
    // Initialize filestream
    std::ifstream inf{"filetree.txt"};
    if(!inf){                   // Check that ifstream opened the file correctly:
        std::cout << "Error: File Not Opened!";
        return 1;
    }

    // Initialize Variables
    class dir headDir("/");         // Points to the head of the overall filetree
    class dir *currentDir;          // Points to the current directory, allows us to navigate the filetree
    currentDir = &headDir;          // Position in the filetree initializes to the head directory
    std::string line;               // Used to save each line of the input data text file 

    std::getline(inf, line);        // First line is always "$ cd /"
    std::getline(inf, line);        // Second line is always "$ ls"

    // Read a "$ ls" command
    while(inf){

        // "$ ls" command detected... so add all contents to the current dir
        if(line == "$ ls"){         
            while(1){
                std::getline(inf, line);
                if(line.find('$') != std::string::npos){            // If line is a command...
                    break;                                          // ...then exit the loop
                }
                else if(line.find("dir") != std::string::npos){     // If line is a directory...
                    (*currentDir).addDir(extractDir(line));         // ...then create a new dir object within current dir
                }
                else if(line.length() > 0){                         // If line is a file... create the file
                    (*currentDir).addFile(extractFileSize(line), extractFileName(line));
                }
                else{                                               // If the line is empty...
                    break;                                          // ... EOF so break!
                }
            }
        }
        // "$ cd" command detected... so traverse currentDir so that it points to the appropriate dir
        else if(line[2] == 'c'){
            // Go up one folder by accessing the parent (parent is set when going down into a folder)
            if(extractDir(line) == ".."){
                currentDir = (*currentDir).parent;
            }
            // Go down one folder
            for(int i=0; i<(*currentDir).dir_dirs.size(); i++){     // Find the right folder first
                if(extractDir(line) == (*currentDir).dir_dirs[i].name){ // If the dir matches the command...
                    (*currentDir).dir_dirs[i].parent = currentDir;          // ...Set the parent of the next dir
                    currentDir = &(*currentDir).dir_dirs[i];                // ...Set the currentDir to the next dir
                    break;                                                  // ...Exit the for loop (we found it)
                }
            }
            std::getline(inf, line);                                // Load up the next line
        }
    }

    // HERE IS WHERE WE HAVE THE FULL TREE OBJECT! (minus folder sizes)


    currentDir = &headDir;                      // Set the pointer back to the head of the tree
    int totalSize = getFolderSize(currentDir);  // Call getFolderSize to populate dir.size values
    std::cout << "Size of '/' is " << totalSize << '\n';
}

/* Function Definitions */

std::string extractDir(std::string line){
    // This function extracts the name of a directory from raw command line 
    // Assumes format "dir XYZ" OR "$ cd XYZ" where XYZ is an arbitrary length filename
    std::string retString;

    if(line[0] == 'd'){
        for(int i=4; i<line.length(); i++){
            retString += line[i];
        }
    }
    else{
        for(int i=5; i<line.length(); i++){
            retString += line[i];
        }
    }

    return retString;
}

std::string extractFileName(std::string line){
    // This function gets the name of a file assuming from raw command line
    // Assumes format "123 XYZ" where XYZ is an arbitrary length filename
    std::string retString;

    for(int i=line.find_first_of(' ')+1; i<line.length(); i++){
        retString += line[i];
    }

    return retString;
}

int extractFileSize(std::string line){
    // This function gets the size of a file assuming from raw command line
    // Assumes format "123 XYZ" where XYZ is an arbitrary length filename
    std::string retString;
    int retInt;

    for(int i=0; i<line.find_first_of(' '); i++){
        retString += line[i];
    }

    return stoi(retString);
}

int getFolderSize(class dir* dir_in){
    // This recursive function calculates the size of a folder!
    // It's recursive because if the folder has any folders inside of it it
    // will call itself again on those folders. The degenerate case is a
    // folder with no folders inside of it.
    int retInt = 0;

    for(int i=0; i<(*dir_in).dir_files.size(); i++){    // For each file in the folder...
        retInt += (*dir_in).dir_files[i].size;          // ...add the files size to the accumulator
    }

    for(int i=0; i<(*dir_in).dir_dirs.size(); i++){     // For each dir in the folder
        if((*dir_in).dir_dirs[i].size == -1){           // ...check if the dir size has been calculated
            (*dir_in).dir_dirs[i].size = getFolderSize(&( (*dir_in).dir_dirs[i]) );    // If it hasn't, calculate it
        }
        retInt += (*dir_in).dir_dirs[i].size;           // Then add the dir size to the accumulator
    }

    if(retInt < 100000){
        file_acc += retInt;
    }

    if(retInt > NEEDED_SPACE){
        std::cout << "dir " << (*dir_in).name << " has size " << retInt << '\n';
    }
    return retInt;                                      // return the accumulator
}
