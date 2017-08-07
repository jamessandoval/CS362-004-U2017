/* -----------------------------------------------------------------------
 *  unittest2.c
 *
 *  Function to be tested: int compare
 *  Ensure that the compare function works correctly.
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

    int a, b, c;

    // should return 0 = the same
    a = compare("test", "test");

    // should return 1 = partial
    b = compare("test", "te");

    // should return -1 = different
    c = compare("adventurer", "test");

    if(a == 0){

        printf("TEST SUCCESSFULLY COMPLETED");
    }else{
        printf("TEST FAILED - SAME");
    }

    if(b == 1){

        printf("TEST SUCCESSFULLY COMPLETED");
    }else{
        printf("TEST FAILED - PART");
    }

    if(c == -1){

        printf("TEST SUCCESSFULLY COMPLETED");
    }else{
        printf("TEST FAILED - DIFF ");
    }


return 0;
}

