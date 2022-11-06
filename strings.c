#include <stdio.h>
#include <string.h>
// This is a C example for strings.

int main(){
    // two way difine a string. String must end with a '\0'
    char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char *pString = "Hello world.";
    printf("Greeting message: %s\n", greeting );
    printf("Greeting message: %s\n", pString );
    printf("print e: %c\n", pString[1]);


    char sReceive[100] = {0};  // an empty 99 chars to load some strings
    strncpy(sReceive, greeting, sizeof(greeting));
    printf("sReceive message: %s\n", sReceive );
    strncpy(sReceive, pString, sizeof(pString));  // sizeof(pString), unexceted!
    printf("sReceive message sizeof(pString): %s\n", sReceive );
    strncpy(sReceive, pString, strlen(pString));  // well done.
    printf("sReceive message strlen(pString): %s\n", sReceive );

    // strncat(pString, greeting, sizeof(greeting));  // error, const string variable hasn't any room to cat str
    // printf("Catted message: %s\n", pString );

    strncat(sReceive, greeting, sizeof(greeting));
    printf("Catted message: %s\n", sReceive );

    // seams defined 2D array with different size.
    char *pMDstrings[] = {"frist blood.", "secondary blood.", "I don't like this kind of expression."};
    printf("%s\n", pMDstrings[0]);
    printf("%s\n", pMDstrings[1]);
    printf("%s\n", pMDstrings[2]);

    return 0;

}