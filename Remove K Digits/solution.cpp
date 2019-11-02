#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        stack<char> st;
        for (int i = 0; i < n; ++i) {
            if (st.empty()) {
                st.push(num[i]);
            } else if (st.top() > num[i] && k > 0) {
                while (!st.empty() && st.top() > num[i] && k > 0) {
                    st.pop();
                    --k;
                }
                st.push(num[i]);
            } else {
                st.push(num[i]);
            }
        }
        while (!st.empty() && k > 0) {
            st.pop();
            --k;
        }
        string res;
        if (st.empty()) {
            res = '0';
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        // remove leading zeroes
        string finalRes;
        int firstIdx = 0;
        int finalLen = res.length();
        while (firstIdx < finalLen && res[firstIdx] == '0') {
            ++firstIdx;
        }
        if (firstIdx == finalLen) {
            finalRes = '0';
        } else {
            while (firstIdx < finalLen) {
                finalRes += res[firstIdx];
                ++firstIdx;
            }
        }
        return finalRes;
    }
};

int main() {
    Solution solver;

    cout << solver.removeKdigits("1234567890", 9) << endl;
}