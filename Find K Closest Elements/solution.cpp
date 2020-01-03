#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int n = arr.size();
	int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
	int left = idx - 1;
	int right = idx;
	vector<int> res;
	while (res.size() < k) {
		int diff_left = INT_MAX; 
		int diff_right = INT_MAX;
		if (left >= 0) {
			diff_left = abs(arr[left] - x);
		}
		if (right < n) {
			diff_right = abs(arr[right] - x);
		}
		if (diff_left <= diff_right) {
			res.push_back(arr[left]);
			--left;
		} else {
			res.push_back(arr[right]);
			++right;
		}
	}
	sort(res.begin(), res.end());
	return res;  
    }
};

int main() {
    Solution solver;
    vector<int> inp({2, 6, 8, 13, 14, 15});
    int k = 3;
    int x = 10;

    vector<int> res = solver.findClosestElements(inp, k, x); // [6, 8, 13]
    for (auto elem: res) {
        cout << elem << " ";
    }
    cout << endl;
}