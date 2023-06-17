# Lab 07 -- Cycle Estimation

- Name: Adrian deCola

- Title: Lab 7

- How many hours did it take you to complete this assignment? 
	
	It took me about 5 hours to complete the assignment.

- Did you collaborate with any other students/TAs/Professors? If so, tell 
  us who and in what capacity.
  - Professor Mwaura - Helped me understand the addembly in barebones.s
  
- Did you use any external resources? (Cite them below)
  - https://chromium.googlesource.com/chromiumos/docs/+/master/constants/syscalls.md
	-> Table for the syscall codes 
  - geeksforgeeks.com 
	-> For knowing how to use some libraries in C
  
- Use your tool to measure the  number of instructions that are require to 
  execute your implementation of the guessing game program that you 
  implemented in Homework 1 using two different levels of optimization:

  - When your program is compiled using the -O0 flag:

    ```
********************** SUMMARY OF INSTRUCTIONS *************************
ADD 5
SUB 4
MUL 1
MOV 44
LEA 4
PUSH 2
Total Instructions = 60
Total Cycles = 70

    ```

  - When your program is compiled using the -O3 flag:

    ```
********************** SUMMARY OF INSTRUCTIONS *************************
ADD 10
SUB 6
MUL 2
MOV 32
LEA 6
PUSH 7
POP 7
Total Instructions = 70
Total Cycles = 86
    ```

- (Optional) What was your favorite part of the assignment? 
  - My favorite part was testing the code on the the Homework 1
    executable(s).
  
- (Optional) How would you improve the assignment? 
  - I think I needed a bit more background on assembly. Also, a trusted
    resources for manipulating strings and using the string library would 
    have been nice. 

## Logistics

For this assignment (and every assignment/lab), you must login into the 
servers through `your_khoury_name@login.khoury.northeastern.edu` to complete 
and test your work. The reason is the examples I will provide below are 
compiled strictly for our machine's architecture, and this is a consistent 
architecture where your submission will be graded.

### Important notes

* Your code **must compile and run** on the Khoury machines to earn credit. 
  Make sure you test your programs on these machines, as this is where we 
  grade your assignments.
* You must commit any additional files (if any) into your repository so we 
  can test your code.
  * Points will be lost if you forget!
* Do not forget to push your changes in your private repo for grading before 
  the assignment deadline!**

