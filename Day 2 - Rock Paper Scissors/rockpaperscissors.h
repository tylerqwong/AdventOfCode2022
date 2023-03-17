// This documented created following the Google C++ header style guide: https://google.github.io/styleguide/cppguide.html#C++_Version


#ifndef ADVENTOFCODE2022_ROCKPAPERSCISSORS_H_
#define ADVENTOFCODE2022_ROCKPAPERSCISSORS_H_

/* Function Prototypes */

// This function takes an opponent move (either A, B, or C) and a user move (either X, Y, or Z) and returns the points
// Note that ABC and XYZ encode rock paper scissors moves in order for each player (i.e. A=rock, B=paper, etc.)
// The point system is as follows: Points = [WIN-6pts, DRAW-3pts, LOSE-0pts] + [X-1pts, Y-2pts, Z-3pts]
// i.e. if the input is O=A and U=X the output is 4=[3]+[1]
int getPoints(char O, char U);

// This function takes an opponent move (either A, B, or C) and a result (either X, Y, or Z) and returns the user move
char getMove(char O, char U);

#endif  // ADVENTOFCODE2022_ROCKPAPERSCISSORS_H_