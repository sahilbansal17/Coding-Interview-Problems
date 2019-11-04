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
    bool isValid(TreeNode* root, int minVal, int maxVal, bool noMin, bool noMax) {
        if (root == NULL) {
            return true;
        }
        if (!noMin && root->val <= minVal) {
            return false;
        }
        if (!noMax && root->val >= maxVal) {
            return false;
        }
        bool rightValid = false;
        bool leftValid = false;
        rightValid = isValid(root->right, root->val, maxVal, false, noMax);
        leftValid = isValid(root->left, minVal, root->val, noMin, false);
        return rightValid && leftValid;
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root, 0, 0, true, true);
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