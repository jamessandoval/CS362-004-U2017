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
    int numact1;
    int numact2;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           council_room, tribute, smithy};
    initializeGame(2,k,2,&G);

    printf("------BEGIN CARD TEST 4------\n\n");
    G.hand[0][0] = village;
    numact1 = G.numActions;
    hCount1 = G.handCount[0];
    if((result = playCard(0, 0, 0, 0, &G)) != 0)
        printf("Card wasn't played.\n");

    hCount2 = G.handCount[0];
    numact2 = G.numActions;

    //see if the handcount is the same after playing
    if(hCount2 == hCount1)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");
    
    //see if numAcions was increased by 2
    if(numact2 > (numact1+2))
        printf("TEST PASSED.");
    else
        printf("TEST FAILED.\n");
    //check if the village card was discarded
    if(G.hand[0][0] != village)
        printf("TEST PASSED. village discarded\n.");
    else
        printf("TEST FAILED>\n");
    
    printf("\n------END TEST------\n");

    return 0;
}