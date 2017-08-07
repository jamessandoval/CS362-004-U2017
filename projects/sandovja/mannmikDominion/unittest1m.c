/**************************************************
**Author: Mike Mann
**Class: CS 362
**Description: Assignment 3 unittest1.c: this tests the numHandCards function.
**numHandCards returns the number of cards in a player's hand. 
**there is no checking of any kind from the numHandCards function so all values set for each player's handcount
**should be valid.
******************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int testResult;
    int player1 = 0;
    int player2 = 0;

    //set up a gamestate
    struct gameState G;

    G.handCount[player1] = 5;
    G.handCount[player2] = 5;    

    printf("--------BEGIN TEST--------\n\n");

    printf("-----Player one should have 5 cards in their hand-----\n");
    
    testResult = numHandCards(&G);
    if(testResult == 5)
        printf("TEST PASSED. Player 1 number of cards: %d.\n\n", testResult);
    else
        printf("TEST FAILED. Player 1 number of cards: %d\n\n", testResult);

    //Test the hand count with large number above what is meant to be used
    G.handCount[player1] = 100;

    printf("-----Player one should have 100 cards in their hand-----\n");
    
    testResult = numHandCards(&G);
    if(testResult == 100)
        printf("TEST PASSED. Player 1 number of cards: %d.\n\n", testResult);
    else
        printf("TEST FAILED. Player 1 number of cards: %d\n\n", testResult);


    //Test the hand count with negative number
    G.handCount[player1] = -2;
    G.handCount[player2] = -2;

    printf("-----Player one should have -2 cards in their hand-----\n");
    
    G.whoseTurn = player1;
    testResult = numHandCards(&G);
    if(testResult == -2)
        printf("TEST PASSED. Player 1 number of cards: %d.\n\n", testResult);
    else
        printf("TEST FAILED. Player 1 number of cards: %d\n\n", testResult);


     //Test the hand count with different numbers for each player
    G.handCount[player1] = 3;

    printf("-----Player should have 3 cards in their hand-----\n");
    
    printf("Player hand is %d\n", G.whoseTurn);
    testResult = numHandCards(&G);
    if(testResult == 3)
        printf("TEST PASSED. Player 1 number of cards: %d.\n\n", testResult);
    else
        printf("TEST FAILED. Player 1 number of cards: %d\n\n", testResult);


     //Test the hand count with different 0 for each player
    G.handCount[player1] = 0;

    printf("-----Player one should have 0 cards in their hand-----\n");
    
    testResult = numHandCards(&G);
    if(testResult == 0)
        printf("TEST PASSED. Player 0 number of cards: %d.\n\n", testResult);
    else
        printf("TEST FAILED. Player 1 number of cards: %d\n\n", testResult);


    return 0;
}