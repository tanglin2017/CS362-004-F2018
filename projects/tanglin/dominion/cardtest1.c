/*******************************************************************************
** File: cardtest1.c
** Author: Lingli Tang
** Date: 10/25/2018
** Descriptions: this program test adventurer card; bug(When the player draws 
** a gold card, which will be treated as other non-treasure card and will be discarded)
*******************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>




int main() {
    
    int seed = 1000;
    int numPlayer = 2;
    int p;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
   
    // arrays of all coppers, silvers, and golds
    int i;
    int handCount=5;
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    printf ("TESTING adventurerRefactor(): set all cards on deck as copper cards\n");
    int choice1=0, choice2=0, choice3=0, handpos=0;
    bonus=0;
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    p=0;//player 0
    memcpy(G.deck[p], coppers, sizeof(int) * handCount); // set all the cards to copper
    int cardNum1=G.handCount[p];//when the game starts, number of copper cards on hand of player 0    
    cardEffect(adventurer, choice1, choice2, choice3, &G, handpos, &bonus);
    int cardNum2=G.handCount[p];//After player 0 uses adventure card, number of cards on hand of player 0
    int moreCard=cardNum2-cardNum1;   

    if (moreCard==2)
        printf("adventurerRefactor(): PASS when player draws 2 and keeps %d copper cards.\n", moreCard);
    else
        printf("adventurerRefactor(): FAIL when player draws 2 and keeps %d copper cards.\n", moreCard);

    printf ("TESTING adventurerRefactor(): set all cards on deck as silver cards\n");
    choice1=0; 
    choice2=0; 
    choice3=0;
    handpos=0;
    bonus=0;
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    p=0;//player 0
    memcpy(G.deck[p], silvers, sizeof(int) * handCount); // set all the cards to copper
    cardNum1=G.handCount[p];//when the game starts, number of copper cards on hand of player 0    
    cardEffect(adventurer, choice1, choice2, choice3, &G, handpos, &bonus);
    cardNum2=G.handCount[p];//After player 0 uses adventure card, number of cards on hand of player 0
    moreCard=cardNum2-cardNum1; 
      
    if (moreCard==2)
        printf("adventurerRefactor(): PASS when player draws 2 and keeps %d silver cards.\n", moreCard);
    else
        printf("adventurerRefactor(): FAIL when player draws 2 and keeps %d silver cards.\n", moreCard);



    printf ("TESTING adventurerRefactor(): set all cards on deck as gold cards\n");
    choice1=0; 
    choice2=0; 
    choice3=0;
    handpos=0;
    bonus=0;
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    p=0;//player 0
    memcpy(G.deck[p], golds, sizeof(int) * handCount); // set all the cards to copper
    cardNum1=G.handCount[p];//when the game starts, number of copper cards on hand of player 0    
    cardEffect(adventurer, choice1, choice2, choice3, &G, handpos, &bonus);
    cardNum2=G.handCount[p];//After player 0 uses adventure card, number of cards on hand of player 0
    moreCard=cardNum2-cardNum1; 

    if (moreCard==2)
        printf("adventurerRefactor(): PASS when player draws 2 and keeps %d gold cards.\n", moreCard);
    else
        printf("adventurerRefactor(): FAIL when player draws 2 and keeps %d gold cards.\n", moreCard);

       
    return 0;
}