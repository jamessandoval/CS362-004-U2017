/**************************************************
**Author: Mike Mann
**Class: CS 362
**Description: Assignment 3 unittest3.c: Tests the getCost function
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
    printf("\n------BEGIN UNIT TEST 4------\n\n");

    //test curse = 0
    testResult = getCost(curse);
    printf("Testing curse card.\n");
    if(testResult == 0)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test estate = 2
    testResult = getCost(estate);
    printf("Testing estate card.\n");
    if(testResult == 2)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test duchy = 5
     testResult = getCost(duchy);
    printf("Testing duchy card.\n");
    if(testResult == 5)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //province = 8
    testResult = getCost(province);
    printf("Testing province card.\n");
    if(testResult == 8)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test copper = 0
     testResult = getCost(copper);
    printf("Testing copper card.\n");
    if(testResult == 0)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test silver = 3
    testResult = getCost(silver);
    printf("Testing silver card.\n");
    if(testResult == 3)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test gold = 6
    testResult = getCost(gold);
    printf("Testing gold card.\n");
    if(testResult == 6)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test adventurer = 6
     testResult = getCost(adventurer);
    printf("Testing adventurer card.\n");
    if(testResult == 6)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test council room = 5
    testResult = getCost(council_room);
    printf("Testing council room card.\n");
    if(testResult == 5)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test feast = 4
    testResult = getCost(feast);
    printf("Testing feast card.\n");
    if(testResult == 4)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test gardens = 4
    testResult = getCost(gardens);
    printf("Testing gardens card.\n");
    if(testResult == 4)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test mine = 5
    testResult = getCost(mine);
    printf("Testing mine card.\n");
    if(testResult == 5)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test remodel = 4
    testResult = getCost(remodel);
    printf("Testing remodel card.\n");
    if(testResult == 4)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test smithy = 4
    testResult = getCost(smithy);
    printf("Testing smithy card.\n");
    if(testResult == 4)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test village = 3
    testResult = getCost(village);
    printf("Testing village card.\n");
    if(testResult == 3)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test baron = 4
    testResult = getCost(baron);
    printf("Testing baron card.\n");
    if(testResult == 4)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test great hall = 3
    testResult = getCost(great_hall);
    printf("Testing great hall card.\n");
    if(testResult == 3)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test minion = 5
    testResult = getCost(minion);
    printf("Testing minion card.\n");
    if(testResult == 5)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test steward = 3
    testResult = getCost(steward);
    printf("Testing steward card.\n");
    if(testResult == 3)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test tribute = 5
    testResult = getCost(tribute);
    printf("Testing tribute card.\n");
    if(testResult == 5)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test ambassador = 3
    testResult = getCost(ambassador);
    printf("Testing ambassador card.\n");
    if(testResult == 3)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test cutpurse = 4
    testResult = getCost(cutpurse);
    printf("Testing cutpurse card.\n");
    if(testResult == 4)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test embargo = 2
    testResult = getCost(embargo);
    printf("Testing embargo card.\n");
    if(testResult == 2)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test outpost = 5
    testResult = getCost(outpost);
    printf("Testing outpost card.\n");
    if(testResult == 5)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test salvager = 4
    testResult = getCost(salvager);
    printf("Testing salvager card.\n");
    if(testResult == 4)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test sea hag = 4
    testResult = getCost(sea_hag);
    printf("Testing sea hag card.\n");
    if(testResult == 4)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test treasure map = 4
    testResult = getCost(treasure_map);
    printf("Testing treasure map card.\n");
    if(testResult == 4)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    //test with an invalid value
    testResult = getCost(1000);
    printf("Testing with card value of 1000.\n");
    if(testResult == -1)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

//test with an invalid value
    testResult = getCost(-99);
    printf("Testing with card value of -99.\n");
    if(testResult == -1)
        printf("TEST PASSED.\n");
    else
        printf("TEST FAILED.\n");

    printf("\n------END TEST------\n\n");

    

    return 0;
}