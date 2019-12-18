#include <iostream>
#include <math.h>
using namespace std;

const int MAX = 110;
typedef long long ll;
const ll MOD = 1000000007;
ll ncr[MAX][MAX];
ll ways[MAX];

class Solution {
    private:
        int solveHelper(int n);
    public:
        int solve(int A);
};

int Solution::solveHelper(int n) {
    if (n <= 2) {
        return 1;
    }
    if (n == 3) {
        return 2;
    }
    if (ways[n] != -1) {
        return ways[n];
    }
    int k = ceil(1.0*(n - 1)/2);
    int hReq = log2(n);
    ll res = 0;
    for (int x = k; x < n - 1; ++x) {
        int hLeft = log2(x);
        int hRight = log2(n - x - 1);
        int lastLevelLeft = pow(2, hLeft + 1) - 1 - x;
        int lastLevelRight = pow(2, hRight + 1) - 1 - (n - x - 1);
        if (hLeft - hRight >= 2) {
            continue;
        }
        if (hLeft == hRight && lastLevelLeft > 0) {
            continue;
        }
        if (hLeft - hRight == 1 && lastLevelRight > 0) {
            continue;   
        }
        if (hLeft + 1 > hReq) {
            continue;
        }
        res += ((ncr[n - 1][x] * solveHelper(x)) % MOD * solveHelper(n - x - 1)) % MOD;
    }
    return ways[n] = res;
}

int Solution::solve(int A) {
    for (int i = 1; i < MAX; ++i) {
        ncr[i][0] = 1;
        ncr[i][i] = 1;
        ncr[i][1] = i;
    }
    for (int i = 2; i < MAX; ++i) {
        for (int j = 2; j < MAX; ++j) {
            ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
            ncr[i][j] %= MOD;
        }
    }
    
    memset(ways, -1, sizeof(ways));
    int res = solveHelper(A);
    return res;
}

int main () {
    Solution solver;
    cout << solver.solve(4) << endl;
    cout << solver.solve(5) << endl;
    cout << solver.solve(6) << endl;
}
