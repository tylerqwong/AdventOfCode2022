#include <iostream>
#include <vector>
#include <string>
#include <fstream>
//User Includes and static variables
#include "ropebridge.h"
#define GRID_SIZE   5       // Range of test.txt movement is 5
// #define GRID_SIZE   100     // Range of ropebridge.txt movement is ???
static int s_ropeGrid[GRID_SIZE][GRID_SIZE] = {};   // Used to track where the tail is at all times
static int s_headPos[2] = {0, 0};  // Starting location of the rope head
static int s_tailPos[2] = {0, 0};  // Starting location of the rope tail

using namespace std;

/* File Description */
// TODO:
//      Write problem description
//      Create a function which updates a node position based on input command
//      Create a function which updates a node position based on the the relative position of the next node

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
        dir = line[0];              // Extract the direction (U, D, L, or R)
        dis = line[2];              // Extract the distance
        for(int i=0; i<dis; i++){   // Iterate through the steps of that command
            // Update s_headPos (make into it's own function?)
            if(dir == 'U'){
                s_headPos[1]++;
            }
            else if(dir == 'D'){
                s_headPos[1]--;
            }
            else if(dir == 'L'){
                s_headPos[0]--;
            }
            else{ // dir == 'R'
                s_headPos[0]++;
            }

            // Update s_tailPos

            // Mark tail position on s_ropeGrid()
        }
    }
    
    // // Iterate through the ropegrid and accumulate all visited coordinates
    // for(int i=0; i<GRID_SIZE; i++){
    //     for(int j=0; j<GRID_SIZE; j++){
    //         if(s_ropeGrid[i][j] == 1){
    //             acc++;
    //         }
    //     }
    // }
    std::cout << "Number of unique coordinates visited by tail:" << acc << '\n';

    return 0;
}

/* Function Definitions */

void printGrid(){
    // This function prints a visual representation of the rope position
    // It references the #defined value "GRID SIZE"
    // Currently, it is hardcoded to only print the head and tail node, intermediate nodes are not considered
    for(int j=GRID_SIZE-1; j>-1; j--){                         // Iterate through Y positions (must go top to bottom)
        for(int i=0; i<GRID_SIZE; i++){
            if(s_headPos[0]==i && s_headPos[1]==j){
                std::cout << 'H';
            }
            else if(s_tailPos[0]==i && s_tailPos[1]==j){
                std::cout << 'T';
            }
            else{
                std::cout << '*';
            }
        }
        std::cout << '\n';
    }
}
