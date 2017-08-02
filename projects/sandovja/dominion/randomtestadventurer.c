/* -----------------------------------------------------------------------
 * randomtestadventurer.c
 *
 *  automated random test generator for: playadventurercard
 *
 *  Reveal cards from your deck until you reveal 2 Treasure cards.
 *  Put those Treasure cards in your hand and discard all other revealed cards.
 *  
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "rngs.h"
#include <time.h>

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

// Randomization function
int randInt(int min, int max) {

  int i;

  srand(time(0));

  i = min + rand() % ((max+1) - min);

  //printf("the random value is: %d\n", i);
  return i;

}

int main() {
    
    int handPos = 0;
    int player = 0;
    int numPlayer = 2;
    int seed = 1000; 
    int handCount = 5; 
    int i,j,r; 
    int preTreasureCount;
    int postTreasureCount;
    int cardCount;
    int temphand[MAX_HAND];
    int z = 0;
    int iterations = 0;

    // Things to Randomize
    // 1. handCount 1 - 5
    // 2. the hand itself, just load it with all kinds of fun stuff.
    int k[10] = {adventurer, council_room, feast, gardens, mine,
           remodel, smithy, village, baron, great_hall};

    while(1){

        preTreasureCount = 0;
        postTreasureCount = 0;
        iterations++;

        numPlayer = randInt(2, 4);
        player = randInt(0, numPlayer-1);

        struct gameState State;
        memset(&State, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &State); // initialize a new game

        State.handCount[player] = 5;

        handPos = randInt(0, State.handCount[player]);

        // randomize the hand with numbers 0 - 26 from curse to treasure map
        for(i = 0; i < State.handCount[0]; i++){

            State.deck[player][i] = randInt(0, 16);

        }


        //1.) what cards does player currently have?
        // in base test its 1, 1, 4, 4, 4, which is 2x estates, and 4x coppers
        for(i=0; i < State.handCount[0]; i++){
            //printf("the card number is %d\n", State.deck[player][i]);
            if(State.deck[player][i] == 4 || State.deck[player][i] == 5 || State.deck[player][i] == 6){
                preTreasureCount++;
            }
        }
        
        // Set rand using 1 - 20 for deck size.
        State.deckCount[player] = randInt(1, 20);
        State.supplyCount[estate] = randInt(0, 1);

        State.outpostPlayed = randInt(0, 1);
        State.phase = randInt(0, 1);
        State.numActions = randInt(0, 5);
        State.numBuys = randInt(0, 5);
        State.playedCardCount = randInt(0, 3);

        playAdventurerCard(&State, temphand, z);
        
        for(i=0; i < State.handCount[0]; i++){
            //printf("the card number is %d\n", State.deck[player][i]);
            if(State.deck[player][i] == 4 || State.deck[player][i] == 5 || State.deck[player][i] == 6){
                postTreasureCount++;
            }
        }

        if(postTreasureCount == (preTreasureCount+2)){
            
            printf("2 TREASURES ADDED TEST SUCCESSFULLY COMPLETED\n");
        
        }else{

            printf("2 TREASURE TEST FAILED\n");
        }

        // The new hand count should be 2.
        if(State.handCount[0] == 2){

            printf("HAND COUNT TEST SUCCESSFULLY COMPLETED\n");

        }else{

            printf("HAND COUNT TEST FAILED\n");
        }

        printf("iterations: %d\n", iterations);

        if(iterations == 1000000){
            return 0;
        }
    }


return 0;
}



