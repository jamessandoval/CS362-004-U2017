/**************************************************
**Author: Mike Mann
**Class: CS 362
**Description: Assignment 3 cardtest2.c
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
    int i;
    int result;
    int coinCount1;            //coin count before playing card
    int coinCount2;            //coin count after playing card
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           council_room, tribute, smithy};
    initializeGame(2,k,2,&G);

     printf("------BEGIN CARD TEST 2------\n\n");
    G.hand[0][0] = embargo;

    coinCount1 = G.coins;
     if((result = playCard(0, 0, 0, 0, &G)) != 0)
        printf("Card wasn't played.\n");
    coinCount2 = G.coins;
    coinCount1 += 2;
    if(coinCount2 >= coinCount1)
        printf("TEST PASSED. Coins increased by 2.\n");
    else
        printf("TEST FAILED. Coins were not increased by 2\n");

    if(G.embargoTokens[0] == 1)
        printf("TEST PASSED. Embargo token added.\n");
    else
        printf("TEST FAILED.\n");
    
    if(G.hand[0][0] != embargo)
        printf("TEST PASSED. Embargo discarded\n.");
    else
        printf("TEST FAILED>\n");
    
     printf("\n------END TEST------\n");
    

    return 0;
}