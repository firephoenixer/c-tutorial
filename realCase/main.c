#include <stdio.h>
// There are two poker players. Caculate the rate of winning when they allin preflop.

int main(){

    // set two players' hands
    char p[2][2][2] = {0};
    
    //*** move this code to an indepence support file 11-09
    printf("player 1's first card: %d%d, second card: %d%d\n", p[0][0][0], p[0][0][1],p[0][1][0],p[0][1][1]);
    printf("player 2's first card: %d%d, second card: %d%d\n", p[1][0][0], p[1][0][1],p[1][1][0],p[1][1][1]);
    return 0;

}

















