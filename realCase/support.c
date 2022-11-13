#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>


// In this file, store support fanctions for the main programme

extern char convers_card(char a);


// show n players' hands to the screen
void show_hands(char (*pArr)[2][2], int n)
{
    // pArr[n][2][2], n=number of players
    for(int i = 0; i < n; i++)
    {
        printf("player %d's first card: %d%d, second card: %d%d\n", 
                i, pArr[i][0][0], pArr[i][0][1],pArr[i][1][0],pArr[i][1][1]);
    }

    return;
}

// check if the memory allocate success
void check_allo(void *pAdd)
{
    if(pAdd == NULL) 
        printf("Allocate memory FAILED!\n ");
    else
        printf("Allocate address: %p\n", pAdd);
    return;
}

// read hands from hands.txt to a heal memory, return hands number copyed.
unsigned int read_hands(char *pHeal, char *pStrFile)
{
    unsigned int n = 0;  // present how many hands readed
    FILE *fTxt;
    fTxt = fopen(pStrFile, "r");

    // check if opened success
    // int errnum;
    if (fTxt == NULL) {
      perror("Error printed by perror");
      return 0;
   }else{
      printf("File hands.txt address: %p\n", fTxt);
   }

    char buff[10] = {0};  // to store a hand temporily
    char tempHand[2][2][2] = {0};
    // get hands circually
    while(!feof(fTxt))
    {
        
        fgets(buff, 10, fTxt);  // seems stop when seen \n, inclued \n
        if(strlen(buff) == 9)
        {
            // mapping the text card to char card
            tempHand[0][0][0] = convers_card(buff[0]); tempHand[0][0][1] = convers_card(buff[1]);
            tempHand[0][1][0] = convers_card(buff[2]); tempHand[0][1][1] = convers_card(buff[3]);
            tempHand[1][0][0] = convers_card(buff[5]); tempHand[1][0][1] = convers_card(buff[6]);
            tempHand[1][1][0] = convers_card(buff[7]); tempHand[1][1][1] = convers_card(buff[8]);
            // printf("%d%d%d%d%d%d%d%d\n", tempHand[0][0][0], tempHand[0][0][1],tempHand[0][1][0], 
            // tempHand[0][1][1], tempHand[1][0][0],tempHand[1][0][1],tempHand[1][1][0], tempHand[1][1][1]);
            
            // check hand illegal
            if(!(2<=tempHand[0][0][0]<=14)) continue;
            if(!(2<=tempHand[0][1][0]<=14)) continue;
            if(!(2<=tempHand[1][0][0]<=14)) continue;
            if(!(2<=tempHand[1][1][0]<=14)) continue;
            if(!(0<=tempHand[0][0][1]<=3)) continue;
            if(!(0<=tempHand[0][1][1]<=3)) continue;
            if(!(0<=tempHand[1][0][1]<=3)) continue;
            if(!(0<=tempHand[1][1][1]<=3)) continue;
            // make sure no same card
            if(memcmp(tempHand[0][0], tempHand[0][1], 2) == 0) continue;  
            if(memcmp(tempHand[0][0], tempHand[1][0], 2) == 0) continue; 
            if(memcmp(tempHand[0][0], tempHand[1][1], 2) == 0) continue; 
            if(memcmp(tempHand[0][1], tempHand[1][0], 2) == 0) continue; 
            if(memcmp(tempHand[0][1], tempHand[1][1], 2) == 0) continue; 
            if(memcmp(tempHand[1][0], tempHand[1][1], 2) == 0) continue; 
            n++;
            // printf("Hand illegal %d : %s\n", n, buff);
            // show_hands(tempHand, 2);

            // save a hand to the heal memory
            memcpy(pHeal + 8*(n-1), tempHand, 8);
        }      
    }
    

    fclose(fTxt);
    printf("Hands read success: %d\n", n);
    return n;
}


// receive a char return the piont it presented, return 0 if error card
char convers_card(char a)
{
    switch (a)
    {
    case '0':  return 0;
    case '1':  return 1;
    case '2':  return 2;
    case '3':  return 3;
    case '4':  return 4;
    case '5':  return 5;
    case '6':  return 6;
    case '7':  return 7;
    case '8':  return 8;
    case '9':  return 9;
    case 'T':  return 10;
    case 'J':  return 11;
    case 'Q':  return 12;
    case 'K':  return 13;
    case 'A':  return 14;
    default:  return 0;
    }
    return 0;
}


















