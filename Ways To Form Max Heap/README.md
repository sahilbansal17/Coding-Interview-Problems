# Ways To Form Max Heap
[Try the problem](https://www.interviewbit.com/problems/ways-to-form-max-heap/)

Max Heap is a special kind of complete binary tree in which for every node, the value present in that node is greater than the value present in it’s children nodes.

So now the problem statement for this question is:

How many distinct Max Heaps can be made from `N` distinct integers?

In short, you have to ensure the following properties for the max heap :
1. Heap has to be a complete binary tree ( A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible. )
2. Every node is greater than all its children.

Let us take an example of 4 distinct integers. Without loss of generality let us take `1 2 3 4` as our 4 distinct integers.

Following are the possible max heaps from these 4 numbers :

```
        4 
       / \ 
      3   2 
     / 
    1
```
```
        4 
       / \ 
      2   3 
     / 
    1
```
```
        4 
       / \ 
      3   1 
     / 
    2
```

As the final answer can be very large output your answer modulo `1000000007`.

Assume that `N <= 100`.

### Examples

```
Input: 4
Output: 3 
```

```
Input: 5
Output: 8
```