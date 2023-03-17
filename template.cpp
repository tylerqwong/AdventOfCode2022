#include <iostream>
#include <vector>
#include <string>
#include <fstream>
//User Includes and static variables
#include "headertemplate.h"

using namespace std;

/* File Description */


/* Class Function Definitions */

int main()
{
    // Initialize filestream
    std::ifstream inf{"test.txt"};
    if(!inf){                   // Check that ifstream opened the file correctly:
        std::cout << "Error: File Not Opened!";
        return 1;
    }

    // Initialize Variables
    int acc = 0;            // Accumulates...
    std::string line;       // Used to save each line of the input data text file 

    // Get a line of the file...
    std::getline(inf, line);

    std::cout << line << '\n';
}

/* Function Definitions */

