#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insertLeft(TreeNode* root, int value) {
    root->left = new TreeNode(value);
    return root->left;
}

TreeNode* insertRight(TreeNode* root, int value) {
    root->right = new TreeNode(value);
    return root->right;
}

class Solution {
public:
    pair<int, int> solve(TreeNode* node, bool& res) {
        int val = node->val;
        pair<int, int> p[2];
        // handle corner cases
        
        int *minRight = NULL;
        int *maxLeft = NULL;
        if (node->left) {
            p[0] = solve(node->left, res);
            maxLeft = new int;
            *maxLeft = p[0].second;
        }
        if (node->right) {
            p[1] = solve(node->right, res);
            minRight = new int;
            *minRight = p[1].first;
        }
        if (maxLeft && val <= *maxLeft) {
            res = false;
        }
        if (minRight && val >= *minRight) {
            res = false;
        }
        
        pair<int, int> returnPair;
        int overallMin = node->val, overallMax = node->val;
        if (maxLeft) {
            overallMax = max(overallMax, *maxLeft);
            overallMin = min(overallMin, p[0].first);
        }
        if (minRight) {
            overallMax = max(overallMax, p[1].second);
            overallMin = min(overallMin, *minRight);
        }
        returnPair.first = overallMin;
        returnPair.second = overallMax;
        // cout << overallMin << " " << overallMax << endl;
        return returnPair;
    }
    bool isValidBST(TreeNode* root) {
        bool res = true;
        // handle corner cases
        if (!root) {
            return res;
        }
        pair<int, int> vals = solve(root, res);
        return res;
    }
};

int main() {
    auto root1 = new TreeNode(50);
    Solution solver;
    cout << solver.isValidBST(root1) << endl; // true

    auto root2 = new TreeNode(50);
    insertLeft(root2, 30);
    insertLeft(root2->left, 10);
    insertRight(root2, 70);
    insertRight(root2->right, 80);
    insertRight(root2->left, 40);
    insertLeft(root2->right, 60);
    cout << solver.isValidBST(root2) << endl; // true

    auto root3 = new TreeNode(50);
    insertLeft(root3, 30);
    insertLeft(root3->left, 20);
    insertRight(root3, 80);
    insertRight(root3->right, 90);
    insertRight(root3->left, 60);
    insertLeft(root3->right, 70);
    cout << solver.isValidBST(root3) << endl; // false
}