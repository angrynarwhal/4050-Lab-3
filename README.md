# Lab 3 - Dynamic Programming

### Place all of your submission documents in the ./lab3_submission folder. You will submit a zip file of that directory in Canvas. 

## Overview

The lab will help strenghthen your grasp of dynamic programming, reinforcing the motifs of recurrence relations, memoization, and graph algorithms through some simple introductory examples; this is followed by a robust implementation of the shortest path algorithm on a graph and an interesting usecase of Dynamic Programming in the real world: Text Wrapping.

<!-- 
    1. Prelude to Dynamic Programming
    2. Introduction to Knuth-Pluss
    3. Shortest Path Review
    4. Graph interpretation
    5. KP-Implementation -->


## Part 1: Warming up with Fibonacci.
### Recursion

In class, we discussed the recursive method for calculating the nth Fibonacci number, often the first recursive program students encounter due to its simple yet elegant mathematical nature.

We start this lab by revisting the topic and taking a look at a working C code that implements this recursive function in `fibo.c`. **Note:** If you've never coded the recursive Fibonacci function before, it might be worthwhile to take a moment and try to implement it for yourself before opening the file. If you look up the definition of the Fibonacci sequence, the algorithm is easy to derive from it.

In `fibo.c` you'll find a main function, and two helper functions: 
- `fibo(n)`:  recursively calls itself to calculate the nth Fibonacci number.
- `fibo_counter(n, k)`: given integers $n$ and $k$, calculates the number of times `fibo(k)` would be called, also recursively.

Try to compile the file using gcc and run it. The file is initialized with $n=10$ and $k=5$. You may change these variables to test the exponential growth of the function as well as answer the questions below **(just a couple sentences should suffice, unless noted otherwise)**.

#### Exercise 1:
Try to modify the main function and add a loop to print the output `fibo_counter(n,k)` for $n=10$ and vary the value of k from 10 to 0. What do you notice about the output? What about the value for $k=1$? **Take a screenshot and attach it with your answer.**


#### Exercise 2: 
Try to guess what value of $n$ makes `fibo_counter(n, 2)` return a value over 1 million. What about 1 billion? As a hint, $n=18$ is when it passes $1000$. You may modify the main function to calculate these numbers and compare your guess with the actual answers. 

#### Exercise 3:
For $n = 30$, take a look at the output of `fibo_counter(n, k)` for $k \in \\{3,2,1,0\\}.$ What do you think of the output for $k=0$, compared to $k=1$ or $k=2$? Does it make sense given the trend? Why or why not?

### Recursion + Memoization

Recall the discussion around the recurrence relation of the fibonacci sequence from class. It derives exactly from the definition and is as follows:

$$ \text{F}_n = \text{F}_{n-1} + \text{F}_{n-2}.\ \ \text{F}_1 = \text{F}_2 = 1$$

This can be seen in the recursive implementation as well, but the key idea is that we can see that $F_{n-2}$ being computed more than once: once for $F_n$ and once for $F_{n-1}$. With this knowledge, and the power of Dynamic Programming, we can convert this exponential time algorithm into a linear time algorithm (or polynomial, depending how deep you want to go into the rabbit hole).

This is accomplished by memoization, essentially keeping a record so that redundant computations are avoided.

#### Exercise 4: 
In `fibo.c`, add a new function with the signature `long fibo_memo(int n);`. Implement the function and print out the results for $n \in \\{60, 75, 100\\}$. Attach a screenshot of the code output below.

## Part 2: Connection with Graph and networks.
In part 3, you will learn a little about text wrapping, which uses an implementation of the DAG shortest path algorithm using dynamic programming. Before we get there, however, lets turn our attention to another well known example of Dynamic Programming: the **Bellman-Ford** Algorithm.


#### Exercise 5:
Recall the Recurrence relation used for Bellman-Ford and implement the algorithm in the `BF.c` file provided. It comes with some of the boilerplate code as well as a short example graph for you to run the finalized algorithm on.

For reference, the *Algorithm Design 2nd edition* covers Bellman-Ford from page 290-297, including examples and a form of psuedocode.

#### Exercise 6:
The Bellman-Ford algorithm finds shortest path from vertex $s$ to vertex $v$. Lets say you're given $v_1$ and  $v_2$. Describe an algorithm to calculate the shortest path starting from $s$ and going to either $v_1$ or $v_2$, whichever is shorter, while going *through* the other vertex... i.e. $s \rightarrow v_1 \rightarrow v_2$ or $s \rightarrow v_2 \rightarrow v_1$.

## Part 3: Text Wrapping. 

The final part of this lab is designed as a simplified walk through of the Knuth-Plass paper from 1981 called *Breaking Paragraphs into Lines.* It discusses the line breaking algorithm as it was implemented in Tex, and explains how a problem that initially seems very simple requires a very nuanced solution.

You may find the original paper [here](https://gwern.net/doc/design/typography/tex/1981-knuth.pdf), though I will attempt to exaplain most of relevant parts in order to implement the simplified version below.


We will study line breaking with the goal of *justification*, a fancy typesetting word that simply states how the words are printed and associated with the margins. Figure 1 shows a side-by-side of left justified (Aligned Left) and justified text. Notice that in left-justified, the right side has jagged edges, but the words are all evenly spaced out; whereas in the justified side, there are no jagged edges on the right side, but this is accomplished by using variable length spaces between words (i.e. line 1 and 2). 

We will use this interplay between space sizes and word widths in order to study and efficiently solve this problem. 

#### Figure 1:
![Image shows left justified vs justified text](/images/image.png)



### Required Reading 

TODO: Finish this section

To simplify the problem, the concept of a paragraph, words and spaces have been presented in a slightly more mathematical fashion. A paragraph *P* may be represented as a string of *items* $(x_1, x_2,\dots x_n).$ In such a representation, each $x_i$ may be a ***box*** specification, a ***glue*** specification, or a ***penalty*** specification.

- A box is categorized as a black box with some content inside of it, be it a character, a symbol, a mathematical formula. We do not care to see what's inside it, just that it has a specific width that cannot change. A box $x_i$ will have a fixed width $w_i$. For KP, a box could contain anything from characters to words, but for the purposes of our lab it will be defined as any word in the english language.

- A Glue refers to whitespaces of variable length :TODO: finish explaination

- A penalty refers to a marker of how good or bad a decision it will be if a line break is inserted after that spot. this is not printed and is solely inserted for convenience of the algorithm.

We will also look at the so called "badness score" which details how good or bad a breakpoint is in conjunction with the penalty score. 

#### Exercise 7
Part one of the algorithm involves a polynomial algorithm that iterates through the paragraph and creates our list of items $(x_1, x_2,\dots, x_n)$ along with all the necessary *badness scores* and legal breakpoints.

TODO: Provide more implementation guidance here. 

Use the provided c file which contains much of the boiler plate code to complete this part of the lab according to specification.

#### Exercise 8

TODO: May remove this part if it feels too long.

Now that you have your paragraph in the proper format, you should be able to convert it into a graph so that the Bellman-Ford algorithm from Part 2 can do its job. It should find the shortest path and output it, which will represent the starting node (the first word), and then every consecutive node represents the optimum line break, minimizing the badness of each line. This shortest path can then be used to finally typeset and print the paragraph.


#### Exercise 9

We've solved the problem using BF algorithm, but have we done it as efficiently as possible? We've used dynamic programming so it must be the case right? 

In actuallity, the Bellman-Ford algorithm is too strong of a hammer to use on this problem, which is actually a DAG (Directed Acyclic Graph) Shortest-Path problem. Bellman-Ford will run in $O(n^2)$ time. Given that its a DAG, we might consider using Dijkstra, which may run in $O(E+V\text{log}(V))$. However, using dynamic programming, this can be solved in linear time, which is the final part of this lab.

Use the given boilerplate code as a starting point and implement the `knuth_plass-sp` function using dynamic programming. Print out the graph using the given function and attach a screenshot below. 


## Conclusion

That concludes the lab. 

Some questions here. Food for thought.

- In your own words, why is Bellman-Ford not the best algorithm to use for this case-study and what allows the Knuth-Plass algorithm to be more efficient?

- Instead of the shortest path, what would it look like if you wrote the algorithm to use the longest path instead? What about the left most path every time (imagining the graph as a top-down tree)?

- What about greedy algorithms? Why did we not consider them? What would a greedy algorithm for this problem look like? What scenario of text-wrapping (as opposed to Tex) would greedy algorithms be more suited for?