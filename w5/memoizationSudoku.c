#include <stdio.h>
#include <stdbool.h>

#define N 9
#define UNASSIGNED 0

bool isSafe(int grid[N][N], int row, int col, int num);

bool solveSudoku(int grid[N][N]);

bool findUnassignedLocation(int grid[N][N], int *row, int *col);

bool solveSudokuUtil(int grid[N][N], int row, int col);

bool usedInRow(int grid[N][N], int row, int num);

bool usedInCol(int grid[N][N], int col, int num);

bool usedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num);

// Bảng memoization để lưu trữ kết quả của các ô
int memo[N][N];

// Khởi tạo bảng memoization
void initMemoization(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] != UNASSIGNED) {
                memo[row][col] = 1; // Đã điền
            } else {
                memo[row][col] = 0; // Chưa điền
            }
        }
    }
}

bool solveSudoku(int grid[N][N]) {
    // Khởi tạo bảng memoization
    initMemoization(grid);
    return solveSudokuUtil(grid, 0, 0);
}

bool solveSudokuUtil(int grid[N][N], int row, int col) {
    if (row == N - 1 && col == N) {
        return true; // Đã giải xong
    }

    if (col == N) {
        row++;
        col = 0;
    }

    if (memo[row][col]) {
        return solveSudokuUtil(grid, row, col + 1); // Đã điền
    }

    for (int num = 1; num <= N; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudokuUtil(grid, row, col + 1)) {
                memo[row][col] = 1; // Đánh dấu đã điền
                return true;
            }
            grid[row][col] = UNASSIGNED; // Hủy bỏ
        }
    }
    return false;
}

bool isSafe(int grid[N][N], int row, int col, int num) {
    return !usedInRow(grid, row, num) && !usedInCol(grid, col, num) &&
           !usedInBox(grid, row - row % 3, col - col % 3, num);
}

bool findUnassignedLocation(int grid[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == UNASSIGNED) {
                return true;
            }
        }
    }
    return false;
}

bool usedInRow(int grid[N][N], int row, int num) {
    for (int col = 0; col < N; col++) {
        if (grid[row][col] == num)
            return true;
    }
    return false;
}

bool usedInCol(int grid[N][N], int col, int num) {
    for (int row = 0; row < N; row++) {
        if (grid[row][col] == num)
            return true;
    }
    return false;
}

bool usedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + boxStartRow][col + boxStartCol] == num)
                return true;
        }
    }
    return false;
}

void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            printf("%d ", grid[row][col]);
        printf("\n");
    }
}


int main() {
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if (solveSudoku(grid)) {
        printGrid(grid);
    } else {
        printf("No solution exists");
    }

    return 0;
}
