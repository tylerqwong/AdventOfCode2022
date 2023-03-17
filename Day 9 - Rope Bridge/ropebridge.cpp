#include <iostream>
#include <vector>
#include <string>
#include <fstream>
//User Includes and static variables
#include "headertemplate.h"
#define GRID_SIZE   5       // Range of test.txt movement is 5
// #define GRID_SIZE   100     // Range of ropebridge.txt movement is ???
static int s_ropeGrid[GRID_SIZE][GRID_SIZE] = {};   // Used to track where the tail is at all times
int s_headPos[2] = {0, 0};  // Starting location of the rope head
int s_tailPos[2] = {0, 0};  // Starting location of the rope tail

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
    int acc = 0;            // Accumulates (counts) the number of tail positions after rope physic simulation
    char dir = ' ';         // Holds the direction of the current command
    int dis = 0;            // Holds the distance of the current command

    std::string line;       // Used to save each line of the input data text file 

    while(inf){
        std::getline(inf, line);    // Get the next command
        // Extract the direction
        // Extract the distance
        for(int i=0; i<dis; i++){   // Iterate through the steps of that command
            // Update s_headPos
            // Update s_tailPos
            // Mark tail position on s_ropeGrid()
        }
    }
    
    // Iterate through the ropegrid and accumulate all visited coordinates
    for(int i=0; i<GRID_SIZE; i++){
        for(int j=0; j<GRID_SIZE; j++){
            if(s_ropeGrid[i][j] == 1){
                acc++;
            }
        }
    }
    std::cout << "Number of unique coordinates visited by tail:" << acc << '\n';

    return 0;
}

/* Function Definitions */

