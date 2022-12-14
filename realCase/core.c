// to caculate the rate of winning for each hand
#include <stdio.h>
#include <string.h>
extern void show_hands(char (*pArr)[][2], int n);
extern void calutate_strength(char hand[2][2], char puCards[5][2], char sth[6]);
extern int compare(char sth1[6], char sth2[6]);

// declare a array to represent all 52 poker cards
static char cards[52][2] = 
    {{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0},{10,0},{11,0},{12,0},{13,0},{14,0},
     {2,1},{3,1},{4,1},{5,1},{6,1},{7,1},{8,1},{9,1},{10,1},{11,1},{12,1},{13,1},{14,1},
     {2,2},{3,2},{4,2},{5,2},{6,2},{7,2},{8,2},{9,2},{10,2},{11,2},{12,2},{13,2},{14,2},
     {2,3},{3,3},{4,3},{5,3},{6,3},{7,3},{8,3},{9,3},{10,3},{11,3},{12,3},{13,3},{14,3}};
static char re_cards[48][2] = {0};
static char public[5][2] = {0};
static char sth1[6] = {0};  // So if we have more players than 2, we should rewrite this code. Not diffcult.
static char sth2[6] = {0};

// generate a array cards witch store the cards havn't dealed. (48cards)
void gen_re_cards(char dealed[2][2][2])
{
    int m = 0;  // represent how many cards got (must be 48)
    for(int n=0; n<52; n++)
    {
        if(memcmp(cards[n], dealed[0][0], 2) == 0) continue;
        if(memcmp(cards[n], dealed[0][1], 2) == 0) continue;
        if(memcmp(cards[n], dealed[1][0], 2) == 0) continue;
        if(memcmp(cards[n], dealed[1][1], 2) == 0) continue;
        memcpy(re_cards[m], cards[n], 2);
        m++;
    }
    // printf("Total cards remain(mustbe 48): %d\n", m);
    return;
}

// set 5 index number to control the generation of public cards
static unsigned short int n1 = 0;  // 0-43
static unsigned short int n2 = 1;  // 0-44
static unsigned short int n3 = 2;  // 0-45
static unsigned short int n4 = 3;  // 0-46
static unsigned short int n5 = 4;  // 0-47
// make a new status of the index
int re_set()  // seems we can use 48,5 as a parameter to make this function more commonly useful
{
    if(n5 < 47) 
    {
        n5++; 
        return 1;
    }
    if(n4 < 46) 
    {
        n4++;
        n5 = n4+1;
        return 1;
    }
    if(n3 < 45) 
    {
        n3++;
        n4 = n3+1;
        n5 = n4+1;
        return 1;
    }
    if(n2 < 44) 
    {
        n2++;
        n3 = n2+1;
        n4 = n3+1;
        n5 = n4+1;
        return 1;
    }
    if(n1 < 43) 
    {
        n1++;
        n2 = n1+1;
        n3 = n2+1;
        n4 = n3+1;
        n5 = n4+1;
        return 1;
    }

    return 0;  // represent the circulation of public cards is done
}


// create a circluar, in each possiblity of public cards which hand will win
void calculate_rate(char aHand[2][2][2])
{
    // printf("This beginning of calculating rate...\n");
    show_hands(aHand, 2);
    // generate a array cards witch store the cards havn't dealed. (48cards)
    gen_re_cards(aHand);

    // generate 5 public cards by all possiblity, then pass them to a comparation function to get a winner
    unsigned int times = 0;
    float win1 = 0, win2 = 0;  // store the 2 players winning time, +0.5 if draw
    int one_result;            // one round 1 represent player 1 win, -1 loss, 0 draw
    n1 = 0; n2 = 1; n3 = 2; n4 = 3; n5 = 4;  // MUST reset them, because they are static in the memory!!!
    do{
        memcpy(public[0], re_cards[n1], 2);
        memcpy(public[1], re_cards[n2], 2);
        memcpy(public[2], re_cards[n3], 2);
        memcpy(public[3], re_cards[n4], 2);
        memcpy(public[4], re_cards[n5], 2);
        times++;
        // get the strength of these two hands
        calutate_strength(aHand[0], public, sth1);
        calutate_strength(aHand[1], public, sth2);

        // compare the strength of these two hands
        one_result = compare(sth1, sth2);
        if(one_result == 1)
            win1 += 1;
        else if (one_result == -1)
        {
            win2 += 1;
        }
        else{
            win1 += 0.5;
            win2 += 0.5;
        }
        
    }while(re_set());

    // printf("n1=%d, n2=%d, n3=%d, n4=%d, n5=%d\n", n1, n2, n3, n4, n5);
    // printf("Last public cards: %d%d, %d%d, %d%d, %d%d, %d%d\n", public[0][0], public[0][1], public[1][0], 
    //         public[1][1], public[2][0], public[2][1], public[3][0], public[3][1], public[4][0], public[4][1]);
    // printf("Strength of last hand1: %d%d%d%d%d%d\n", sth1[0],sth1[1],sth1[2],sth1[3],sth1[4],sth1[5]);
    // printf("Strength of last hand2: %d%d%d%d%d%d\n", sth2[0],sth2[1],sth2[2],sth2[3],sth2[4],sth2[5]);
    // printf("Total times: %d\n", times);
    // calculate the rate
    win1 = win1/times;
    win2 = win2/times;
    printf("Player1 win rate: %.4f\n", win1);
    printf("Player2 win rate: %.4f\n", win2);
    printf("----------------------------------------\n");
    return;
}



















