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

###1005 - Rooks
Not yet solved 

###1006 - Hex-a-bonacci
This question is quite simple and straight forward as compared to the previous questions. All you need to dos is to replace the recursion with a for loop. Also make sure to take the modulo before storing the values in array as the values can be quite large

###1007 - Mathematically Hard
You should take exereme care while solving this problem. The input require very first IO method. Scanf and Printf would be the best choice if you are using C++. You can need to use a modified version of the Sieve method for cracking the problem. The approach I used was to first store the prime numbers using the sieve method and then to use a sieve like method to calculate `phi of n`. Take extra care to use `llu` while printing out the answer as the output is in the range of unsigned long long.

###1008 - Fibsieve`s Fantabulous Birthday 
Try to find the pattern in which the numbers are appearing. If you look carefully you can obtain the pattern and device an formula to find the coordinates. 

###1009 - Back to Underworld
I didn't use any normal graph algorithm for solving this problem. Even tough the problem uses a little concept of connected componenents. Try approaching the problem by considering the rivals as nodes in a graph. Check the code if you are stuck for a long time
