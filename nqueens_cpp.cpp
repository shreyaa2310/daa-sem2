#include <iostream>
#include <vector>
using namespace std;

int N;

// Check if it's safe to place queen
bool isSafe(vector<vector<int>>& board, int row, int col) {
    // Check column
    for(int i = 0; i < row; i++)
        if(board[i][col])
            return false;

    // Check left diagonal
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if(board[i][j])
            return false;

    // Check right diagonal
    for(int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if(board[i][j])
            return false;

    return true;
}

// Recursive function
bool solve(vector<vector<int>>& board, int row) {
    if(row == N) {
        // Print solution
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        return true; // change to false if all solutions needed
    }

    for(int col = 0; col < N; col++) {
        if(isSafe(board, row, col)) {
            board[row][col] = 1;   // place queen

            if(solve(board, row + 1))
                return true;

            board[row][col] = 0;   // backtrack
        }
    }
    return false;
}

int main() {
    cout << "Enter number of queens: ";
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));

    if(!solve(board, 0))
        cout << "No solution exists\n";

    return 0;
}