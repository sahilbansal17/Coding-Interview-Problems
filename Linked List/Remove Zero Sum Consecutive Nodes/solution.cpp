#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int curSum = 0;
        ListNode* cur = head;
        unordered_map<int, ListNode*> seen_sum;
        seen_sum[0] = cur;

        while (cur) {
            curSum += cur->val;
            ListNode* seen_node = NULL;
            if (seen_sum.find(curSum) != seen_sum.end()) {
                seen_node = seen_sum[curSum];
            }
            if (seen_node) {
                ListNode* temp;
                if (curSum == 0) {
                    temp = seen_node; 
                }
                else {
                    temp = seen_node->next;
                }
                int temp_sum = curSum;
                // remove the extra keys from the seen_sum
                while (temp != cur) {
                    temp_sum += temp->val;
                    seen_sum.erase(temp_sum);
                    temp = temp->next;
                }
            }
            if (curSum == 0) {
                // delete all nodes from first node to cur node
                seen_sum[0] = cur->next;
            } else if (seen_node) {
                // update the next pointer to delete the intermediate nodes
                seen_node->next = cur->next;
            } else {
                seen_sum[curSum] = cur;
            }
            cur = cur->next;
        }
        return seen_sum[0];
    }
    void printList(ListNode* head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main () {
    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    head->next = new ListNode(2);
    cur = cur->next;
    cur->next = new ListNode(3);
    cur = cur->next;
    cur->next = new ListNode(-3);
    cur = cur->next;
    cur->next = new ListNode(-2);

    Solution solver;
    solver.removeZeroSumSublists(head);
    solver.printList(head); // 1
}