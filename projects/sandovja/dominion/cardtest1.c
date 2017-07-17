/* -----------------------------------------------------------------------
 *  cardtest1.c
 *
 *  Function to be tested: playsmithcard
 *  
 *  +3 Cards.
 *  Hand should start with 5, then pick up 3 more. resulting in 8.
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
    int player = 1;
    int numPlayer = 2;
    int seed = 1000; 
    int handCount = 5; 
    int i,j,r; 
    int count = 0;
    int handAfterCard;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
           remodel, smithy, village, baron, great_hall};

    struct gameState State;
    memset(&State, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &State); // initialize a new game
            // Hand count is min 1, and max 5 
    State.handCount[player] = handCount;     
    State.deckCount[player] = 10;

    playSmithyCard(handPos, &State, player); 

    handAfterCard = State.handCount[player] + 1;
    // get hand count
    //printf("Get the resulting count %d", handAfterCard);

    if(handAfterCard == 8){

        printf("TEST SUCCESSFULLY COMPLETED");
    }else{
        printf("TEST FAILED");
    }

return 0;
}
