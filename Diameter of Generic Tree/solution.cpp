#include <bits/stdc++.h>
using namespace std;

pair<int, int> rec_solve(int root, vector<int> adj[], vector<int>& vis) {
    vis[root] = 1;
    
    int ht = 0;
    int dia = 0;
    int ht_best = -1;
    int ht_second_best = -1;
    for (auto next: adj[root]) {
        if (!vis[next]) {
            auto dia_height = rec_solve(next, adj, vis);
            int dia_next = dia_height.first;
            int ht_next = dia_height.second;
            ht = max(ht, ht_next);
            if (ht_next > ht_best) {
                ht_second_best = ht_best;
                ht_best = ht_next;
            } else if (ht_next > ht_second_best) {
                ht_second_best = ht_next;   
            }
            dia = max(dia, dia_next);
            int dia2 = 0;
            if (ht_best != -1) {
                dia2 = ht_best;
            }
            if (ht_second_best != -1) {
                dia2 += ht_second_best;
            }
            dia = max(dia, dia2);
        }
    }
    
    return {dia, 1 + ht};
}

int diameter(vector<int> &A) {
    int n = A.size();
    int root = 0;
    vector<int> adj[n];
    for (int i = 0; i < n; ++i) {
        if (A[i] == -1) {
            root = i;
        } else {
            adj[i].push_back(A[i]);
            adj[A[i]].push_back(i);
        }
    }
    vector<int >vis(n, 0);
    pair<int, int> res = rec_solve(root, adj, vis); // {diameter, height}
    return res.first;
}

int main () {

    vector<int> P = {-1, 0, 0, 0, 3};
    cout << diameter(P) << endl; // 3
}