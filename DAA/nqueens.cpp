#include <bits/stdc++.h>
using namespace std;

const int n = 8;
int board[n][n] = {};

bool isSafe(int row, int col){
    for(int i = 0; i < row; i ++){
        if (board[i][col] == 1) return false;
    }
    for(int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--){
        if(board[i][j] == 1) return false;
    }
    for(int i = row - 1, j = col + 1; i >=0 && j < n; i--, j++){
        if(board[i][j] == 1) return false;
    }
    return true;
}

bool solve(int row){
    if(row == n) return true;
    for (int col = 0; col < n; col++){
        if (isSafe(row, col)){
            board[row][col] = 1;
            if (solve(row+1)) return true;
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int firstCol;
    cout << "Column for the first queen (0-" << n - 1 << "): ";
    cin >> firstCol;
    board[0][firstCol] = 1;           // first queen is already placed at row 0

    if (solve(1)) {                   // start from row 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution with first queen at column " << firstCol << endl;
    }
    return 0;
}