// This documented created following the Google C++ header style guide: https://google.github.io/styleguide/cppguide.html#C++_Version


#ifndef ADVENTOFCODE2022_RUCKSACK_H_
#define ADVENTOFCODE2022_RUCKSACK_H_

/* Function Prototypes */

// This function takes a string which encodes the contents of 1 rucksack and returns a list of items 
// shared between the first and second 'compartments' (1 compartment = 1/2 of the string).
// The number of non-terminating characters in the input string should be even.
std::string getLetters(std::string rucksack);

// This function takes an array of upper and lower-case letters which have a associated points and returns the total points
// The scoring is defined by getPoint()
int getPoints(std::string input);

// Takes a character and returns it's associated point value
// The scoring is as follows: a-z = 1-26, A-Z = 27-52
//                            i.e. a=1, b=2, A=27, B=28, etc.
int getPoint(char input);

#endif  // ADVENTOFCODE2022_RUCKSACK_H_