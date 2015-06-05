#Solutions For Light OJ

Use the hints for solving the problem. See the solutions only in worst case situations. 

###1002 - Country Roads
You need to use a modification of Dijkstra's algorithm for solving thr peorblem. They key catch is in Dijkstra we use 

`a[i][j] + d[i] < d[j]`
`d[j] = a[i][j] + d[i]`

While here we should use

`max(a[i][j], d[i]) < d[j]`
`d[j] = max(a[i][j], d[i])`

###1003 - Drunk
The task is to check whether cycle exists in the directed graph. If cycle exists he can't drink all. You can use a hash function or map to convert the drinks to numbers. Once converted use DFS or a suitable algo for checking the existance of cycles. I used `DFS` for the search of cycles. 

###1004 - Monkey Banana Problem
This is a basic Dynamic Programming problem. The tricky part is to write the loops. While calculating the maximum bananas the second inner loop will run forward till i < n and for the remaining it would run backward. Check the solution for understanding the logic behind this. 

###1006 - Hex-a-bonacci
This question is quite simple and straight forward as compared to the previous questions. All you need to dos is to replace the recursion with a for loop. Also make sure to take the modulo before storing the values in array as the values can be quite large

###1007 - Mathematically Hard
You should take exereme care while solving this problem. The input require very first IO method. Scanf and Printf would be the best choice if you are using C++. You can need to use a modified version of the Sieve method for cracking the problem. The approach I used was to first store the prime numbers using the sieve method and then to use a sieve like method to calculate `phi of n`. Take extra care to use `llu` while printing out the answer as the output is in the range of unsigned long long.

###1008 - Fibsieve`s Fantabulous Birthday 
Try to find the pattern in which the numbers are appearing. If you look carefully you can obtain the pattern and device an formula to find the coordinates. 

###1009 - Back to Underworld
I didn't use any normal graph algorithm for solving this problem. Even tough the problem uses a little concept of connected componenents. Try approaching the problem by considering the rivals as nodes in a graph. Check the code if you are stuck for a long time

###1011 - Marriage Ceremonies 
This is a normal Memoization with Bit masking type problem. Normal recursion without memoization causes a TLE. 

###1012 - Guilty Prince
This is one is a really simple graph problem. Keep marking the visited nodes to avoid visiting them again

###1014 - Ifter Party
This is also a normal Ad-Hoc problem. The simplified task is to find the divisors of p - l which are greater than l.

###1016 - Brush II
This is yet another adhoc problem. What you need to do is to ietrate over all the y points in ascending order in such a way that you increase the counter only when the difference of ym, ym+1, ....yn becomes greater than w. The counter would give you the answer. 

###1019 - Brush IV
This is a trivial application of Shortest Path algorithms. Implementing Floyd Warshal solution for this can accept the solution in a few lines of code

###1020 - A Childhood game
This is a problem under Game theory. You can write the solution for this problem by just observing the pattern of win or loss. If Alice is taking the stone first she will get a win for 0, 2, 3, 5 .... and loss for 1, 4, 7 .... You can easily use this observation for solving the problem. 

###1022 - Circle in Square
The only tricky part in this question is to use double for all the calculations. Always use double instead of float in programming contests. 

###1023 - Discovering Permutations
This is a pretty simple questions. You can use the C++ `next_permutation` for cracking this problem in a few lines of code

###1025 - The Specials Menu
This is a dp problem

###1027 - A Dangerous Maze 
The below example have been taken from the forum

Let's consider test case #3:

3
3 -6 -9


There are 3 doors, and we are to find the expected amount of time it will take to get out of the maze. Let's call that expected value E. Now, E has to be equal to the average of the times that it takes to get out from each door, correct? Let's say T1 is the amount of time to get out of the maze when taking door #1, and T2 and T3 are defined similarly. Then:

`E = (T1 + T2 + T3) / 3`


It's easy to see that T1 is 3, but what about T2 and T3? You can think about it like this: if you take door number 2, you will spend 6 minutes going through the maze, and you end up at the starting point, and from there, how much time will it take you to get out? Well, E is the expected time it will take you to get out from the start, right? So, you can say:

`T2 = 6 + E
T3 = 9 + E`


Putting all that together, the original equation becomes:

`E = 3/3 + (6/3 + E/3) + (9/3 + E/3`
`E = 6 + 2E/3`
`E/3 = 6`
`E = 18`

Now convert the logic into simple code


###1028 - Trailing Zeroes (I) 
If a number can be expressed as p1 ^ c1 * p2 ^ c2 * ..... pn ^ cn where p1 .. pn are the prime factors and c1 ... cn are the powers of the factors, then the total number of divisors of the number is given by 

`n = (c1 + 1) * (c2 + 1) * ... * (cn + 1)`

Check the code carefully for the implementation

###1029 - Civil and Evil Engineer 
This is a simple application of minimum spanning trees. Use a priority queue for reducing the time complexity.

###1033 - Generating Palindromes
Find the LCS of the given string and the reverse string. Then subtract the LCS from the actual length of the string. Find LCS using DP.  

###1034 - Hit the Light Switches
Use Kosaraju’s algorithm for finding the connected componenets of the directed Graph. In Kosaraju’s algorithm we perform the second DFS in the transpose graph. Skipping the creation of transpose graph result in the generation of cconnected componenents instead of the `SCC` which is exactly we want

###1035 - Intelligent Factorial Factorization
I don't think you would need any hint for soloving this question. Don't try to generate factorial to solve this question. 

###1037 - Agent 47
This can be solved using bit masking. Write a recurise solution and save the states. 

###1040 - Donation
Use Prims MST algorithm accordingly for solving this problem. 

###1041 - Road Construction
First you need to find the connected components of the graph. Then you need apply PRIMS MST in the connected components to find the minimum cost. 

###1042 - Secret Origins
This is an adhoc problem. Don't bruteforce. See how the bits changes from input to output answer. 

###1044 - Paliandrome Partitioning
This is a DP problem. you need to solve 2 seperate tasks for solving the problem. First task is to precompute the indexes of all the palidrome substrings. The second task is to solve the problem using the pre computed value with (1) lookup time. 


###1045 - Digits Of A  Factorial
You can find the number of digits required ny taking log of the factorial. This is equalent to 
`log(N!) = log(1) + log(2) + .... + log(N)`
Precompute and store the values to avoid doing repetetive tasks. 


###1046 - Rider
Use BFS for solving this problem. You need to find the shortest distance from each rider to all the cells in the chess board using BFS. Then use a simple loop for choosing the best cell. 

###1047 - Neighbour House
Normal DP problem. Try solving it yourself. 


###1049 - One Way Roads
This is a normal ad hoc problem. You can solve this by trying the two possible way of road arrangements, one being mere the compliment of the other. 

###1051 - Good Or Bad
DP problem. I solved it by using memoization and considering only characters of the string from the point you are evaulating to save the state for memoization. I used only 5 characters because they only decide the outcome of the that point. 

###1053 - Higher Math
If the triangle is right angle `a * a + b * b == c * c`

###1093 - Ghakjini
Use two priority queues. One for tracking maximum element in memeory and one for tracking minimum element. 

###1094 - Farthest Node In Tree
Do to DFS. First one would return one node. The seond one from that node will get return you the other
