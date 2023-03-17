// This documented created following the Google C++ header style guide: https://google.github.io/styleguide/cppguide.html#C++_Version


#ifndef ADVENTOFCODE2022_TREEHOUSE_H_
#define ADVENTOFCODE2022_TREEHOUSE_H_

/* Function Declarations */

// This function takes the co-ordinates of a tree in a 2d grid and calculates the "scenic
// score" of that tree by counting the number of trees which are visible from it in each
// cardinal direction and multiplying them together.
// i.e. if you look west from 4 in row "12351245" the westView is '3'
int getView(int row, int col);

#endif  // ADVENTOFCODE2022_TREEHOUSE_H_