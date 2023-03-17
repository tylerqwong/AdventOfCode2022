#include <iostream>
#include <vector>
#include <string>
#include <fstream>
//User Includes and static variables
#include "tuning.h"

using namespace std;

// Purpose:     Scan a stream of lower case characters and identify the start-of-packet marker. The 
//              start-of-packet is the 1st sequence of 4 characters which are all different.

// Input:       A stream of lower case characters
// Output:      A positive integer 'n' where the nth character is the 4th character of the 
//              start-of-packet marker.

int main()
{
    // Initialize filestream
    std::ifstream inf{"tuning.txt"};
    if(!inf){                   // Check that ifstream opened the file correctly:
        std::cout << "Error: File Not Opened!";
        return 1;
    }

    // Initialize Variables
    int acc = 0;                // Tracks the number of characters iterated through so far
    int skip = 0;               // Saves the number of times we need to skip ahead after each checkSOP call
    char next_char = '0';       // Used to save each line of the input data text file
    std::string buffer;         // Treat as a queue, call buffer.insert() and buffer.pop_back() together after initial load

    // Load the first 14 characters
    for(int i=0; i<14; i++){
        inf.get(next_char);
        buffer.insert(buffer.begin(), next_char);
        acc++;
    }

    while(inf){
        skip = checkSOP14(buffer);    // Check for start-of-packet signal
        if(skip==0){                // If SOP signal detected then exit loop
            break;
        }
        for(int i=0; i<skip; i++){  // Push next char to queue an appropriate number of times
            inf.get(next_char);
            buffer.insert(buffer.begin(), next_char);
            acc++;
            buffer.pop_back();
        }
    }

    std::cout << acc << '\n';

}

/* Function Definitions */

int checkSOP(std::string buffer){
    // This function compares the first four characters in the input string.
    // If all the characters are different it returns 0
    // If some of the characters match it returns a pos int corresponding to the minimum number
    // of new characters needed s.t. the 4 characters could be all different again.
    // I.E. if the input is "aabc" it will return 3 as adding 3 random characters will give "XXXa"
    // I.E. if the input is "abac" it will reutnr 2 as adding 2 random characters will give "XXab"

    if(buffer[0]==buffer[1]){
        return 3;
    }
    else if(buffer[0]==buffer[2] || buffer[1]==buffer[2]){
        return 2;
    }
    else if(buffer[0]==buffer[3] || buffer[1]==buffer[3] || buffer[2]==buffer[3]){
        return 1;
    }
    else{
        return 0;
    }
}

int checkSOP14(std::string buffer){
    // This function fulfills the same purpose as checkSOP14 but instead of comparing the first 4
    // characters it comapres the first 14 characters!

    for(int i=1; i<14; i++){            // Iterate the 2nd number of each comparison check
        for(int j=0; j<i; j++){         // Iterate the 1st number of each comparison check
            if(buffer[i]==buffer[j]){   // If we find a match...
                return (14-i);          // ...then skip ahead until the 2nd number of the detected pair exits the buffer
            }
        }
    }

    return 0;
}

