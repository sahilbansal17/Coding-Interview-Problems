# Largest Distance between nodes of a Tree
[Try the problem](https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/)

Given an arbitrary unweighted rooted tree which consists of `N (2 <= N <= 40000)` nodes. 

The goal of the problem is to find largest distance between two nodes in a tree. 

Distance between two nodes is a number of edges on a path between the nodes (there will be a unique path between any pair of nodes since it is a tree). 

The nodes will be numbered `0` through `N - 1`.

The tree is given as an array `P`, there is an edge between nodes `P[i]` and `i` (0 <= i < N). 

Exactly one of the i’s will have P[i] equal to -1, it will be **root node**.

### Example

```
Input:
P = [-1, 0, 0, 0, 3]
```

Tree looks like this:
```
         0
       / | \ 
      3  1  2
     / 
    4
```

```
Output: 3 (one of the longest path is 4 -> 3 -> 0 -> 2).
```