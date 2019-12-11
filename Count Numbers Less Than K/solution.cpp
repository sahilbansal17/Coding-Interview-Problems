#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int countDigits(int X) {
    int cnt = 0;
    while (X) {
        X /= 10;
        ++cnt;
    }
    return cnt;
}

class Solution {
    public:
        int solve(vector<int> &A, int B, int C);
};

/*
 * vector<int>& A: contains the digits which can be used
 * int B: the length of which the numbers are to be formed
 * int C: the numbers formed should have value < C
 */
int Solution::solve(vector<int> &A, int B, int C) {
    // not assuming that length of C is same as B
    int total = countDigits(C);

    if (total < B) {
        return 0;
    } 
    
    int result = 0; // we can form all numbers with length B, not starting from 0
    bool zeroPresent = false;
    int n = A.size();
    
    vector<int> cnt(11, 0);
    vector<int> origCnt(11, 0);
    for (int i = 0; i < n; ++i) {
        ++cnt[A[i]];
        ++origCnt[A[i]];
        if (A[i] == 0) {
            zeroPresent = true;
        }
    }
    if (!zeroPresent) {
        result = pow(n, B);
    } else {
        result = (n - 1) * pow(n, B - 1);
    }
    
    int origC = C;
    if (total == B) {
        // need to subtract those cases where number formed is >= C
        // find suffix of cnt to represent count of digits in set >= given digit   
        for (int i = 8; i >= 0; --i) {
            cnt[i] = cnt[i] + cnt[i + 1];
        }
        
        vector<int> digits;
        while (C) {
            digits.push_back(C % 10);
            C /= 10;
        }
        reverse(digits.begin(), digits.end());
        
        int toSubtract = 0;
        // loop for every digit in C
        bool presentC = true;
        for (int i = 0; i < B; ++i) {
            int cur = digits[i];
            toSubtract += cnt[cur + 1]*pow(n, B - i - 1);
            if (origCnt[cur] == 0) {
                presentC = false;
                break;
            }
        }
        if (presentC) {
            toSubtract += 1;
        }
        result -= toSubtract;
    }
    if (B == 1 && origC > 0 && zeroPresent) {
        ++result;
    }
    return result;
}

int main () {
    Solution solver;
    vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = 3;
    int maxValue = 1000;
    cout << solver.solve(digits, length, maxValue) << endl;
    return 0;
}