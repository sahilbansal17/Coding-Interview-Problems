#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = gas[i] - cost[i];
        }

        int res = -1;
        int curPos = 0;
        int curSum = 0;
        int i = 0;

        bool traversed = false;
        while (!traversed) {
            curPos = i;
            bool cnt = true;
            bool possible = true;
            // while either the first element starting from curPos
            // or not come back to it as end position
            while (cnt || curPos != i) {
                // first position
                if (cnt) {
                    cnt = !cnt; // set cnt to false
                    curSum = diff[curPos];
                } else {
                    curSum += diff[curPos];
                }
                // if reach negative fuel, break
                if (curSum < 0) {
                    curSum = 0;
                    possible = false;
                    break;
                }
                curPos = (curPos + 1) % n;
                // hit 0 atleast once, set traversed to true
                if (curPos == 0) {
                    traversed = true;
                }
            }
            if (possible) {
                res = i;
                break;
            } else {
                // start from nextPosition in next iteration
                i = (curPos + 1) % n;
                // if hit 0, set traversed to true
                if (i == 0) {
                    traversed = true;
                }
            }
        }
        return res;
    }
};

int main () {
    Solution solver;
    vector<int> gas = {5, 3, 2, 4, 2};
    vector<int> cost = {2, 6, 4, 1, 3};

    cout << solver.canCompleteCircuit(gas, cost) << endl; // 3

    gas = {5, 3, 2, 4, 1};
    cout << solver.canCompleteCircuit(gas, cost) << endl; // -1

    return 0;
}