/* -----------------------------------------------------------------------
 *  unittest1.c
 *
 *  Function to be tested: buyCard
 *  // checks to see if prices are correct
 *  // and that the correct cards are purchased.
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
    // int buyCard(int supplyPos, struct gameState *state)
    // variables you need: 
    // supplyPos = 
     
    int numPlayer = 2;
    int seed = 1000; 
    int handCount = 5; 
    int i,j,r; 
    int p = 1; // which player ? (1 or 2) 
    int count = 0;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
           remodel, smithy, village, baron, great_hall};
    
    struct gameState State;
    // make sure correct cards are bought for correct amounts

    for(i = 0; i < 8; i++){
        for(j = 0; j < 17; j++){

            memset(&State, 23, sizeof(struct gameState));   // clear the game state
            r = initializeGame(numPlayer, k, seed, &State); // initialize a new game
            // Hand count is min 1, and max 5 
            State.handCount[p] = handCount;                 // set the number of cards on hand
            State.coins = i;

            // this test makes sure that the prices are correct and coins can be purchased based on set amounts
            if(buyCard(j, &State) != 0 && State.coins == getCost(j)){ // correct choice has been made 
                count += 1;
            }
        }
    }

    // test card purchasing
    if(count == 0){
        printf("TEST SUCCESSFULLY COMPLETED");
    }else{
        printf("TEST FAILED");
    }
    
return 0;
}


