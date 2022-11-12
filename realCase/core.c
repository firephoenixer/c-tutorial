// to caculate the rate of winning for each hand
#include <stdio.h>
extern void show_hands(char (*pArr)[][2], int n);


// create a circluar, in each possiblity of public cards which hand will win
void calculate_rate(char aHand[2][2][2])
{
    printf("This beginning of calculating rate...\n");
    show_hands(aHand, 2);


    printf("This end of calculating rate...\n");
    return;
}



















