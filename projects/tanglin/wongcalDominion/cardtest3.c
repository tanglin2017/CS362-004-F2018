/*******************************************************************************
** File: cardtest3.c
** Author: Lingli Tang
** Date: 10/25/2018
** Descriptions: this program test council_room card; bug(draw 0 cards instead of 4)
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
   
    

    printf ("TESTING council_roomRefactor(): after player uses council_room card, he should have 3 more cards in hand after he draws 4 cards\n");


    int choice1=0, choice2=0, choice3=0, handpos=0;
    bonus=0;
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    p=0;//player 0
    int cardNum1=G.handCount[p];//when the game starts, number of cards on hand of player 0    
    cardEffect(council_room, choice1, choice2, choice3, &G, handpos, &bonus);
	int cardNum2=G.handCount[p];//After player 0 uses smithy card, number of cards on hand of player 0
	int moreCards=cardNum2-cardNum1;

	if (moreCards==4)
        printf("council_roomRefactor(): PASS when player has %d more cards after he plays council_room card.\n", moreCards);
    else
        printf("council_roomRefactor(): FAIL when player has %d more cards after he plays council_room card.\n", moreCards);
       
    return 0;
}