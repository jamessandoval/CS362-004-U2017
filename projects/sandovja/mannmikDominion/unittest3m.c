/**************************************************
**Author: Mike Mann
**Class: CS 362
**Description: Assignment 3 unittest3.c: Tests the isGameOver function
**alters the supplyCount piles stored in our gameState to check our isGameOver function
******************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int test_isGameOver(struct gameState *state)
{
    if(isGameOver(state))
        return 1;
    else 
        return 0;
}

int main()
{
    int i;
    int j;
    //create our gameState
    struct gameState *state = malloc(sizeof(struct gameState));
    int numPlayers = 2;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    
    //initializing our supply piles
    //used pieces of the code from the initialize game function to set these supply values by hand
    //because we are only testing isGameOver in our unittest3 
    state->supplyCount[curse] = 10;
    state->supplyCount[estate] = 8;
    state->supplyCount[duchy] = 8;
    state->supplyCount[province] = 8;
    state->supplyCount[copper] = 60 - (7 * numPlayers);
    state->supplyCount[silver] = 40;
    state->supplyCount[gold] = 30;

     for (i = adventurer; i <= treasure_map; i++)       	//loop all cards
    {
        for (j = 0; j < 10; j++)           		//loop chosen cards
        {
            if (k[j] == i)
                {
                    //check if card is a 'Victory' Kingdom card
                    if (k[j] == great_hall || k[j] == gardens)
                    {
                    if (numPlayers == 2){ 
                        state->supplyCount[i] = 8; 
                    }
                    else
                    { 
                        state->supplyCount[i] = 12; 
                        }
                    }
                    else
                    {
                    state->supplyCount[i] = 10;
                    }
                    break;
                }
            else    //card is not in the set choosen for the game
                {
                state->supplyCount[i] = -1;
                }
            }
    }


   printf("\n------BEGIN UNIT TEST 3------\n\n");

   //test with our default supply.
   printf("First test uses default supply counts. Game should NOT be over.\n");
    if(!test_isGameOver(state))
        printf("TEST PASSED!\n");
    else
        printf("TEST FAILED.\n");

    //set our province supply to 0 to end the game.
    state->supplyCount[province] = 0;
    //test with province supply at 0. game should be over
    printf("Testing isGameOver with our province supply at 0. Game should be OVER.\n");
    if(test_isGameOver(state))
        printf("TEST PASSED!\n");
    else
        printf("TEST FAILED.\n");
    
    //restore our provice supply so we can move to the next statement in isGameOver
    state->supplyCount[province] = 8;

    //set 3 of our supply piles to 0 to test next case in isGameOver
    state->supplyCount[curse] = 0;
    state->supplyCount[estate] = 0;
    state->supplyCount[duchy] = 0;
    //test with 3 supply piles at 0
    printf("Testing isGameOver with 3 of our supply piles at 0. Game should be OVER.\n");
    if(test_isGameOver(state))
        printf("TEST PASSED!\n");
    else
        printf("TEST FAILED.\n");
    
    //restore one supply pile
    state->supplyCount[duchy] = 8;

    //test with only 2 of our supply piles empty.
    printf("Testing isGameOver with 2 of our supply piles at 0. Game should be NOT be over.\n");
    if(!test_isGameOver(state))
        printf("TEST PASSED!\n");
    else
        printf("TEST FAILED.\n");

    printf("\n------END TEST------\n\n");

    free(state);
    return 0;
}