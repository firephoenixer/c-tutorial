#include <stdio.h>
// There are two poker players. Caculate the rate of winning when they allin preflop.
extern void show_hands(char (*pArr)[][2], int n);

int main(){

    // set two players' hands
    char p[2][2][2] = {0};
    show_hands(p, 2);
    
    return 0;

}

















