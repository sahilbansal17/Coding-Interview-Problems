# Remove Zero Sum Consecutive Nodes from Linked List

Given the `head` of a linked list, we repeatedly delete consecutive sequences of nodes that sum to `0` until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

### Example 1

```
Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.
```

### Example 2

```
Input: head = [1,2,3,-3,4]
Output: [1,2,4]
```

### Example 3

```
Input: head = [1,2,3,-3,-2]
Output: [1]
```