#include "headers.hpp"

bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set<int> seen;
    for(int col = 0; col < 9; col++) {
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == '.') continue;
            if(seen.count(board[i][col])) return false;
            seen.insert(board[i][col]);
        }
        seen.clear(); // O(n)
    }

    for(int row = 0; row < 9; row++) {
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == '.') continue;
            if(seen.count(board[row][i])) return false;
            seen.insert(board[row][i]);
        }
        seen.clear();
    }

    for(int square = 0; square < 9; square++) {
        int startRow = (square / 3) * 3;
        int startCol = (square % 3) * 3;
        for(int i = 0; i < 9; i++) {
            int row = startRow + i / 3;
            int col = startCol + i % 3;

            if(board[row][col] == '.') continue;
            if(seen.count(board[row][col])) return false;
            seen.insert(board[row][col]);
        }
        seen.clear();
    }
    return true;
}

int main() {


    return 0;
}