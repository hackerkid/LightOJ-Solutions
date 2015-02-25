#Solutions For Light OJ

##Use the hints for solving the problem. See the solutions only in worst case situations. 

###1002 
You need to use a modification of Dijkstra's algorithm for solving thr peorblem. They key catch is in Dijkstra we use 

`a[i][j] + d[i] < d[j]`
`d[j] = a[i][j] + d[i]`

While here we should use

`max(a[i][j], d[i]) < d[j]`
`d[j] = max(a[i][j], d[i])`

###1003
The task is to check whether cycle exists in the directed graph. If cycle exists he can't drink all. You can use a hash function or map to convert the drinks to numbers. Once converted use DFS or a suitable algo for checking the existance of cycles. I used `DFS` for the search of cycles. 

###1004
This is a basic Dynamic Programming problem. The tricky part is to write the loops. While calculating the maximum bananas the second inner loop will run forward till i < n and for the remaining it would run backward. Check the solution for understanding the logic behind this. 

###1005
Not yet solved 

###1006
This question is quite simple and straight forward as compared to the previous questions. All you need to dos is to replace the recursion with a for loop. Also make sure to take the modulo before storing the values in array as the values can be quite large

