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
        
        // check if first row contains a zero
        bool first_zero = false;
        for (int i = 0; i < cols; ++i) {
            if (matrix[0][i] == 0) {
                first_zero = true;
            }
        }
        
        // put zeroes in first row if the column has zero
        for (int j = 0; j < cols; ++j) {
            for (int i = 0; i < rows; ++i) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                }
            }
        }
        
        // set zeroes in the matrix
        for (int i = 1; i < rows; ++i) {
            // check if row has zero
            bool row_zero = false;
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    row_zero = true;
                }
            }
            // if row has zero or the first row's particular element has zero
            for (int j = 0; j < cols; ++j) {
                if (matrix[0][j] == 0 || row_zero) {
                    matrix[i][j] = 0;
                }
            }
        }
        // put zeroes in the first row only if first_zero is true
        if (first_zero) {
            for (int i = 0; i < cols; ++i) {
                matrix[0][i] = 0;
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