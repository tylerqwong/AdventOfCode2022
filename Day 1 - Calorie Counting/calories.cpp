#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    // Initialize filestream
    std::ifstream inf{"calories.txt"};
    if(!inf){                   // Check that ifstream opened the file correctly:
        std::cout << "Error: File Not Opened!";
        return 1;
    }

    // Initialize variables
    int highest_elf = 0;        // Tracks which elf is carrying the most calories
    int highest_cal = 0;        // Tracks how many calories that elf is carrying
    int second_elf = 0;
    int second_cal = 0;
    int third_elf = 0;
    int third_cal = 0;
    int current_elf = 0;        // Iterates the current elf
    int current_cal = 0;        // Accumulates the calories of the current elf
    std::string cal;            // string used to store every value read out of the calories.txt file

    // Find the Elf with the highest 
    while(inf){                 // For as long as we haven't reached EOF...
        
        current_elf++;          // Assumes that the first elf is '1' and not '0'
        current_cal = 0;        // Reset the current calories accumulator

        while(1){               // Calculate calories for the next elf...
            std::getline(inf, cal);  // Get the current calory value of the current elf
            if(cal.length() > 1){    // If the current calory value is a valid value...
                current_cal = current_cal + stoi(cal);          // Add the calories to the current elf's calory count
            }
            else{               // If we end up here then we've reached the end of the current elf!
                break;          
            }
                
        }

        // Some checks need to happen here to update highest_elf and highest_cal
        if(current_cal>highest_cal){
            third_elf = second_elf;
            second_elf = highest_elf;
            highest_elf = current_elf;

            third_cal = second_cal;
            second_cal = highest_cal;
            highest_cal = current_cal;
        }
        else if(current_cal>second_cal){
            third_elf = second_elf;
            second_elf = current_elf;

            third_cal = second_cal;
            second_cal = current_cal;
        }
        else if(current_cal>third_cal){
            third_cal = current_cal;

            third_elf = current_elf;
        }
    }

    std::cout << "Elf #" << highest_elf << " is carrying " << highest_cal << '\n';
    std::cout << "Elf #" << second_elf << " is carrying " << second_cal << '\n';
    std::cout << "Elf #" << third_elf << " is carrying " << third_cal << '\n';
    std::cout << "Togethery they carry: " << third_cal+second_cal+highest_cal << '\n';

    return 0;

}