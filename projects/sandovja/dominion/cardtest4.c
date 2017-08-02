/* -----------------------------------------------------------------------
 *  cardtest3.c
 *
 *  Function to be tested: playCouncilRoomCard
 *  
 *  +4 cards + one buy
 *  all other players draw a card.
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
    int count = 1;
    int cardCount;
    int temphand[MAX_HAND];
    int z = 0;
    int choice = 0;

    int buyCount;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
           remodel, smithy, village, baron, great_hall};

    struct gameState State;
    memset(&State, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &State); // initialize a new game
            // Hand count is min 1, and max 5    
    State.deckCount[player] = 10;

    buyCount = State.numBuys;

    playCouncil_roomCard(0, player, &State);

    if (State.numBuys  != buyCount){
        count = 0;
    }

    if(count == 0){

        printf("TEST SUCCESSFULLY COMPLETED");
    }else{
        printf("TEST FAILED");
    }


return 0;
}
