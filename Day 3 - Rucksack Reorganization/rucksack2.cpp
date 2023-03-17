#include <iostream>
#include <vector>
#include <string>
#include <fstream>
//User Includes
#include "rucksack2.h"

using namespace std;

int main()
{
    // Initialize filestream
    std::ifstream inf{"rucksack.txt"};
    if(!inf){                   // Check that ifstream opened the file correctly:
        std::cout << "Error: File Not Opened!";
        return 1;
    }

    // Initialize Variables
    int acc = 0;            // Accumulates the priority values for each rucksack
    std::string team1;      // Used to save each line of the input data text file 
    std::string team2;      //      Now in pairs of 3 to match the 3-person teams
    std::string team3;
    char badge;

    while(inf){
        // Get the next team's rucksacks 
        std::getline(inf, team1);
        std::getline(inf, team2);
        std::getline(inf, team3);

        // Find the ONE shared character between all 3 team members
        badge = getBadge(team1, team2, team3);
        if(badge != 0){
            acc += getPoint(badge);
        }

    }

    std::cout << acc << '\n';
}

/* Function Definitions */
std::string getLetters(std::string rucksack){
    // This function takes a string which encodes the contents of 1 rucksack and returns a list of items 
    // shared between the first and second 'compartments' (1 compartment = 1/2 of the string).
    // The number of non-terminating characters in the input string should be even.

    // Initialize variables
    int len = rucksack.length();    // len/2 is used to denote the midpoint separating each compartment
    std::string output;             // This string holds every character shared between the first and last compartment
    std::size_t foundindex;


    for (int i=0; i<(len/2); i++){  // Iterative through the 1st compartment

        for (int j=(len/2); j<len; j++){    // Compare the 1st compartment to every character in the 2nd compartment
            if(rucksack[i]==rucksack[j]){
                //std::cout << rucksack[i] << " is found at indexes " << i << " and " << j << '\n'; // Debugging print
                // If the result is unique then add it to the output string
                if(output.find_first_of(rucksack[i]) == string::npos){
                    output += rucksack[i];

                }
                break;                      // We don't care if it matches multiple times so break
            }
        }
    }

    //std::cout << output << '\n';                                                                    // Debugging print
    return output;

}

int getPoints(std::string input){
    // This function takes an array of upper and lower-case letters which have a associated points and returns the total points
    // The scoring is defined by getPoint()

    // Initialize Variables
    int acc = 0;

    for(int i=0; i<input.length(); i++){
        acc += getPoint(input[i]);
    }

    return acc;
}

int getPoint(char input){
    // Takes a character and returns it's associated point value
    // The scoring is as follows: a-z = 1-26, A-Z = 27-52
    //                            i.e. a=1, b=2, A=27, B=28, etc.
    if(islower(input) != 0){
        return (int)(input-96);
    }
    return (int)(input-38);
}

char getBadge(std::string team1, std::string team2, std::string team3){
    // This function takes three strings and finds one character common to all three strings
    // and returns that character. Behaviour is undefined if no such character exists.

    for(int i=0; i<team1.length(); i++){
        if(team2.find_first_of(team1[i]) != string::npos){      // If character of index i in team1 is found in team2...
            if(team3.find_first_of(team1[i]) != string::npos){  // ...and also found in team3
                return team1[i];                                    // Then output that character!
            }
        }

    }

    return 0;
}
