#include <iostream>
#include <vector>
#include <string>
#include <fstream>
//User Includes and static variables
#include "supplystack.h"
static int currentmove[3];

using namespace std;

// Initial State of stacks
//     [M]             [Z]     [V]    
//     [Z]     [P]     [L]     [Z] [J]
// [S] [D]     [W]     [W]     [H] [Q]
// [P] [V] [N] [D]     [P]     [C] [V]
// [H] [B] [J] [V] [B] [M]     [N] [P]
// [V] [F] [L] [Z] [C] [S] [P] [S] [G]
// [F] [J] [M] [G] [R] [R] [H] [R] [L]
// [G] [G] [G] [N] [V] [V] [T] [Q] [F]
//  1   2   3   4   5   6   7   8   9 

// Note that the standard template library contains an implementation of the stack container (via #include<stack>)
// I should look into how that implementation of stack<char> would compare to the current implementation which uses
// standard strings and the push_back(), pop_back(), and back() methods.

int main()
{
    // Initialize filestream
    std::ifstream inf{"supplystack.txt"};
    if(!inf){                   // Check that ifstream opened the file correctly:
        std::cout << "Error: File Not Opened!";
        return 1;
    }

    // Initialize Variables
    int acc = 0;            // Accumulates the priority values for each rucksack
    std::string line;       // Used to save each line of the input data text file 
    // Initialize stack states
    std::string stackarray[] = {"GFVHPS", "GJFBVDZM", "GMLJN", "NGZVDWP", "VRCB", "VRSMPWLZ", "THP", "QRSNCHZV", "FLGPVQJ"};
    std::string flipstack; // This array is used to maintain the order of crates when multiple crates are transferred in a single move

    while(inf){
        // Execute...
        std::getline(inf, line);    // Get the next line of the program (of format "move X from Y to Z")
        // std::cout << line << '\n';  // Print the line
        getMove(line);              // Extract the values from the line into the currentmove array
        // Execute currentmove (part 1 implementation)
        // for(int i=0; i<currentmove[0]; i++){
        //     stackarray[currentmove[2]-1].push_back(stackarray[currentmove[1]-1].back()); // Copy the top value of Y and append to Z
        //     stackarray[currentmove[1]-1].pop_back();                                     // Delete the top value of Y
        // }
        // Execute currentmove (part 2 implementation)
        for(int i=0; i<currentmove[0]; i++){
            // Move crates from Y to the flipstack
            flipstack.push_back(stackarray[currentmove[1]-1].back());
            stackarray[currentmove[1]-1].pop_back();
        }
        for(int i=0; i<currentmove[0]; i++){
            // Move crates from the flipstack to X
            stackarray[currentmove[2]-1].push_back(flipstack.back());
            flipstack.pop_back();
        }
    }

    for(int i=0; i<9; i++){
        std::cout << stackarray[i].back();
    }
}

/* Function Definitions */

void getMove(std::string line){
    // This function takes a string of format "move X from Y to Z" where XYZ are positive integeres.
    // It then saves these integers in the static array called 'currentmove' in order X, Y, and Z
    // currentmove is set to [0, 0, 0] if the input is invalid.

    // Initialize Variables
    int sep1, sep2, sep3, sep4, sep5, sep6;// These variables used to track what indices XYZ are at in the 'line' string
    std::string X, Y, Z;                // These strings used to temporarily store the XYZ extracted integers
    for(int i=0; i<3; i++){
        currentmove[i] = 0;
    }

    // If the input is invalid, exit here
    if(line.length() < 1){
        return;
    }

    // Extract separators
    sep1 = 4;
    // std::cout << sep1 << '\n';
    sep2 = line.find(" from");
    // std::cout << sep2 << '\n';
    sep3 = sep2 + 5;
    // std::cout << sep3 << '\n';
    sep4 = line.find(" to");
    // std::cout << sep4 << '\n';
    sep5 = sep4 + 3;
    // std::cout << sep5 << '\n';
    sep6 = line.length();
    // std::cout << sep6 << '\n';

    // Using separators, write extract XYZ values
    for(int i=sep1+1; i<sep2; i++){
        X.push_back(line[i]);
    }
    currentmove[0] = stoi(X);
    // std::cout << currentmove[0] << ", ";

    for(int i=sep3+1; i<sep4; i++){
        Y.push_back(line[i]);
    }
    currentmove[1] = stoi(Y);
    // std::cout << currentmove[1] << ", ";

    for(int i=sep5+1; i<sep6; i++){
        Z.push_back(line[i]);
    }
    currentmove[2] = stoi(Z);
    // std::cout << currentmove[2] << '\n';

    return;
}

