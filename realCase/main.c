#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// There are two poker players. Caculate the rate of winning when they allin preflop.
extern void show_hands(char (*pArr)[][2], int n);
extern void check_allo(void *pAdd);
extern unsigned int read_hands(char *pHeal, char *pStrFile);

int main(){

    // set two players' hands
    char p[2][2][2] = {0};
    show_hands(p, 2);  // 2 means the number of players
    
    // use 2-13 present 2-9-T-J-Q-K, 14 present A, 0:club, 1:diamond, 2:heart, 3:spade
    // use hands.txt store witch hands we are interesting about. format as: A0A1|92T3  one line one hands

    // use heal memory to store the hands from the file
    char *pHands = calloc(1000, sizeof(char)*8);    // so the max hands number will be 1000
    check_allo(pHands);

    // read the hands to the heal memory just allocated
    int nHands = read_hands(pHands, "hands.txt");

    // reallocate the heal to save omit the idel space
    pHands = realloc(pHands, sizeof(char)*8*nHands);

    // check the hands in the heap
    char (*paHands)[2][2][2] = (void *)pHands;
    for(int i = 0; i < nHands; i++)
    {
        printf("The %dst hand:\n", i);
        show_hands(paHands[0], 2);
        // the core business function



        paHands++;
    }

    
    



    free(pHands);
    return 0;

}

















