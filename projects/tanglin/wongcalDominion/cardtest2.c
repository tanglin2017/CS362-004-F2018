/*******************************************************************************
** File: cardtest2.c
** Author: Lingli Tang
** Date: 10/25/2018
** Descriptions: this program test smithy card; bug(draw 2 cards instead of 3)
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
   
    

    printf ("TESTING smithyRefactor(): after player uses smithy card, he should have 2 more card in hand\n");


    int choice1=0, choice2=0, choice3=0, handpos=0;
    bonus=0;
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    p=0;//player 0
    int cardNum1=G.handCount[p];//when the game starts, number of cards on hand of player 0    
    cardEffect(smithy, choice1, choice2, choice3, &G, handpos, &bonus);
	int cardNum2=G.handCount[p];//After player 0 uses smithy card, number of cards on hand of player 0
	int moreCards=cardNum2-cardNum1;

	if (moreCards==2)
        printf("smithyRefactor(): PASS when player has %d more cards after he plays smithy card.\n", moreCards);
    else
        printf("smithyRefactor(): FAIL when player has %d more cards after he plays smithy card.\n", moreCards);
       
    return 0;
}