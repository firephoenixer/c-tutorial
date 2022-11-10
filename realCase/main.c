#include <stdio.h>
// There are two poker players. Caculate the rate of winning when they allin preflop.
extern void show_hands(char (*pArr)[][2], int n);

int main(){

    // set two players' hands
    char p[2][2][2] = {0};
    show_hands(p, 2);  // 2 means the number of players
    
    // use 2-13 present 2-9-T-J-Q-K, 14 present A, 0:club, 1:diamond, 2:heart, 3:spade
    // use hands.txt store witch hands we are interesting about. format as: A0A1|92T3  one line one hands







    return 0;

}

















