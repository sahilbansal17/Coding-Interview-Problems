#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
/*
ll cache[60][4010];

ll solve(int start, int N, vector<int>& zero, vector<int>& one, vector<int>& accepting) {
    if (N == 0) {
        if (accepting[start]) {
            return 1;
        }
        return 0;
    }
    if (cache[start][N] != -1) {
        return cache[start][N];   
    }
    ll res = 0;
    res += solve(zero[start], N - 1, zero, one, accepting);
    res %= MOD;
    res += solve(one[start], N - 1, zero, one, accepting);
    return cache[start][N] = res;
}
*/
int automata(vector<int> &zeroEdge, vector<int> &oneEdge, vector<int> &accepting, int start, int N) {
    // memset(cache, -1, sizeof(cache));
    
    int states = zeroEdge.size();
    vector<int> acceptingState(states, 0);
    for (auto acc: accepting) {
        acceptingState[acc] = 1;
    }
    // return (int)solve(start, N, zeroEdge, oneEdge, acceptingState);
    
    /**
     * Time: O(N*K) where N = length, K = no of states 
     * Space: O(K) 
     * Iterative Dynamic Programming
     */
    vector<ll> acceptingBefore(states, 0); // for length (i - 1)
    vector<ll> acceptingCurrent(states, 0); // for length (i)
    for (int i = 0; i < states; ++i) {
        if (acceptingState[i]) {
            acceptingCurrent[i] = 1; // for length 0, it is accepting
        }
    }
    
    for (int len = 1; len <= N; ++len) {
        acceptingBefore = acceptingCurrent;
        for (int state = 0; state < states; ++state) {
            acceptingCurrent[state] = (acceptingBefore[zeroEdge[state]] + acceptingBefore[oneEdge[state]]) % MOD;
        }
    }
    
    // only consider strings accepted with start state and having length N
    return (int)acceptingCurrent[start];
}

int main () {
    vector<int> zeroEdges = {0, 2, 1};
    vector<int> oneEdges = {1, 0, 2};
    vector<int> accepting = {0};
    int start = 0;
    int length = 2;
    cout << automata(zeroEdges, oneEdges, accepting, start, length) << endl;
    return 0;
}