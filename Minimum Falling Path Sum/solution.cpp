#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int> > &A) {
        int rows = A.size(); // 3
        int cols = A[0].size(); // 3
        vector<vector<int> > minSum(rows, vector<int> (cols, 0)); // 3*3 with all 0's
        // set for first row
        for (int curCol = 0; curCol <cols; ++curCol) {
            minSum[0][curCol] = A[0][curCol]; // {1, 2, 3} is the first row
        }
        // solve for all other rows, value depends on top, topleft and topright
        for (int curRow = 1; curRow < rows; ++curRow) {
            for (int curCol = 0; curCol < cols; ++curCol) {
                int curMinSum = INT_MAX;
                int prevRow = curRow - 1;
                for (int k = -1; k <= 1; ++k) {
                    int prevCol = curCol + k;
                    if (prevCol >= 0 && prevCol < cols) {
                        curMinSum = min(curMinSum, minSum[prevRow][prevCol]);
                    }
                }
                // curMinSum is 1 for the cell valued 4, i.e. (1, 0)
                minSum[curRow][curCol] = A[curRow][curCol] + curMinSum;
                // minSum[1][0] = 4 + 1 = 5
            }
        }
        // minSum at the end = { {1, 2, 3}, {5, 6, 8}, {12, 13, 15} }
        // result is the minimum value in the last row
        int res = INT_MAX;
        for (int curCol = 0; curCol < cols; ++curCol) {
            res = min(res, minSum[rows - 1][curCol]);
        }
        return res; // 12
    }
};

int main () {
    Solution solver;
    vector<vector<int> > A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << solver.minFallingPathSum(A) << endl;
}