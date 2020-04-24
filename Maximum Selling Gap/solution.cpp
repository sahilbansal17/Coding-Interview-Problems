#include <vector>
#include <iostream>
using namespace std;

int maxSellingGap(const vector<int>& price) {

    int num = price.size();

    vector<int> suffix_max(num);
    suffix_max[num - 1] = price[num - 1];
    for (int idx = num - 2; idx >= 0; --idx) {
        suffix_max[idx] = max(price[idx], suffix_max[idx + 1]);
    }

    int left = 0;
    int right = 0;

    int maxGap = 0;
    int minPrefix = price[0];
    while (left < num && right < num) {
        int elem = price[left];
        //      5 7 1 9 6 3 2
        //      5 5 1 1 1 1 1 (minPrefix)
        //      9 9 9 9 6 3 2 (suffix_max)
        //          ^

        minPrefix = min(minPrefix, elem);
        if (minPrefix <= suffix_max[right]) {
            maxGap = max(maxGap, right - left);
            ++right;
        } else {
            ++left;
        }
    }

    return maxGap;
}

int main () {
    vector<int> price = {5,7,1,9,6,3,2};
    cout << maxSellingGap(price) << endl;
    return 0;
}