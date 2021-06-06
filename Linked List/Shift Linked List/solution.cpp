#include <bits/stdc++.h>
using namespace std;

class LinkedList {
 public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    next = nullptr;
  }
};

LinkedList *shiftLinkedList(LinkedList *head, int k) {
  int n = 0;
  LinkedList *temp = head;
  LinkedList *tail = NULL;
  while (temp) {
    tail = temp;
    temp = temp->next;
    ++n;
  }
  if (n <= 1) {
    return head;
  }
  k = k % n;
  if (k < 0) {
    k += n;
  }
  if (k == 0) {
    return head;
  }
  LinkedList *new_head = head;
  LinkedList *prev = NULL;
  for (int i = 0; i < n - k; ++i) {
    prev = new_head;
    new_head = new_head->next;
  }
  prev->next = NULL;
  tail->next = head;

  return new_head;
}

vector<int> linkedListToArray(LinkedList *head) {
  vector<int> array{};
  auto current = head;
  while (current != nullptr) {
    array.push_back(current->value);
    current = current->next;
  }
  return array;
}

int main() {
  auto head = new LinkedList(0);
  head->next = new LinkedList(1);
  head->next->next = new LinkedList(2);
  head->next->next->next = new LinkedList(3);
  head->next->next->next->next = new LinkedList(4);
  head->next->next->next->next->next = new LinkedList(5);
  auto result = shiftLinkedList(head, 2);
  auto array = linkedListToArray(result);

  for (auto e : array) {
    cout << e << " ";
  }
  cout << endl;

  vector<int> expected{4, 5, 0, 1, 2, 3};
  assert(expected == array);

  return 0;
}