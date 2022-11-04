#include <stdio.h>
// How use array
#define MAXCARDS 52  // This micro number show max number of cards in a poker

int main(){
    int arList[5] = {0,1,2,3,4};
    for(int i = 0; i < 5; i++) printf("%d ", arList[i]);
    printf("\n");

    char arChar[5] = {'a', 'b', 'c', 'd', 'e'};
    for(int i = 0; i < 5; i++) printf("%d ", arChar[i]);
    printf("\n");
    for(int i = 0; i < 5; i++) printf("%c ", arChar[i]);
    printf("\n");

    int ar2dInteger[3][3] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    for(int m = 0; m < 3; m++)
    {
        for (int n = 0; n< 3; n++)
        {
            printf("%d ", ar2dInteger[m][n]);
        }
    }
    printf("\n");

    // 2 different way to diclare a poker
    char arPoker[MAXCARDS] = {0};
    for(int i=0;i<MAXCARDS;i++) arPoker[i] = i;
    for(int i=0;i<MAXCARDS;i++) printf("%d ", arPoker[i]);
    printf("\n");

    char ar2dPoker[4][13] = {{2,3,4,5,6,7,8,9,10,11,12,13,14},
                             {2,3,4,5,6,7,8,9,10,11,12,13,14},
                             {2,3,4,5,6,7,8,9,10,11,12,13,14},
                             {2,3,4,5,6,7,8,9,10,11,12,13,14}};
    for(int i=0; i<4; i++){
        for(int n=0; n<13; n++)
        {
            printf("%d ", ar2dPoker[i][n]);
        }
        printf("\n");
    }

    // difine a array when running
    int n;
    printf("Please enter a number to define a array: \n");
    scanf("%d", &n);
    int arRunning[n];
    printf("Please enter the numbers to the array: \n");
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &arRunning[i]);
    }
    for(int i=0;i<n;i++) printf("%d ", arRunning[i]);
    printf("\n");


    return 0;

}
















