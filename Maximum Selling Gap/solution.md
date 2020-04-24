# Solution

<details>
<summary> 
Hint 1
</summary>
The brute force O(N^2) solution is obvious. Try to think if you can use sorting (you might have to also store the index information) to optimize it to O(N log N).
</details>

<details>
<summary>
Hint 2
</summary>
Think if you can further reduce the complexity of your algorithm to O(N). You might need extra space.
Given a index i, we basically want to find the maximum index j, such that A[i] <= A[j].
So, does storing the suffixMax (i.e. maximum starting from a given index till the end) help?

At an index, if the suffixMax at next index is greater than it, definitely we can get a possible value from here. How to get the maximum one?
</details>

<details>
<summary>
Hint 3
</summary>
Now, also think if storing or calculating (while iterating) the prefixMin can help in some way!
</details>