/* -----------------------------------------------------------------------
 *  randomtestfeast.c
 *
 *  Function to be tested: playFeastCard
 *
 *  trash card and gain a new card with a value of up to 5
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

// Randomization function
int randInt(int min, int max) {

  int i;

  srand(time(0));

  i = min + rand() % ((max+1) - min);

  //printf("the random value is: %d\n", i);
  return i;

}

int arrayShuffle(int *cardArray){

    int temp;
    int randomIndex;
    int i;

    // populate the array
    for(i=0;i < 20;i++){
        cardArray[i] = i+7; 
    }

    // shuffle the array
    for (i = 0; i < 20; i++) {
        temp = cardArray[i];
        srand(time(0));
        randomIndex = rand() % 20;

        cardArray[i] = cardArray[randomIndex];
        cardArray[randomIndex] = temp;
    }
}

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
    int choice = 0;
    int cardArray[20];
    int iteration = 0;
    int *k; 

    while(1){

        iteration++;

        arrayShuffle(&cardArray);

        k = kingdomCards(cardArray[0], cardArray[1], cardArray[2], cardArray[3], cardArray[4], cardArray[5], cardArray[6], cardArray[7], cardArray[8], cardArray[9]);

        printf("the iteration is %d\n\n", iteration);

        numPlayer = randInt(2, 4);
        player = randInt(0, numPlayer-1);

            struct gameState State;
            memset(&State, 23, sizeof(struct gameState));   // clear the game state
            r = initializeGame(numPlayer, k, seed, &State); // initialize a new game   

        for(i=0;i < numPlayer;i++){

            State.deckCount[i] = 10;

            
            playFeastCard(i, &State, choice, temphand);

            if(State.handCount[0] != 5 || State.deck[player][i] > 5){
                printf("TEST FAILED");
            }else{
                printf("TEST SUCCESSFULLY COMPLETED");
            }

        }

        if(iteration == 1000000){
            return 0;
        }

    }

return 0;
}

// trash card and gain up to 5.

