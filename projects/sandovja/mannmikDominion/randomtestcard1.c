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
#include <stdlib.h>
#include <assert.h>
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
    int player = 1;
    int numPlayers = 2;
    int seed = 1000; 
    int handCount = 5; 
    int i,j,r;
    int *k; 
    int count = 0;
    int preHandCount;
    int postHandCount;
    int iterations = 0;
    int cardArray[20];
    int numGen = 0;
    struct gameState State;
    int *coin_bonus = randInt(0, 5);
    
     while(1){

        iterations++;

        arrayShuffle(&cardArray);

        k = kingdomCards(cardArray[0], cardArray[1], cardArray[2], cardArray[3], cardArray[4], cardArray[5], cardArray[6], cardArray[7], cardArray[8], cardArray[9]);

        printf("the iteration is %d\n\n", iterations);

        numPlayers = randInt(2, 4);
        player = randInt(0, numPlayers-1);

        memset(&State, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayers, k, seed, &State); // initialize a new game
        
        for(i = 0; i < numPlayers; i++){
            // get data for player and set data
            for(j = 0; j < 2; j++){

                // assign a new value to each card 
                r = i+1;
                State.deck[i][j] = k[r];
                //printf("the new card is: %d \n", State.deck[i][j]);
            }

            for(j = 3; j < 6; j++){

                numGen = randInt(4, 6);
                // assign a new value to each card 
                State.deck[i][j] = numGen;
                //printf("the new card is: %d \n", State.deck[i][j]);
            }

            State.handCount[i] = 5;
            preHandCount = State.handCount[i];

            printf("the hand count is: %d \n", State.handCount[i]);
            printf("the deck count is: %d \n", State.deckCount[i]);

            playCard(State.deck[i][0], State.deck[i][1], State.deck[i][2], State.deck[i][3], &State);

            //cardEffect(State.deck[i][0], State.deck[i][1], State.deck[i][2], State.deck[i][3], &State, 0, &coin_bonus);

            State.numActions = 1;
                
            for(i = 0; i < numPlayers; i++){

                theSmithy(i, &State, handPos); 

                postHandCount = State.handCount[i]+1;

                if(postHandCount == 8){

                    printf("TEST SUCCESSFULLY COMPLETED\n\n");

                }else{

                    printf("TEST FAILED");
                }

            }
        }

        if(iterations == 1000000){
            return 0;
        }

    }

return 0;
}
