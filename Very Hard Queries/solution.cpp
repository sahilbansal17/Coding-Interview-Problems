#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

vector<int> st; // segment tree
void build(vector<int>& arr, int v, int tl, int tr) {
    if (tl == tr) {
        st[v] = arr[tl];
    } else {
        int tm = (tl + tr)/2;
        build(arr, 2*v, tl, tm);
        build(arr, 2*v + 1, tm + 1, tr);
        st[v] = st[2*v] + st[2*v + 1];
    }
}
int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        return st[v];
    }
    int tm = (tl + tr)/2;
    return sum(2*v, tl, tm, l, min(r, tm)) 
            + sum(2*v + 1, tm + 1, tr, max(l, tm + 1), r);
}
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        st[v] = new_val;
    } else {
        int tm = (tl + tr)/2;
        if (pos <= tm) {
            update(2*v, tl, tm, pos, new_val);
        } else {
            update(2*v + 1, tm + 1, tr, pos, new_val);
        }
        st[v] = st[2*v] + st[2*v + 1];
    }
}
int countSteps(int n) {
    int root = sqrt(n);
    return min(abs(root*root - n), abs((root + 1)*(root + 1) - n));
}
int solve(vector<int> &nums, vector<vector<int> > &queries) {
    int n = nums.size();
    st.assign(4*n, 0);
    vector<int> steps(n);
    for (int i = 0; i < n; ++i) {
        steps[i] = countSteps(nums[i]);
    }
    build(steps, 1, 0, n - 1);
    
    ll ans = 0;
    for (auto query: queries) {
        int type = query[0];
        if (type == 1) {
            int id = query[1];
            int x = query[2];
            // zero-based indexing
            --id;
            update(1, 0, n - 1, id, countSteps(x));
        } else {
            int l = query[1];
            int r = query[2];
            // zero-based indexing
            --l;
            --r;
            int res = sum(1, 0, n - 1, l, r);
            ans += 1ll*res;
            ans %= MOD;
        }
    }
    return ans;
}

int main () {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> queries = {{2, 1, 1}, {2, 1, 2}, {1, 3, 1}, {2, 1, 3}};
    cout << solve(nums, queries) << endl;
    return 0;
}