/* -----------------------------------------------------------------------
 *  unittest4.c
 *
 *  Function to be tested: int updateCoins();
 *  Ensure coins are updated appropriately.
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

    int check, i;

    int p = 1;
    int bonus = 0;

    struct gameState State;
    State.handCount[p] = 5;

    check = updateCoins(p, &State, bonus);

    // Load the hand full of coppers
    for(i = 0; i < 5; i++){
       State.hand[p][i] = copper;
    }
   
    // check to see that values reflect correct updates
    if(State.coins == 0){

        printf("TEST SUCCESSFULLY COMPLETED");
    }else{
        printf("TEST FAILED");
    }
    // make sure function returns as expected.
    if(check == 0){

        printf("TEST SUCCESSFULLY COMPLETED");
    }else{
        printf("TEST FAILED");
    }

return 0;
}
