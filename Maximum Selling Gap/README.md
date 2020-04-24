# Max Selling Gap
[Try the problem](https://www.interviewbit.com/problems/max-distance/)

Given an array `A` of integers, find the maximum of `j - i` subjected to the constraint of `A[i] <= A[j]`.

If there is no solution possible, return `-1`.

### Example 1

```
Input: [3,5,4,2]
Output: 2
Explanation: For the pair (3, 4).
```

### Example 2
```
Input: [5,7,1,9,6,3,2]
Output: 4
Explanation: For the pair (1, 2). There could be other answers but they'll have the same maximum gap.
```