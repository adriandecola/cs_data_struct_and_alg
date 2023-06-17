Here is the result working on the given lists in main:

-bash-4.2$ ./insertion 
0 1 2 3 4 5 6 7 8 9 10 
0 1 2 3 4 5 6 7 8 9 10 
0 1 2 3 4 5 6 7 8 9 10 
1 1 1 1 1 1 1 1 1 1 2 
-9 24 52 55 75 100 150 201 623 3223 8523 
-9 -6 -3 -1 1 2 4 5 7 8 10 



Here is the result of the amount of time it took to sort different size lists from size 10 to 1,000,000:


List Size   |  Time to sort (seconds)
-------------------------------------
10          |  0.000003
-------------------------------------
100         |  0.000068
-------------------------------------
1000        |  0.006080
-------------------------------------
10000       |  0.241876
-------------------------------------
100000      |  18.905789
-------------------------------------
1000000     |  1871.005714
-------------------------------------








-bash-4.2$ ./insertion 10
Total time = 0.000003 seconds

-bash-4.2$ ./insertion 100
Total time = 0.000068 seconds

-bash-4.2$ ./insertion 1000
Total time = 0.006080 seconds 

-bash-4.2$ ./insertion 10000
Total time = 0.241876 seconds

-bash-4.2$ ./insertion 100000
Total time = 18.905789 seconds

-bash-4.2$ ./insertion 1000000
Total time = 1871.005714 seconds
