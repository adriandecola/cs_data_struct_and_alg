Here is the result working on the given lists in main:

-bash-4.2$ ./mergesort 
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
100         |  0.000037
-------------------------------------
1000        |  0.000401
-------------------------------------
10000       |  0.004518
-------------------------------------
100000      |  0.050778
-------------------------------------
1000000     |  0.246495
-------------------------------------






-bash-4.2$ ./mergesort 10
Total time = 0.000003 seconds

-bash-4.2$ ./mergesort 100
Total time = 0.000037 seconds

-bash-4.2$ ./mergesort 1000
Total time = 0.000401 seconds

-bash-4.2$ ./mergesort 10000
Total time = 0.004518 seconds

-bash-4.2$ ./mergesort 100000
Total time = 0.050778 seconds

-bash-4.2$ ./mergesort 1000000
Total time = 0.246495 seconds

