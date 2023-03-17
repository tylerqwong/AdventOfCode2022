#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "rockpaperscissors.h"

using namespace std;

// Goal: to calculate our final score in a rock paper scissors tournament using the following rules and strategy guide format:
// Opponent: A = Rock, B = Paper, C = Scissors
// Us:       X = Rock, Y = Paper, Z = Scissors
// Points:
//      Winning gives us 6 points, Draws give us 3 points, Losing gives us 0 points
//      Additionally picking Rock gives us 1 point, Paper gives us 2 points, Scissors gives us 1 point

// NOTE: this returns a correct value but if you want to be perfectionist than getPoints needs a better way to handle the last empty line

int main()
{
    // Initialize filestream
    std::ifstream inf{"rockpaperscissors.txt"};
    if(!inf){                   // Check that ifstream opened the file correctly:
        std::cout << "Error: File Not Opened!";
        return 1;
    }

    // Initialize variables
    int points = 0;     // Points accumulator
    std::string round;  // The moves from each round get stored in here 1 at a time

    while(inf){
        // Get the next line and extract the moves from it
        std::getline(inf, round);

        // Part 1 Solution: XYZ=ROCK/PAPER/SCISSORS
        //points = points + getPoints(round[0], round[2]); 

        // Part 2 Solution: XYZ=LOSE/DRAW/WIN
        points = points + getPoints(round[0], getMove(round[0], round[2]));

    }

    std::cout << to_string(points) << '\n';

    return 0;
}

/* Function Definitions*/

int getPoints(char O, char U){
    switch(O){
        case 'A': // Opponent selected ROCK
            if (U=='X') // User Selected ROCK
                return 1+3;
            if (U=='Y') // User selected PAPER
                return 2+6;
            if (U=='Z') // User selected SCISSORS
                return 3+0;
            throw std::invalid_argument( "getPoints() invalid U argument \n" );
        case 'B': // Opponent selected PAPER
            if (U=='X') // User Selected ROCK
                return 1+0;
            if (U=='Y') // User selected PAPER
                return 2+3;
            if (U=='Z') // User selected SCISSORS
                return 3+6;
            throw std::invalid_argument( "getPoints() invalid U argument \n" );
        case 'C': // Opponent selected SCISSORS
            if (U=='X') // User Selected ROCK
                return 1+6;
            if (U=='Y') // User selected PAPER
                return 2+0;
            if (U=='Z') // User selected SCISSORS
                return 3+3;
            throw std::invalid_argument( "getPoints() invalid U argument \n" );
        default:
            std::cout << "getPoints() invalid O argument \n";
            return 0;
    }

}

char getMove(char O, char U){
    switch(O){
        case 'A': // Opponent selected ROCK
            if (U=='X') // User must LOSE
                return 'Z'; // Select SCISSORS
            if (U=='Y') // User must DRAW
                return 'X'; // Select ROCK
            if (U=='Z') // User must WIN
                return 'Y'; // Select PAPER
            throw std::invalid_argument( "getPoints() invalid U argument \n" );
        case 'B': // Opponent selected PAPER
            if (U=='X') // User must LOSE
                return 'X'; // Select ROCK
            if (U=='Y') // User must DRAW
                return 'Y'; // Select PAPER
            if (U=='Z') // User must WIN
                return 'Z'; // Select SCISSORS
            throw std::invalid_argument( "getPoints() invalid U argument \n" );
        case 'C': // Opponent selected SCISSORS
            if (U=='X') // User must LOSE
                return 'Y'; // Select PAPER
            if (U=='Y') // User must DRAW
                return 'Z'; // Select SCISSORS
            if (U=='Z') // User must WIN
                return 'X'; // Select ROCK
            throw std::invalid_argument( "getPoints() invalid U argument \n" );
        default:
            std::cout << "getPoints() invalid O argument \n";
            return 0;
    }

}
