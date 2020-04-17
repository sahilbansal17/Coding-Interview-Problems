# Deterministic Finite Automaton
[Try the problem](https://www.interviewbit.com/problems/deterministic-finite-automaton/)

Deterministic finite automaton(DFA) is a finite state machine that accepts/rejects finite strings of symbols and only produces a unique computation (or run) of the automation for each input string.

- DFAs can be represented using state diagrams. For example, in the automaton shown below, there are three states: S0, S1, and S2 (denoted graphically by circles). 
- The automaton takes a finite sequence of 0s and 1s as input. 
- For each state, there is a transition arrow leading out to a next state for both 0 and 1. 
- Upon reading a symbol, a DFA jumps deterministically from a state to another by following the transition arrow. 
- For example, if the automaton is currently in state S0 and current input symbol is 1 then it deterministically jumps to state S1. 
- A DFA has a start state (denoted graphically by an arrow coming in from nowhere) where computations begin, and a set of accept states (denoted graphically by a double circle) which help define when a computation is successful.

![multiples_of_3](https://upload.wikimedia.org/wikipedia/commons/9/94/DFA_example_multiplies_of_3.svg)

These are some strings above DFA accepts,

```
0
00
000
11
110
1001
```

You are given a DFA in input and an integer N. You have to tell how many distinct strings of length N the given DFA accepts. Return answer modulo 10<sup>9</sup>+7.

### Notes

1. Assume each state has two outgoing edges(one for 0 and one for 1). Both outgoing edges won’t go to the same state.
2. There could be multiple accept states, but only one start state.
3. A start state could also be an accept state.

### Input Format

1. States are numbered from 0 to K-1, where K is total number of states in DFA.
2. You are given three arrays zeroEdges, oneEdges, accepting and two integers start and N.
3. Array `zeroEdges` denotes a 0 edge from state numbered i to state A[i], for all 0 ≤ i ≤ K-1
4. Array `oneEdges` denotes a 1 edge from state numbered i to state B[i], for all 0 ≤ i ≤ K-1
5. Array `accepting` contains indices of all accept states.
6. Integer `start` denotes the start state.
7. Integer `N` denotes you have to count how many distinct strings of length N the given DFA accepts.

### Example

```
For the DFA shown in image, input is
zeroEdges = [0, 2, 1]
oneEdges = [1, 0, 2]
accepting = [0]
start = 0

Input 1
-------
N = 2
Strings '00' and '11' are only strings on length 2 which are accepted. So, answer is 2.

Input 2
-------
N = 1
String '0' is the only string. Answer is 1.
```