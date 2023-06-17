/*
Author: Adrian deCola
Leetcode link: https://leetcode.com/problems/roman-to-integer
*/



int romanToInt(char * s){
    //interating through the list
    int i = 0;
    int sum = 0;
    while (s[i] != '\0'){
        // catching the special ones
        if (s[i] == 'I' && s[i+1] == 'V'){
            sum += 4;
            i++;
        }
        else if (s[i] == 'I' && s[i+1] == 'X'){
            sum += 9;
            i++;
        }
        else if (s[i] == 'X' && s[i+1] == 'L'){
            sum += 40;
            i++;
        }
        else if (s[i] == 'X' && s[i+1] == 'C'){
            sum += 90;
            i++;
        }
        else if (s[i] == 'C' && s[i+1] == 'D'){
            sum += 400;
            i++;
        }
        else if (s[i] == 'C' && s[i+1] == 'M'){
            printf("here\n");
            sum += 900;
            i++;
        }
        // the rest
        else if (s[i] == 'I'){
            sum += 1;
        }
        else if (s[i] == 'V'){
            sum += 5;
        }
        else if (s[i] == 'X'){
            sum += 10;
        }
        else if (s[i] == 'L'){
            sum += 50;
        }
        else if (s[i] == 'C'){
            sum += 100;
        }
        else if (s[i] == 'D'){
            sum += 500;
        }
        else if (s[i] == 'M'){
            sum += 1000;
        }   
        i++;
    }
    return sum;
}