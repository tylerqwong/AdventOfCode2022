#include <iostream>
#include <vector>
#include <string>
#include <fstream>
//User Includes and static variables
#include "treehouse.h"
// #define GRID_SIZE   5   // test.txt grid size is 5x5
#define GRID_SIZE   99  // treehouse.txt size is 100x100
static int s_treeGrid[GRID_SIZE][GRID_SIZE] = {};    // Input file is loaded into here, each element is an int within (0, 9)
static int s_ghostGrid[GRID_SIZE][GRID_SIZE] = {};   // Tracks whether or not a tree is visible, init. as "all trees invisible"

using namespace std;

/* File Description */

// We are given a grid of numbers representing the height of a grid of trees.
// Our goal is to count the number of trees which can be seen from the edge of
// the grid. This is defined as "there exists a straight path in a cardinal
// direction between a tree and the edge of the grid where there are no taller
// trees"

// The final (pt 1) output value should be the # of trees that are visible

// Initial thought is that we need to...
//      1. Load the entire file into a 2d array variable
//      2. Create a ghost array of bools which only tracks whether or not a tree is visible
//      3. Check each cell for a path to the West edge + update the ghost map
//      4. Repeat step 3 for North, East, and South
//      5. Iterate through the ghost array and count visible trees

// PART 2
// Now we want to find the tree with the best scenic score which is calculated
// by taking the viewing distance in each direction and multiplying them by 
// each other. I.e. #4 in the sequence "15234" has a viewing distance of 3

// Something I want to get better at is standardizing my naming conventions. A
// tentative plan might be:
//      - #define'd constants are UPPER_CASE
//      - class names are one-word and Capitalized and should be nouns
//      - function names are camelCase() and should begin with a verb
//      - variable names should be camelCase
//          - class member variables are pre-pended with 'm'
//          - static variables are pre-pended with 's'
//          - pointer variables are pre-pended with 'p'


/* Class Function Definitions */

int main()
{
    // Initialize filestream
    std::ifstream inf{"treehouse.txt"};
    if(!inf){                   // Check that ifstream opened the file correctly:
        std::cout << "Error: File Not Opened!";
        return 1;
    }

    // Initialize Variables
    int acc = 0;            // Accumulates...
    std::string line;       // Used to save each line of the input data text file
    int checkFlag;

    // 1. load the entire file into s_treeGrid
    for(int i=0; i<GRID_SIZE; i++){         // i indexes the row #
        std::getline(inf, line);
        for(int j=0; j<GRID_SIZE; j++){     // j indexes the col #
            s_treeGrid[i][j] = (int)line[j] - 48;
        }
    }

    /* Part 1

    // 2. s_ghostGrid already initialized (NOTE: 0=>"invisible" and 1=>"visible")

    // 3. Check each cell for a past to the Western edge of the grid + update s_ghostGrid as appropriate
    for(int i=0; i<GRID_SIZE; i++){
        checkFlag = -1; // Set a check flag
        for(int j=0; j<GRID_SIZE; j++){
            if(checkFlag < s_treeGrid[i][j]){ // If current tree > all trees so far...
                s_ghostGrid[i][j] = 1;        // ...then update the s_ghostGrid...
                checkFlag = s_treeGrid[i][j]; // ...and the checkFlag
            }
            // Could probably see if checkFlag = 9 (max value) and break in order to speed up this program...
        }
    }

    // 4. Same but for Northern edge
    for(int i=0; i<GRID_SIZE; i++){
        checkFlag = -1;
        for(int j=0; j<GRID_SIZE; j++){
            if(checkFlag < s_treeGrid[j][i]){
                s_ghostGrid[j][i] = 1;
                checkFlag = s_treeGrid[j][i];
            }
        }
    }

    // 4. Same but for Eastern edge
    for(int i=0; i<GRID_SIZE; i++){
        checkFlag = -1;
        for(int j=(GRID_SIZE-1); j>-1; j--){
            if(checkFlag < s_treeGrid[i][j]){
                s_ghostGrid[i][j] = 1;
                checkFlag = s_treeGrid[i][j];
            }
        }
    }

    // 4. Same but for Southern edge
    for(int i=0; i<GRID_SIZE; i++){
        checkFlag = -1;
        for(int j=(GRID_SIZE-1); j>-1; j--){
            if(checkFlag < s_treeGrid[j][i]){
                s_ghostGrid[j][i] = 1;
                checkFlag = s_treeGrid[j][i];
            }
        }
    }

    // 5. Iterate through the ghost grid and count the number of visible trees
    for(int i=0; i<GRID_SIZE; i++){
        for(int j=0; j<GRID_SIZE; j++){
            if(s_ghostGrid[j][i] == 1){
                acc++;
                std::cout << '1';
            }
            else{
                std::cout << '0';
            }
        }
        std::cout << '\n';
    }

    std::cout << "Number of visible trees: " << acc << '\n';
    */

    /* Part 2 */
    int maxView = 0;
    int tempVal = 0;

    // Calculate view score!
    // getView(1, 20);
    for(int i=0; i<GRID_SIZE; i++){
        for(int j=0; j<GRID_SIZE; j++){
            tempVal = getView(i, j);
            if(tempVal > maxView){
                maxView = tempVal;
                std::cout << "New highest scenic score of " << maxView << " found at " << i << ' ' << j << '\n';
            }
        }
    }

    return 0;
}

/* Function Definitions */

int getView(int row, int col){
    // This function takes the co-ordinates of a tree in a 2d grid and calculates the "scenic
    // score" of that tree by counting the number of trees which are visible from it in each
    // cardinal direction and multiplying them together.
    // i.e. if you look west from 4 in row "12351245" the westView is '3'

    // Variable Declarations
    int westView = 0;
    int eastView = 0;
    int northView = 0;
    int southView = 0;

    // Look East
    for(int j=(col+1); j<GRID_SIZE; j++){
        eastView++;
        if(s_treeGrid[row][j] >= s_treeGrid[row][col]){
            break;
        }
    }
    // Look West
    for(int j=(col-1); j>-1; j--){
        westView++;
        if(s_treeGrid[row][j] >= s_treeGrid[row][col]){
            break;
        }
    }
    // Look North
    for(int i=(row-1); i>-1; i--){
        northView++;
        if(s_treeGrid[i][col] >= s_treeGrid[row][col]){
            break;
        }
    }
    // Look South
    for(int i=(row+1); i<GRID_SIZE; i++){
        southView++;
        if(s_treeGrid[i][col] >= s_treeGrid[row][col]){
            break;
        }
    }

    return eastView * southView * northView * westView;
}


