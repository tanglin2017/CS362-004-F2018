/****************4**************************************************************
** File: cardtest4.c
** Author: Lingli Tang
** Date: 10/25/2018
** Descriptions: this program test remodel card; bug(draw 2 cards instead of 3)
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
   
    

 printf ("TESTING remodelRefactor():\n");


    int choice1=0;
    int choice2=0;//choice for gained card, 0 is curse card whose cost is 0
    int choice3=0;
    int handpos=0;
    bonus=0;
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    int returnCode=cardEffect(remodel, choice1, choice2, choice3, &G, handpos, &bonus);

    if(returnCode==-1)
        printf("remodelRefactor() PASS when the system does not allow player to gain a curse card with cost 0\n");
    else
        printf("remodelRefactor() FAIL when the system does not allow player to gain a curse card with cost 0\n");

    choice1=0;
    choice2=3;//choice for gained card, 3 is PROVINCE card whose cost is maxmimum
    choice3=0;
    handpos=0;
    bonus=0;
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
     p=0;//player 0
    int cardNum1=G.handCount[p];
    cardEffect(remodel, choice1, choice2, choice3, &G, handpos, &bonus);
    int cardNum2=G.handCount[p];
    int gap=cardNum1-cardNum2;


    if(gap==1)
        printf("remodelRefactor() PASS when player has %d less cards than before he uses remodel card.\n", gap);
    else
        printf("remodelRefactor() FAIL when player has %d less cards than before he uses remodel card.\n", gap);   
	   
       
    return 0;
}