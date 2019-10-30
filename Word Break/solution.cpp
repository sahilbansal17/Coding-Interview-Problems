#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        // canBreak[i] denotes whether we can break the string starting from the i-th index
        bool canBreak[n];
        memset(canBreak, false, sizeof(canBreak));
        map<string, int> isWord;
        for (auto word: wordDict) {
            isWord[word] = 1;
        }
        for (int i = n - 1; i >= 0; --i) {
            string cur = s.substr(i, 1);
            bool canBreakCur = false;
            for (int k = i + 1; k < n; ++k) {
                canBreakCur |= canBreak[k] && isWord[cur];
                if (canBreakCur == true) {
                    break;
                }
                cur += s[k];
            }
            if (isWord[cur]) {
                canBreakCur = true;
            }
            canBreak[i] = canBreakCur;
        }
        return canBreak[0];
    }
};

int main() {
    Solution solver;
    vector<string> wordDict = {"a", "bcd", "cd"};
    cout << solver.wordBreak("abcd", wordDict) << endl; // 1
    cout << solver.wordBreak("acde", wordDict) << endl; // 0
    return 0;
}