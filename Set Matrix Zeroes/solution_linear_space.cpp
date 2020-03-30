#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) {
            return;
        }
        int cols = matrix[0].size();
        
        vector<int> row_zero(rows, 0);
        vector<int> col_zero(cols, 0);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    row_zero[i] = 1;
                    col_zero[j] = 1;
                }
            }
        }
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (row_zero[i] || col_zero[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main () {
    Solution solver;
    vector<vector<int> > matrix = {{0, 1, 2, 0},
                                    {3, 4, 5, 2},
                                    {1, 3, 1, 5}};
    solver.setZeroes(matrix);

    for (auto row: matrix) {
        for (auto x: row) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}