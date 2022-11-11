// show a hand's (7 cards) strength
#include <stdio.h>

/* Strength of a hand, sth[6] dicate it
sth[0] = 8, flush straight   sth[1] High card
sth[0] = 7, four of a kind   sth[1] the kind,        sth[2] the kicker
sth[0] = 6, full horse       sth[1] the kind of 3,   sth[2] the kind of 2 
sth[0] = 5, flush            sth[1] sth[2] sth[3] sth[4] sth[5] High card to low
sth[0] = 4, straight         sth[1] High card
sth[0] = 3, three of a kind  sth[1] the kind,        sth[2] sth[3] the high kicker to low
sth[0] = 2, two pairs        sth[1] sth[2] the high pair to low, sth[3] the kicker
sth[0] = 1, one pairs        sth[1] the pair, sth[2] sth[3] sth[4] High kicker to low
sth[0] = 0, High card        sth[1] sth[2] sth[3] sth[4] sth[5] High card to low
*/



// input a hand and piblic cards, 7 cards totally, output the strength of this hand.
char *calutate_strength(char hand[2][2], char puCards[5][2])
{
    char sth[7][5] = {0};


    
    return sth;
}



















