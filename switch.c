#include <stdio.h>
// This is a C example for beginners.

int main(){

    int i = 3;

    switch (i)
    {
    case 1:  // only constant integer valid
        printf("It is 1\n");
        break;  // break in important!!!
    case 2:
        printf("It is 2\n");
        break;
    case 3:
        printf("It is 3\n");
        break;
    case 4:
        printf("It is 4\n");
        break;
    case 5:
        printf("It is 5\n");
        break;
    default:
        printf("It is a number other than 1-5\n");
        break;
    }

    return 0;

}