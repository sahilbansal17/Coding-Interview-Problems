# Very Hard Queries
[Try the problem](https://www.interviewbit.com/problems/very-hard-queries/)

You are given an array A having n integers.
You have to perform some very hard queries on A.
There are 2 types of queries:
- 1 id X, change A[id] with X.
- 2 L R, you have to find the minimum number of steps required to change all elements in [L, R] such that
every element in [L, R] will have the odd number of divisors. In one step you can choose any element from A and can add or subtract 1 from it.

Note that in the second type of query, the array does not change.

### Input Format

```
The 1st argument given is an integer array nums.
The 2nd argument given is a 2D integer array queries, where queries[i] denotes ith query
```

### Output Format

```
Return an Integer X % (1e9 + 7), the sum of answer for each query of type 2.   
```

### Example 

```
Input:
    A = [1, 2, 3]
    B = [[2, 1, 1], [2, 1, 2], [1, 3, 1], [2, 1, 3]]
Output:
    2
   
Explanation:
    query 1: we don't need any steps as 1 has an odd number of divisors, so the answer is 0.
    query 2: in 1 step we can change 2 to 1, so the answer is 1.
    query 3: change value of A[3] with 1, array after the 3rd query is A = [1, 2, 1]
    query 4: again in 1 step we can change 2 to 1, so answer is 1.
    
	So the sum of answers to all queries of type 2 is 2.
```

<details>
<summary> 
Hint 1
</summary>
What is so special about a number having odd number of divisors? Can you use it to find the minimum no. of steps to change a number to get to a number with odd no. of divisors?
</details>

<details>
<summary> 
Hint 2
</summary>
Does the problem reduce to finding out the sum of values in a given range along with some update queries?
Which data structure can you use here to optimize the brute force solution?
</details>

<details>
<summary> 
Hint 3
</summary>
Read and learn about segment trees: https://cp-algorithms.com/data_structures/segment_tree.html
</details>