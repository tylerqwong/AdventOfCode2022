// This documented created following the Google C++ header style guide: https://google.github.io/styleguide/cppguide.html#C++_Version


#ifndef ADVENTOFCODE2022_TUNING_H_
#define ADVENTOFCODE2022_TUNING_H_

/* Function Prototypes */

// This function compares the first four characters in the input string.
// If all the characters are different it returns 0
// If some of the characters match it returns a pos int corresponding to the minimum number
// of new characters needed s.t. the 4 characters could be all different again.
// I.E. if the input is "aabc" it will return 3 as adding 3 random characters will give "XXXa"
// I.E. if the input is "abac" it will reutnr 2 as adding 2 random characters will give "XXab"
int checkSOP(std::string buffer);

// This function fulfills the same purpose as checkSOP14 but instead of comparing the first 4
// characters it comapres the first 14 characters!
int checkSOP14(std::string buffer);

#endif  // ADVENTOFCODE2022_TUNING_H_