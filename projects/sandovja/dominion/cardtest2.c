/* -----------------------------------------------------------------------
 *  cardtest1.c
 *
 *  Function to be tested: playadventurercard
 *
 *  Reveal cards from your deck until you reveal 2 Treasure cards. 
 *  Put those Treasure cards in your hand and discard the other revealed cards.
 *  
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    
    int handPos = 0;
    int player = 0;
    int numPlayer = 2;
    int seed = 1000; 
    int handCount = 5; 
    int i,j,r; 
    int count = 0;
    int cardCount;
    int temphand[MAX_HAND];
    int z = 0;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
           remodel, smithy, village, baron, great_hall};

    struct gameState State;
    memset(&State, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &State); // initialize a new game
            // Hand count is min 1, and max 5    
    State.deckCount[player] = 10;
    playAdventurerCard(&State, temphand, z);

    //printf("The old hand count is: %d", State.handCount[0]);

    // if the values match, the cards have added two and both are treasure cards.
    for(i = 5; i < 7;i++){
        //printf("The hand is:%d\n", State.deck[player][i]);
        if(State.deck[player][i] == 4 || State.deck[player][i] == 5 || State.deck[player][i] == 6){

            count = 0;
        }else{
            count = 1;
        }
    }
    
    //printf("The new hand count is: %d", State.handCount[0]);

    if(State.handCount[0] == 7){

        printf("TEST SUCCESSFULLY COMPLETED");
    }else{
        printf("TEST FAILED");
    }

    if(count == 0){

        printf("TEST SUCCESSFULLY COMPLETED");
    }else{
        printf("TEST FAILED");
    }
return 0;
}

