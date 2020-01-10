#include <iostream>
#include <queue>
#include <utility>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return root;
        }
        queue<pair<Node*, int> > q;
        q.push({root, 0});
        int prevLevel = 0;
        Node* prevNode = NULL;
        while (!q.empty()) {
            auto front = q.front();
            auto node = front.first;
            auto level = front.second;
            q.pop();
            if (prevLevel != level) {
                prevNode->next = NULL;
                prevLevel = level;
                prevNode = node;
            } else {
                if (prevNode) {
                    prevNode->next = node;
                }
                prevNode = node;
            }
            if (node->left) {
                q.push({node->left, level + 1});
            }
            if (node->right) {
                q.push({node->right, level + 1});
            }      
        }
        return root;
    }
};

int main () {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solver;
    root = solver.connect(root);

    Node* cur = root;
    while (cur) {
        Node* temp = cur;
        while (temp) {
            cout << temp->val << " " ;
            temp = temp->next;
        }
        cout << endl;
        cur = cur->left;
    }
    /*
    Output:
    1
    2 3
    4 5 6 7
    */

    return 0;
}