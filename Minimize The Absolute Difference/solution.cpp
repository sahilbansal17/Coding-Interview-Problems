#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int solve(vector<int> &A, vector<int> &B, vector<int> &C);
};

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int n1 = A.size();
    int n2 = B.size();
    int n3 = C.size();
    int i = 0, j = 0, k = 0;
    int res = INT_MAX;
    while (i < n1 && j < n2 && k < n3) {
        int mini = A[i], maxi = A[i];
        if (B[j] < mini) {
            mini = B[j];
        }
        if (B[j] > maxi) {
            maxi = B[j];
        }
        if (C[k] < mini) {
            mini = C[k];
        }
        if (C[k] > maxi) {
            maxi = C[k];
        }
        res = min(res, maxi - mini);
        if (A[i] == mini) {
            ++i;
        } else if (B[j] == mini) {
            ++j;
        } else {
            ++k;
        }
    }
    return res;
}

int main() {
    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B = {6, 7, 8, 9, 10};
    vector<int> C = {11, 12, 13, 14, 15};
    Solution solver;
    cout << solver.solve(A, B, C) << endl; // 6 because (5, 6, 11) is the triplet
}