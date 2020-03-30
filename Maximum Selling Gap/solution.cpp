#include <vector>

using namespace std;

int maxSellingGap(const vector<int>& price) {

    int num = price.size();

    vector<int> suffix_max(num);
    suffix_max[num - 1] = price[num - 1];
    for (int idx = num - 2; idx >= 0; --idx) {
        suffix_max[idx] = max(price[idx], suffix_max[idx + 1]);
    }

    int left = 0;
    int right = num - 1;

    int maxGap = 0;
    int minPrefix = -1;
    while (left < num) {
        int elem = price[left];
        // 5 7 1 9 6 3 2
        // 9 9 9 9 6 3 2
        //         ^

        if (minPrefix == -1) {
            // first iteration
            while (suffix_max[right] < elem) {
                --right;
            }
        } else if (minPrefix > elem) {
            // shift the right to right
            while (right < num && suffix_max[right] < elem) {
                ++right;
            }
        }
        minPrefix = min(minPrefix, elem);

        if (right < num && price[right] >= elem) {
            maxGap = max(maxGap, right - left);
        }
        ++left;
    }

    return maxGap;
}