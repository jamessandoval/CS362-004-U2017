/**************************************************
**Author: Mike Mann
**Class: CS 362
**Description: Assignment 3 cardtest1.c
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
    int tCount1;            //treasure count before playing card
    int tCount2;            //treasure count after playing card
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           council_room, tribute, smithy};
    initializeGame(2,k,2,&G);
   

    printf("------BEGIN CARD TEST 1------\n\n");

     for(i = 0; i < G.handCount[0]; ++i)
    {
        if(handCard(i, &G) == copper || handCard(i, &G) == silver || handCard(i, &G) == gold )
            tCount1++;
    }
    G.hand[0][0] = adventurer;
    if((result = playCard(0, 0, 0, 0, &G)) != 0)
        printf("Card wasn't played.\n");
   
    for(i = 0; i < G.handCount[0]; ++i)
    {
        if(handCard(i, &G) == copper || handCard(i, &G) == silver || handCard(i, &G) == gold )
            tCount2++;
    }

    if(G.hand[0][0] == adventurer)
        printf("TEST PASSED. Adventurer was discarded.\n");
    else
        printf("TEST FAILED. Card not discared.\n");
    //check that 2 treasure cards were added to our hand
    if(tCount2 >= (tCount1 + 2))
        printf("TEST PASSED. Two treasure cards added.\n");
    else
        printf("TEST FAILED. Didn't draw two treasures.\n");
    
    
     printf("\n------END TEST------\n");

    return 0;
}