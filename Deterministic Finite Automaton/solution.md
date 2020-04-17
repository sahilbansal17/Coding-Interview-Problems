# Solution

<details>
<summary> 
Hint 1
</summary>
Being at the start state, you have two options, either to take a zeroEdge from here, or to take a oneEdge from here.

Now, your problem reduces to finding accepting string count for length (N - 1) being at this new state.
So, try to think in terms of recursion.
Make sure you end up writing base cases clearly.
</details>

<details>
<summary>
Hint 2
</summary>
Think about of base case, when the length passed is zero. Then you have two cases to consider, either the current state is accepting or non-accepting!

Now, try to take some examples and you can observe that there will be overlapping subproblems. Thus, you can use dynamic programming over here.
First of all, try to implement the memoized version of the solution, and analyze its time and space complexity.

</details>

<details>
<summary>
Hint 3
</summary>
You will notice that the recursion with memoization takes O(N*K) time where K is the no. of states, as well as `O(N*K)` memory. Thus, the solution is memory intensive.

Try to take an example, and see how the values are getting filled in the memo or cache or table. You can come up with an iterative solution that will take up linear space!
</details>