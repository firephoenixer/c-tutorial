#include <stdio.h>
#include <stdlib.h>

// Before using, functions are needly declared.
int g_sum(int, int);
// gcc .\functions.c .\globalFunctions.c  
// Notice: You must compile the associated file too, or you will lost the definity of the function!!!

int main(){

    printf("sum of 3+4=%d\n", g_sum(3,4));
    return 0;

}

















