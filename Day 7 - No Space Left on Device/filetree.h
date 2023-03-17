// This documented created following the Google C++ header style guide: https://google.github.io/styleguide/cppguide.html#C++_Version
#ifndef STRINGVECTOR
#define STRINGVECTOR
#include <string>
#include <vector>
#endif // STRINGVECTOR

#ifndef ADVENTOFCODE2022_FILETREE_H_
#define ADVENTOFCODE2022_FILETREE_H_

/* Function Declarations */

// This function extracts the name of a directory from raw command line 
// Assumes format "dir XYZ" where XYZ is an arbitrary length filename
std::string extractDir(std::string line);

// This function gets the name of a file assuming from raw command line
// Assumes format "123 XYZ" where XYZ is an arbitrary length filename
std::string extractFileName(std::string line);

// This function gets the size of a file assuming from raw command line
// Assumes format "123 XYZ" where XYZ is an arbitrary length filename
int extractFileSize(std::string line);

// This recursive function calculates the size of a folder!
// It's recursive because if the folder has any folders inside of it it
// will call itself again on those folders. The degenerate case is a
// folder with no folders inside of it.
int getFolderSize(class dir* dir_in);

/* Define Classes Here */
class file{
    public:
        // Member variables
        int size;
        std::string name;

        // Constructor
        file(int size_in, std::string name_in){
            size = size_in;
            name = name_in;
        }

        // Member functions (defined in filetree.cpp)
        // void init(std::string name, int size);

};

class dir{
    public:
        // Member variables
        int size;
        std::string name;
        class dir *parent;
        std::vector<class file> dir_files;
        std::vector<class dir> dir_dirs;

        // Constructor
        dir(std::string name_in){
            name = name_in;
            size = -1;
        }

        // Member functions (defined in filetree.cpp)
        void addDir(std::string name_in);               // Adds a folder to this directory with a name
        void addFile(int size_in, std::string name_in); // Adds a file to this directory with a name and a size
};

#endif  // ADVENTOFCODE2022_FILETREE_H_

