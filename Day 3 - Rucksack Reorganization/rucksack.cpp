#include <iostream>
#include <vector>
#include <string>
#include <fstream>
//User Includes
#include "rucksack.h"

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
    std::string rucksack;   // Used to save each line of the input data text file 
    // Get points



    while(inf){
        std::getline(inf, rucksack);    // Read out the next line of the rucksack.txt file
        acc += getPoints(getLetters(rucksack));
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

