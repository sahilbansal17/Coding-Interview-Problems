#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	int numWays[25][2010];
	int solve(int idx, vector<int>& nums, int target) {
		if (target > 1000) {
            return 0;
        }
        if (idx == nums.size()) {
			if (target == 0) {
				return 1;
			}
			return 0;
		}
		if (numWays[idx][1000 + target] != -1) {
			return numWays[idx][1000 + target];
		}
		return numWays[idx][1000 + target] = solve(idx + 1, nums, target - nums[idx]) 
											+ solve(idx + 1, nums, target + nums[idx]);
	}
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		memset(numWays, -1, sizeof(numWays));
		return solve(0, nums, S);
	}
};

int main () {

	Solution solver;
	int N, target;
	cin >> N >> target;
	vector<int> nums(N);
	for (auto &i: nums) {
		cin >> i;
	}
	cout << solver.findTargetSumWays(nums, target) << endl;
	return 0;
}
