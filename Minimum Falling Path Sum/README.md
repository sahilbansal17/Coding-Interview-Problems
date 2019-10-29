# Minimum Falling Path Sum
[Try the problem](https://leetcode.com/problems/minimum-falling-path-sum/)

Given a matrix of integers, we want to find the **minimum** sum of *falling path* through it.

A falling path starts at any element in the first row, and chooses one element from each row.
<br/>
The next row's choice must be in a column that is different from the previous row's column by atmost one.

### Example

```
Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: 12
Explanation: 
The possible falling paths are:
```

- `[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]`
- `[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]`
- `[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]`

The falling path with the smallest sum is `[1,4,7]`, so the answer is `12`.