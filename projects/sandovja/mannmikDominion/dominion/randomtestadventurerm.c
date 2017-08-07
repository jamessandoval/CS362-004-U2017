/**************************************************
**Author: Mike Mann
**Class: CS 362
**Description: Assignment 4 random test of Adventurer card
**Adventurer card was given a bug so it will not pass our tests.
**the bug only allows adventurer to draw one treasure card when it should draw 2.
******************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#define TOTAL_TESTS 1000
#define MAX_PLAYERS 4
#define MAX_HAND 500
#define MAX_DECK 500


int randAdventurerTest(int currentPlayer, struct gameState *state)
{
    int i;
    int preTreasureCards = 0;
    int postTreasureCards = 0;
    //struct gameState pre;
    //memcpy (&pre, state, sizeof(struct gameState));

    for(i = 0; i < state->handCount[currentPlayer]; ++i)
    {
        if (state->hand[currentPlayer][i] == copper || state->hand[currentPlayer][i] == silver || state->hand[currentPlayer][i] == gold)
            preTreasureCards++;
    }
    
   printf("-----------------------------\n");
    
    printf ("\nTesting Adventurer card function.\n");
    printf("Pre/Post hand counts should differ by 2\n\n");
    
    theAdventurer(currentPlayer, state);                      //testing the refactored card funciton directly
    //cardEffect(village, 0, 0, 0, 0, *state, 0);                   //can test the card with cardEffect
    //playCard(0, 0, 0, 0, state);

    for(i = 0; i < state->handCount[currentPlayer]; ++i)
    {
        if (state->hand[currentPlayer][i] == copper || state->hand[currentPlayer][i] == silver || state->hand[currentPlayer][i] == gold)
            postTreasureCards++;
    }
    printf("Pre treasure card count is %d\n", preTreasureCards);
    printf("Post treasure card count is %d\n\n", postTreasureCards);
    printf("-----------------------------\n");

    if(preTreasureCards + 2 == postTreasureCards)
        return 1;                                                   //if adventurer card performs as expected then return 1 test passed
    
    return 0;                                                       //return 0, test failed
}

int main()
{
    srand(time(NULL));
    struct gameState G;
    int n;
    int i;
    int p;
    int passedTests = 0;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

    printf("------BEGIN RANDOM CARD TEST 2------\n\n");
    for (n = 0; n < TOTAL_TESTS; n++) 
    {
        /*for (i = 0; i < sizeof(struct gameState); i++) 
        {
            ((char*)&G)[i] = floor(Random() * 256);
        }*/
        p = 0;
        while(p < 2)
        {
            p = rand() % MAX_PLAYERS;                   //randomize our num players from 2-4
        }
        G.numPlayers = p;
        
        initializeGame(p,k,2,&G);
        //G.deckCount[p] = rand() % MAX_DECK + 1;
        G.whoseTurn = p;
        G.numActions = rand() % 20;                     
        //G.discardCount[p] = rand() % MAX_DECK + 1;
        G.handCount[p] = rand() % MAX_HAND + 1;         //randomize our player's handCount because smithy affects handCount
        //initializeGame(p,k,2,&G);
        G.hand[p][0] = smithy;                         //set our first card in our hand to our card were testing
        for(i = 1; i < G.handCount[p]; ++i)             //loop fills the rest of our hand with random cards starting with the second card
        {
            int r = rand() % 10;                        //use for a random card from our k[10] above
            G.hand[p][i] = k[r]; 
        }
       
        passedTests += randAdventurerTest(p, &G);       //increment our total passed tests by our test result of either 1 or 0
  }
  printf("\n\nTotal passed tests is %d out of %d\n", passedTests, TOTAL_TESTS);
  printf("\n------END RANDOM CARD TEST 2------\n\n");

    return 0;
}