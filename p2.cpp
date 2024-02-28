#include <iostream>
#include <vector>
#include <array>

using namespace std;

const int N = 9;

void printGrid(const array<array<int, N>, N>& grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}
bool isSafe(const array<array<int, N>, N>& grid, int row, int col, int num) {
    for (int i = 0; i < N; i++)
        if (grid[row][i] == num || grid[i][col] == num)
            return false;

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}
bool findEmptyCell(const array<array<int, N>, N>& grid, int& row, int& col) {
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == 0)
                return true;
    return false;
}
bool solveSudoku(array<array<int, N>, N>& grid) {
    int row, col;
    if (!findEmptyCell(grid, row, col))
        return true;

    
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid))
                return true;
            grid[row][col] = 0;
        }
    }

    return false;
}

int main() {
    array<array<int, N>, N> grid = {
        { {5, 3, 0, 0, 7, 0, 0, 0, 0},
          {6, 0, 0, 1, 9, 5, 0, 0, 0},
          {0, 9, 8, 0, 0, 0, 0, 6, 0},
          {8, 0, 0, 0, 6, 0, 0, 0, 3},
          {4, 0, 0, 8, 0, 3, 0, 0, 1},
          {7, 0, 0, 0, 2, 0, 0, 0, 6},
          {0, 6, 0, 0, 0, 0, 2, 8, 0},
          {0, 0, 0, 4, 1, 9, 0, 0, 5},
          {0, 0, 0, 0, 8, 0, 0, 7, 9}} };

    if (solveSudoku(grid))
        printGrid(grid);
    else
        cout << "No solution exists";

    return 0;
}
