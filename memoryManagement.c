#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void check_allo(void *pAdd)
{
    if(pAdd == NULL) 
        printf("Allocate memory FAILED!\n ");
    else
        printf("Allocate address: %p\n", pAdd);
    return;
}

int main()
{
    // allocate 100 char with initialized by 0
    char *pTitle = calloc(100, sizeof(char));  
    check_allo(pTitle);
    int a;
    strncpy(pTitle, "abcd1234567890efgh", strlen("abcd1234567890efgh"));

    printf("Title content: %s\n", pTitle);
    printf("Title intialized by: %d\n", pTitle[99]);

    
    // allocate 20 char without initialized
    char *pArrayChar = malloc(20);
    check_allo(pArrayChar);
    pArrayChar[19] = 0;  // end of a string
    printf("Title content (random): %s\n", pArrayChar);   // random value

    // realloc set old allocated memory to new pointer
    pArrayChar = realloc(pArrayChar, 100);
    memset(pArrayChar, 0, 100);  // initialized by user  
                                 // memory functions: memcpy,memcmp,memset,memmove
    printf("Length of pTitles: %d\n", strlen(pTitle));
    strncpy(pArrayChar, pTitle, strlen(pTitle));
    printf("Title content: %s\n", pArrayChar);   // new value


    // Never forget free memory you allocated!!! or causing waste of memory!
    free(pTitle);
    free(pArrayChar);
    return 0;
}






    
















