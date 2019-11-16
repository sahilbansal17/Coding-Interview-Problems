# Minimize The Absolute Difference
[Try the problem](https://www.interviewbit.com/problems/minimize-the-absolute-difference/)

Given three sorted arrays A, B and C of not necessarily same sizes.

Calculate the **minimum absolute difference* between the maximum and minimum number from the triplet (a, b, c) such that a, b, c belong to the arrays A, B and C respectively, i.e.
minimize |max(a, b, c) - min(a, b, c)| for all possible triplets.

### Example

```
Input: 
A : [ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]

Output:
1

We get the minimum difference for a=5, b=6, c=6 as | max(a,b,c) - min(a,b,c) | = |6-5| = 1.
```