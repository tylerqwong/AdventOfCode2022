// This documented created following the Google C++ header style guide: https://google.github.io/styleguide/cppguide.html#C++_Version


#ifndef ADVENTOFCODE2022_CAMP_H_
#define ADVENTOFCODE2022_CAMP_H_

/* Function Prototypes */

// Takes a string of format "A-B,C-D" where A, B, C, D are all positive integers and
// extracts and converts them into actual integers stored in the global variable
// rangevalues in order of [A, B, C, D].
void getNumbers(std::string ranges);

#endif  // ADVENTOFCODE2022_CAMP_H_