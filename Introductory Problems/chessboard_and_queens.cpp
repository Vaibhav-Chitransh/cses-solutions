#include<bits/stdc++.h>
using namespace std;

unordered_map<int, bool> col_captured;
unordered_map<int, bool> diag1_captured;
unordered_map<int, bool> diag2_captured;

bool isValid(int x, int y) {
    if(col_captured[y] || diag1_captured[x+y] || diag2_captured[x-y]) return false;
    return true; 
}

void placeQueens(int row, vector<vector<char>>& board, int n, int& count) {
    if(row == n) {
        count++;
        return ;
    }

    for(int col=0; col<n; col++) {
        if(board[row][col] == '*') continue;
        if(isValid(row, col)) {
            board[row][col] = 'Q';
            col_captured[col] = true;
            diag1_captured[row+col] = true;
            diag2_captured[row-col] = true;

            placeQueens(row+1, board, n, count);

            board[row][col] = '.';
            col_captured[col] = false;
            diag1_captured[row+col] = false;
            diag2_captured[row-col] = false;
        }
    }
}

int main() {
    vector<vector<char>> board(8, vector<char>(8));
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            cin >> board[i][j];
        }
    }

    int count = 0;
    placeQueens(0, board, 8, count);

    cout << count;

    return 0;
}