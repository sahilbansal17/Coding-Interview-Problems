# Shift Linked List
[Try the problem](https://www.algoexpert.io/questions/Shift%20Linked%20List)

Write a function that takes in the head of a Singly Linked List and an integer `k`, shifts the list in place by `k` positions, and returns its new head.


Shifting a Linked List means moving its nodes forward or backward and wrapping them around the list where appropriate. For example, shifting a Linked List forward by one position would make its tail become the new head of the linked list.


Whether nodes are moved forward or backward is determined by whether `k` is positive or negative.

Each `LinkedList` node has an integer `value` as well as a `next` node pointing to the next node in the list or to `None` / `null` if it's the tail of the list.
  

### Example 

#### Sample Input
- head = 0 -> 1 -> 2 -> 3 -> 4 -> 5
- k = 2

#### Sample Output

- 4 -> 5 -> 0 -> 1 -> 2 -> 3