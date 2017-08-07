/**************************************************
**Author: Mike Mann
**Class: CS 362
**Description: Assignment 3 unittest2.c: Tests the handCard function.
**handCard function should return the card at specific position in a player's hand.
**in unittest2 we set the five player cards and check to see if handCard matches.
******************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//function test handCard function
//takes postion of card in handpos, gameState, and an integer with the targeted card number.
//for example, if we are looking for smithy we pass smithy in our target parameter
int testHandCard(int handpos, struct gameState *g, int target)
{
    if(g->hand[0][handpos] == target)
        return 1;
    else 
        return 0;
}

int main()
{
  struct gameState G;
  int i;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
  
  //set our player's hand to have the first 5 cards from our k array
  for(i = 0; i < 5; ++i)
  {
      G.hand[0][i] = k[i];
  }

  printf("------BEGIN UNIT TEST 2------\n\n");

  printf("Card 1 should be adventurer\n");
  //test that our first card is adventurer
  if(testHandCard(0, &G, k[0]))
      printf("TEST PASSED\n");
  else
    printf("TEST FAILED\n");

  printf("Card 2 should be gardens\n");
  
  if(testHandCard(1, &G, k[1]))
      printf("TEST PASSED\n");
  else
    printf("TEST FAILED\n");

  printf("Card 3 should be embargo\n");
  
  if(testHandCard(2, &G, k[2]))
      printf("TEST PASSED\n");
  else
    printf("TEST FAILED\n");

  printf("Card 4 should be village\n");
  
  if(testHandCard(3, &G, k[3]))
      printf("TEST PASSED\n");
  else
    printf("TEST FAILED\n");

  printf("Card 5 should be minion\n");
  
  if(testHandCard(4, &G, k[4]))
      printf("TEST PASSED\n");
  else
    printf("TEST FAILED\n");

    //testing outside of our size hand. 
    printf("Testing outside of hand size. Cards should not match.\n");
    if(!testHandCard(5, &G, k[1]))
        printf("TEST PASSED\n");
    else
        printf("TEST FAILED.\n");
    
    printf("\n------END TEST------\n");
  
    return 0;
}