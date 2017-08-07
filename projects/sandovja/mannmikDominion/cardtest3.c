/**************************************************
**Author: Mike Mann
**Class: CS 362
**Description: Assignment 3 cardtest3.c
******************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    struct gameState G;
    int result;
    int hCount1;            //hand count before playing card
    int hCount2;            //hand count after playing card
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           council_room, tribute, smithy};
    initializeGame(2,k,2,&G);

    G.hand[0][0] = smithy;
    hCount1 = numHandCards(&G);
    if((result = playCard(0, 0, 0, 0, &G)) != 0)
        printf("Card wasn't played.\n");
    hCount2 = numHandCards(&G);

     printf("------BEGIN CARD TEST 3------\n\n");
    if(hCount2 == (hCount1 + 2))        //we discard smithy so hand should be greater by 2 cards because we draw 3
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");
    
    if(G.hand[0][0] != smithy)
        printf("TEST PASSED. Smithy discarded\n.");
    else
        printf("TEST FAILED>\n");
    
     printf("\n------END TEST------\n");

     return 0;
}