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
// static char b_sth[6] = {0};      // for back
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

// order the five cards by descending, seems dont use this function anymore
void order_descending()
{
    int i=0, j=1;
    for(i=0; i<=3; i++)
        for(j=i+1; j<=4; j++)
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

// descend the 7 cards in stead will be more fast
void order_des_all_cards()
{
    int i=0, j=1;
    for(i=0; i<=5; i++)
        for(j=i+1; j<=6; j++)
            {
                if(allCards[j][0] > allCards[i][0])
                    {
                        memcpy(t_card, allCards[i], 2);
                        memcpy(allCards[i], allCards[j], 2);
                        memcpy(allCards[j], t_card, 2);
                    }
            }
    return;
}


// calculate the 5 cards' strength, store in t_sth7[6]
void a_calc()
{
    // order the five cards by descending
    // order_descending();  // no necessary now, had done before 7_5 loop

    // now, how to judge the strength of this combine?
    if(oneCom[0][1]!=oneCom[1][1]||oneCom[0][1]!=oneCom[2][1]||oneCom[0][1]!=oneCom[3][1]||oneCom[0][1]!=oneCom[4][1])
    { // not the same color (M)
     if(oneCom[0][0]==oneCom[1][0]||oneCom[1][0]==oneCom[2][0]||oneCom[2][0]==oneCom[3][0]||oneCom[3][0]==oneCom[4][0])
     {// must have same card, (at least one pair)
       // four of a kind
       if(t_sth[0]>=7) return;
       if(oneCom[0][0]==oneCom[3][0]) {t_sth[0]=7; t_sth[1]=oneCom[3][0]; t_sth[2]=oneCom[4][0]; return;}
       if(oneCom[1][0]==oneCom[4][0]) {t_sth[0]=7; t_sth[1]=oneCom[4][0]; t_sth[2]=oneCom[0][0]; return;}
       // full horse 
       if(t_sth[0]>=6) return;
       if(oneCom[0][0]==oneCom[2][0]&&oneCom[3][0]==oneCom[4][0])
       {t_sth[0]=6; t_sth[1]=oneCom[2][0]; t_sth[2]=oneCom[4][0]; return;}
       if(oneCom[0][0]==oneCom[1][0]&&oneCom[2][0]==oneCom[4][0])
       {t_sth[0]=6; t_sth[1]=oneCom[4][0]; t_sth[2]=oneCom[0][0]; return;}
       // three of a kind
       if(t_sth[0]>=3) return;
       if(oneCom[0][0]==oneCom[2][0])
       {t_sth[0]=3; t_sth[1]=oneCom[2][0]; t_sth[2]=oneCom[3][0];  t_sth[3]=oneCom[4][0];return;}
       if(oneCom[1][0]==oneCom[3][0])
       {t_sth[0]=3; t_sth[1]=oneCom[3][0]; t_sth[2]=oneCom[0][0];  t_sth[3]=oneCom[4][0];return;}
       if(oneCom[2][0]==oneCom[4][0])
       {t_sth[0]=3; t_sth[1]=oneCom[4][0]; t_sth[2]=oneCom[0][0];  t_sth[3]=oneCom[1][0];return;}
       // two pairs
       if(t_sth[0]>=2) return;
       if(oneCom[0][0]==oneCom[1][0]&&oneCom[2][0]==oneCom[3][0])
       {t_sth[0]=2; t_sth[1]=oneCom[1][0]; t_sth[2]=oneCom[3][0];  t_sth[3]=oneCom[4][0];return;}
       if(oneCom[0][0]==oneCom[1][0]&&oneCom[3][0]==oneCom[4][0])
       {t_sth[0]=2; t_sth[1]=oneCom[1][0]; t_sth[2]=oneCom[4][0];  t_sth[3]=oneCom[2][0];return;}
       if(oneCom[1][0]==oneCom[2][0]&&oneCom[3][0]==oneCom[4][0])
       {t_sth[0]=2; t_sth[1]=oneCom[2][0]; t_sth[2]=oneCom[4][0];  t_sth[3]=oneCom[0][0];return;}
       // one pair
       if(t_sth[0]>=1) return;
       if(oneCom[0][0]==oneCom[1][0])
       {t_sth[0]=1; t_sth[1]=oneCom[1][0]; t_sth[2]=oneCom[2][0];  t_sth[3]=oneCom[3][0];t_sth[4]=oneCom[4][0];return;}
       if(oneCom[1][0]==oneCom[2][0])
       {t_sth[0]=1; t_sth[1]=oneCom[2][0]; t_sth[2]=oneCom[0][0];  t_sth[3]=oneCom[3][0];t_sth[4]=oneCom[4][0];return;}
       if(oneCom[2][0]==oneCom[3][0])
       {t_sth[0]=1; t_sth[1]=oneCom[3][0]; t_sth[2]=oneCom[0][0];  t_sth[3]=oneCom[1][0];t_sth[4]=oneCom[4][0];return;}
       if(oneCom[3][0]==oneCom[4][0])
       {t_sth[0]=1; t_sth[1]=oneCom[4][0]; t_sth[2]=oneCom[0][0];  t_sth[3]=oneCom[1][0];t_sth[4]=oneCom[2][0];return;}
     }
     else // do not have same card (M)
     {
      // straight
      if(t_sth[0]>4) return;  // mustn't use >= , ex: A765432, A5432 test before 76543
      if(oneCom[0][0]==14&&oneCom[1][0]==5) {t_sth[0]=4; t_sth[1]=oneCom[1][0]; return;}
      if(oneCom[0][0]-oneCom[4][0]==4) {t_sth[0]=4; t_sth[1]=oneCom[0][0]; return;}
      // all left are high card
      if(t_sth[1]>=2) return;  // this line should use index 1, because the initial value is 0
      t_sth[0]=0; t_sth[1]=oneCom[0][0]; t_sth[2]=oneCom[1][0]; t_sth[3]=oneCom[2][0]; 
      t_sth[4]=oneCom[3][0]; t_sth[5]=oneCom[4][0]; return;
     }
    }
    else  // all the same color
    {
     // straight flush
     if(t_sth[0]>8) return;  // mustn't use >= , ex: A765432, A5432 test before 76543
      if(oneCom[0][0]==14&&oneCom[1][0]==5) {t_sth[0]=8; t_sth[1]=oneCom[1][0]; return;}
      if(oneCom[0][0]-oneCom[4][0]==4) {t_sth[0]=8; t_sth[1]=oneCom[0][0]; return;}
      // flush
      if(t_sth[0]>=5) return;
      t_sth[0]=5; t_sth[1]=oneCom[0][0]; t_sth[2]=oneCom[1][0]; t_sth[3]=oneCom[2][0]; 
      t_sth[4]=oneCom[3][0]; t_sth[5]=oneCom[4][0]; return;
    }
    // error if execute here
    return;
}

// compare two hands, if hand1 is stronger retrun 1 , equeal 0, less -1
int compare(char sth1[6], char sth2[6])
{
    if(sth1[0]>sth2[0]) return 1;
    if(sth1[0]<sth2[0]) return -1;
    // to here, means they are in the same range
    switch (sth1[0])
    {
    case 8:  // flash straight
        if(sth1[1]>sth2[1]) return 1;
        if(sth1[1]<sth2[1]) return -1;
        break;  // break in important!!!
    case 7:  // four of a kind
        if(sth1[1]>sth2[1]) return 1;
        if(sth1[1]<sth2[1]) return -1;
        if(sth1[2]>sth2[2]) return 1;
        if(sth1[2]<sth2[2]) return -1;
        break;
    case 6:  // full horse
        if(sth1[1]>sth2[1]) return 1;
        if(sth1[1]<sth2[1]) return -1;
        if(sth1[2]>sth2[2]) return 1;
        if(sth1[2]<sth2[2]) return -1;
        break;
    case 5:  // flash
        if(sth1[1]>sth2[1]) return 1;
        if(sth1[1]<sth2[1]) return -1;
        if(sth1[2]>sth2[2]) return 1;
        if(sth1[2]<sth2[2]) return -1;
        if(sth1[3]>sth2[3]) return 1;
        if(sth1[3]<sth2[3]) return -1;
        if(sth1[4]>sth2[4]) return 1;
        if(sth1[4]<sth2[4]) return -1;
        if(sth1[5]>sth2[5]) return 1;
        if(sth1[5]<sth2[5]) return -1;
        break;
    case 4:  // straight
        if(sth1[1]>sth2[1]) return 1;
        if(sth1[1]<sth2[1]) return -1;
        break;
    case 3: // three of a kind
        if(sth1[1]>sth2[1]) return 1;
        if(sth1[1]<sth2[1]) return -1;
        if(sth1[2]>sth2[2]) return 1;
        if(sth1[2]<sth2[2]) return -1;
        if(sth1[3]>sth2[3]) return 1;
        if(sth1[3]<sth2[3]) return -1;
        break;
    case 2:  // two pairs
        if(sth1[1]>sth2[1]) return 1;
        if(sth1[1]<sth2[1]) return -1;
        if(sth1[2]>sth2[2]) return 1;
        if(sth1[2]<sth2[2]) return -1;
        if(sth1[3]>sth2[3]) return 1;
        if(sth1[3]<sth2[3]) return -1;
        break;
    case 1:  // one pair
        if(sth1[1]>sth2[1]) return 1;
        if(sth1[1]<sth2[1]) return -1;
        if(sth1[2]>sth2[2]) return 1;
        if(sth1[2]<sth2[2]) return -1;
        if(sth1[3]>sth2[3]) return 1;
        if(sth1[3]<sth2[3]) return -1;
        if(sth1[4]>sth2[4]) return 1;
        if(sth1[4]<sth2[4]) return -1;
        break;
    case 0:  // high card
        if(sth1[1]>sth2[1]) return 1;
        if(sth1[1]<sth2[1]) return -1;
        if(sth1[2]>sth2[2]) return 1;
        if(sth1[2]<sth2[2]) return -1;
        if(sth1[3]>sth2[3]) return 1;
        if(sth1[3]<sth2[3]) return -1;
        if(sth1[4]>sth2[4]) return 1;
        if(sth1[4]<sth2[4]) return -1;
        if(sth1[5]>sth2[5]) return 1;
        if(sth1[5]<sth2[5]) return -1;
        break;
    default:
        // printf("\n");
        break;
    }
    return 0;  // two hands are same
}


// input a hand and piblic cards, 7 cards totally, output the strength of this hand to sth[6].
void calutate_strength(char hand[2][2], char puCards[5][2], char sth[6])
{
    // // reset b_sth[6]
    // memset(b_sth, 0, 6);
    // // memset(t_sth, 0, 6);  // no necessary

    // try to make the strength store in sth[6] derectly , maybe could run faster
    // memset(sth, 0, 6);

    // set t_sth[6] as a temp, maybe more safe
    memset(t_sth, 0, 6);

    // copy all cards together
    memcpy(allCards[0], hand[0], 2*2);
    memcpy(allCards[2], puCards[0], 5*2);
    // printf("show hand: %d%d %d%d\n", allCards[0][0], allCards[0][1],allCards[1][0],allCards[1][1]);
    // printf("show public: %d%d %d%d\n", allCards[2][0], allCards[2][1],allCards[3][0],allCards[3][1]);
    // printf("show public: %d%d %d%d\n", allCards[4][0], allCards[4][1],allCards[5][0],allCards[5][1]);
    // printf("show public: %d%d \n", allCards[6][0], allCards[6][1]);

    // if we do descending 7 cards here, then we won't need do it in the next loop.
    order_des_all_cards();
    
    // do 7-5 calculation
    n1 = 0; n2 = 1; n3 = 2; n4 = 3; n5 = 4;  // MUST reset them, because they are static in the memory!!!
    do{
        // set one combine
        memcpy(oneCom[0], allCards[n1], 2);
        memcpy(oneCom[1], allCards[n2], 2);
        memcpy(oneCom[2], allCards[n3], 2);
        memcpy(oneCom[3], allCards[n4], 2);
        memcpy(oneCom[4], allCards[n5], 2);
        // calculate the strength and store them in t_sth
        a_calc();

        // compare to b_sth, if stronger replace it
        // if(compare(t_sth, b_sth) == 1)
        // {
        //     memcpy(b_sth, t_sth, 6);
        // }

    }while(re_set7_5());

    // set result t_sth[6] to sth[6]
    memcpy(sth, t_sth, 6);
    return;
}



















