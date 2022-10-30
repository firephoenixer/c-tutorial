// This is example for users to understand loop and judgement in C
#include <stdio.h>
#include <stdbool.h>
const int aNum = 77;  // This a int number for user to guess, const declare it can't be changed later.


int main()
{
    int times = 0;  // This variable record how many time user have guessed.
    int userNum;
    bool onRunning = true;
    while(onRunning)  
    {
        times++;
        printf("Please enter a int number (0-99) to guess:\n");
        scanf("%d", &userNum);  // Value range 0-99: 

        if(userNum > aNum)
        {
            printf("Higher, try again...\n");
        }
        else if (userNum < aNum)
        {
            printf("Lower, try again...\n");
        }
        else
        {
            printf("Congra!!!\n");
            onRunning = false;
        }       
    }

    printf("You have guessed %d times.", times);

    return 0;
}














