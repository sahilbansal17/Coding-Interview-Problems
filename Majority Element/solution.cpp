/*
 * Program to find the majority element in an array
 * using Boyer Moore's voting algorithm: O(N) time and O(1) space
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityIdx = 0;
        int n = nums.size();
        int curCount = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[majorityIdx]) {
                // decreases the effective count
                --curCount;
            } else {
                ++curCount;
            }
            if (curCount == 0) {
                // count of nums[majorityIdx] equals those not equal to it
                majorityIdx = i + 1;
            }
        }
        return nums[majorityIdx];
    }
};

/*
// Using O(N) space

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    unordered_map<int, int> count;
    int res = -1;
    for (auto x: a) {
        ++count[x];
        if (count[x] > n/2) {
            res = x;
        }
    }
    cout << res << endl;
}
*/

int main () {
    Solution solver;
    vector<int> inp = {1, 1, 1, 1, 2, 2};
    cout << solver.majorityElement(inp) << endl;
    return 0;
}