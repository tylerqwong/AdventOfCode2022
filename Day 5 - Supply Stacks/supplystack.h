// This documented created following the Google C++ header style guide: https://google.github.io/styleguide/cppguide.html#C++_Version


#ifndef ADVENTOFCODE2022_SUPPLYSTACK_H_
#define ADVENTOFCODE2022_SUPPLYSTACK_H_

/* Function Prototypes */

// This function takes a string of format "move X from Y to Z" where XYZ are positive integeres.
// It then saves these integers in the static array called 'currentmove' in order X, Y, and Z
// currentmove is set to [0, 0, 0] if the input is invalid.
void getMove(std::string line);

#endif  // ADVENTOFCODE2022_SUPPLYSTACK_H_