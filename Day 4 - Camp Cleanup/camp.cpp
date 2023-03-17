#include <iostream>
#include <vector>
#include <string>
#include <fstream>
//User Includes and static variables
#include "camp.h"
static int rangevalues[4];      // Used by getNumbers() to pass rangevalues in format [lower1, higher1, lower2, higher2]


using namespace std;

// Goal:    We are given a text file containing pairs of ranges of number (i.e. 2-3 + 5-7). Our goal is to find
//          the number of pairs where one range is fully encapsulated by the other.


int main()
{
    // Initialize filestream
    std::ifstream inf{"camp.txt"};
    if(!inf){                   // Check that ifstream opened the file correctly:
        std::cout << "Error: File Not Opened!";
        return 1;
    }

    // Initialize variables
    int acc = 0;
    std::string ranges;

    while(inf){

        // get a line
        std::getline(inf, ranges);
        // extract the 4 integeres associated with that line
        getNumbers(ranges);
        // Check for encapsulation
        if(rangevalues[0] <= rangevalues[2] && rangevalues[1] >= rangevalues[3]){
            // std::cout << rangevalues[0] << '-' << rangevalues[1] << " encapsulates " << rangevalues[2] << '-' << rangevalues[3] << '\n';
            acc++;
        }
        else if(rangevalues[0] >= rangevalues[2] && rangevalues[1] <= rangevalues[3]){
            // std::cout << rangevalues[2] << '-' << rangevalues[3] << " encapsulates " << rangevalues[0] << '-' << rangevalues[1] << '\n';
            acc++;
        }
        // Check for overlap
        else if(rangevalues[0] >= rangevalues[2] && rangevalues[0] <= rangevalues[3]){
            acc++;
        }
        else if(rangevalues[1] >= rangevalues[2] && rangevalues[1] <= rangevalues[3]){
            acc++;
        }
    }

    std::cout << "final count: " << acc << '\n';
}

/* Function Definitions */
void getNumbers(std::string ranges){
    // Takes a string of format "A-B,C-D" where A, B, C, D are all positive integers and
    // extracts and converts them into actual integers stored in the global variable
    // rangevalues in order of [A, B, C, D]. Clears rangevalues[] at the start.
    // Behaviour undefined if input string not formatted correctly.

    // Initialize Variables
    int sep1, sep2, sep3, sep4;                     // Separators used to track where the numbers are in each line
    std::string lower1, lower2, higher1, higher2;   // Strings used to store each number, to be converted into ints
    for (int i=0; i<4; i++){                        // Set rangevalues to a 'safe' value (i.e. will not be counted)
        rangevalues[i] = i;
    }

    // Get the indexes of separator characters '-' and ','
    if(ranges.length() < 1){
        return;
    }

    sep1 = ranges.find_first_of('-');
    sep2 = ranges.find_first_of(',');
    sep3 = ranges.find_last_of('-');
    sep4 = ranges.length();

    // Get the first number
    lower1.clear();
    for(int i=0; i<sep1; i++){
        lower1.push_back(ranges[i]);
    }
    rangevalues[0] = stoi(lower1);
    // std::cout << rangevalues[0] << '\n';

    // Get the second number
    higher1.clear();
    for(int i=sep1+1; i<sep2; i++){
        higher1.push_back(ranges[i]);
    }
    rangevalues[1] = stoi(higher1);
    // std::cout << rangevalues[1] << '\n';

    // Get the third number
    lower2.clear();
    for(int i=sep2+1; i<sep3; i++){
        lower2.push_back(ranges[i]);
    }
    rangevalues[2] = stoi(lower2);
    // std::cout << rangevalues[2] << '\n';

    // Get the fourth number
    higher2.clear();
    for(int i=sep3+1; i<sep4; i++){
        higher2.push_back(ranges[i]);
    }
    rangevalues[3] = stoi(higher2);
    // std::cout << rangevalues[3] << '\n';
}

