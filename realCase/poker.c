// show a hand's (7 cards) strength
#include <stdio.h>
#include <string.h>

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
static char allCards[7][2]={0};  // set all cards together
static char oneCom[5][2] = {0};  // store one possible
static char b_sth[6] = {0};      // for back
static char t_sth[6] = {0};      // for temp
static char t_card[2] = {0};     // for switch 2 cards

// set 5 index number to control the generation of one possible
static unsigned short int n1 = 0;  // 0-2
static unsigned short int n2 = 1;  // 0-3
static unsigned short int n3 = 2;  // 0-4
static unsigned short int n4 = 3;  // 0-5
static unsigned short int n5 = 4;  // 0-6
// make a new status of the index
int re_set7_5()
{
    if(n5 < 6) 
    {
        n5++; 
        return 1;
    }
    if(n4 < 5) 
    {
        n4++;
        n5 = n4+1;
        return 1;
    }
    if(n3 < 4) 
    {
        n3++;
        n4 = n3+1;
        n5 = n4+1;
        return 1;
    }
    if(n2 < 3) 
    {
        n2++;
        n3 = n2+1;
        n4 = n3+1;
        n5 = n4+1;
        return 1;
    }
    if(n1 < 2) 
    {
        n1++;
        n2 = n1+1;
        n3 = n2+1;
        n4 = n3+1;
        n5 = n4+1;
        return 1;
    }

    return 0;  // represent the circulation is done
}

// order the five cards by descending
void order_ascending()
{
    int i=0, j=1;
    for(i=0; i<3; i++)
        for(j=i+1; j<4; j++)
            {
                if(oneCom[j][0] > oneCom[i][0])
                    {
                        memcpy(t_card, oneCom[i], 2);
                        memcpy(oneCom[i], oneCom[j], 2);
                        memcpy(oneCom[j], t_card, 2);
                    }
            }
    return;
}

// calculate the 5 cards' strength, if stronger than sth[6], then replace it.
void a_calc()
{
    // order the five cards by descending
    order_ascending();

    // now, how to judge the strength of this combine?



    return;
}


// input a hand and piblic cards, 7 cards totally, output the strength of this hand to sth[6].
void calutate_strength(char hand[2][2], char puCards[5][2], char sth[6])
{
    // copy all cards together
    memcpy(allCards[0], hand[0], 2*2);
    memcpy(allCards[2], puCards[0], 5*2);
    do{
        memcpy(oneCom[0], allCards[n1], 2);
        memcpy(oneCom[1], allCards[n2], 2);
        memcpy(oneCom[2], allCards[n3], 2);
        memcpy(oneCom[3], allCards[n4], 2);
        memcpy(oneCom[4], allCards[n5], 2);

    }while(re_set7_5());


    
    return;
}



















