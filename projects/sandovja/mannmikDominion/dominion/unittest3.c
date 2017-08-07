/* -----------------------------------------------------------------------
 *  unittest3.c
 *
 *  Function to be tested: int isGameOver();
 *  Make sure game ends when it is supposed to. 
 *  (based on values that are checked.)
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

    struct gameState State;

    State.supplyCount[province] = 0;

    for (i = 0; i < 25; i++){

        State.supplyCount[i] = 0;
    }

    check = isGameOver(&State);

    // value should be 1 indicating game is over.
    if(check == 1){
        printf("TEST SUCCESSFULLY COMPLETED");
    }else{
        printf("TEST FAILED");
    }
return 0;
}

