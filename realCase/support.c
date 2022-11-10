#include <stdio.h>

// In this file, store support fanctions for the main programme

// show n players' hands to the screen
void show_hands(char (*pArr)[2][2], int n)
{
    // pArr[n][2][2], n=number of players
    for(int i = 0; i < n; i++)
    {
        printf("player %d's first card: %d%d, second card: %d%d\n", 
                i, pArr[0][0][0], pArr[0][0][1],pArr[0][1][0],pArr[0][1][1]);
    }

    return;
}

// check if the memory allocate success
void check_allo(void *pAdd)
{
    if(pAdd == NULL) 
        printf("Allocate memory FAILED!\n ");
    else
        printf("Allocate address: %p\n", pAdd);
    return;
}

// read hands from hands.txt to a heal memory, return hands number copyed.
unsigned int read_hands(char *pHeal, char *pStrFile)
{
    unsigned int n = 0;


    printf("Hands read success: %d", n);
    return n;
}






















