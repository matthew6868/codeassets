/*
 *  Source: https://leetcode.com/problems/island-perimeter/
 *  Author: matthew6868(mxu.public@outlook.com)
 *  Date: 2016-12-1
 *
    463. Island Perimeter
    Total Accepted: 6952
    Total Submissions: 11997
    Difficulty: Easy
    Contributors: amankaraj
    You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

    Example:

    [[0,1,0,0],
    [1,1,1,0],
    [0,1,0,0],
    [1,1,0,0]]

    Answer: 16
    Explanation: The perimeter is the 16 yellow stripes in the image below:
 */

 int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
    int perimeter = 0;
    
    for (int row = 0; row < gridRowSize; row++) {
        for (int col = 0; col < gridColSize; col++) {
            if (grid[row][col] == 1) {
                int sum = 4;
                // check left
                if (col > 0) {
                    if (grid[row][col - 1] == 1) {
                        sum--;
                    }
                }
                // check right
                if (col < gridColSize - 1) {
                    if (grid[row][col + 1] == 1) {
                        sum--;
                    }
                }
                // check up
                if (row > 0) {
                    if (grid[row -1][col] == 1) {
                        sum--;
                    }
                }
                // check down
                if (row < gridRowSize -1) {
                    if (grid[row + 1][col] ==1) {
                        sum--;
                    }
                }
                
                perimeter += sum;
            }
        }
    }
    
    return perimeter;
}