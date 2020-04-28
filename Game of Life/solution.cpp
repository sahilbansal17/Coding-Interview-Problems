#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    int dx[8] = {-1, -1, -1, 0, 0, +1, +1, +1};
    int dy[8] = {-1, 0, +1, -1, +1, -1, 0, +1};
    bool isSafe(int x, int y, int N, int M) {
        if (x < 0 || y < 0) {
            return false;
        }
        if (x >= N || y >= M) {
            return false;
        }
        return true;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int N = board.size();
        int M = board[0].size();
        for (int row = 0; row < N; ++row) {
            for (int col = 0; col < M; ++col) {
                // count no. of live neighbors
                int neighbors = 0;
                for (int k = 0; k < 8; ++k) {
                    int x = row + dx[k];
                    int y = col + dy[k];
                    if (isSafe(x, y, N, M) && board[x][y] >= 1) {
                        ++neighbors;
                    }
                }
                if (board[row][col] == 1) {
                    // update the cell with neighbors count
                    if (neighbors != 0) {
                        board[row][col] = neighbors;
                    }
                } else {
                    // update the cell with -neighbors count 
                    board[row][col] = -neighbors;
                }
            }
        }
        
        for (int row = 0; row < N; ++row) {
            for (int col = 0; col < M; ++col) {
                int neighbors = board[row][col];
                if (neighbors > 0) {
                    if (neighbors < 2) { // live cell with < 2 live neighbors dies
                        board[row][col] = 0;
                    } else if (neighbors <= 3) { // with 2-3 lives
                        board[row][col] = 1;
                    } else { // dies due to over-population
                        board[row][col] = 0;
                    }
                } else {
                    if (neighbors == -3) { // dead cell with 3 live neighbors
                        board[row][col] = 1;
                    } else {
                        board[row][col] = 0;
                    }
                }
            }
        }
    }
};

int main () {
    vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};

    Solution solver;
    solver.gameOfLife(board);

    for (auto row: board) {
        for (auto elem: row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}