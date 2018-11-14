/****************4**************************************************************
** File: randomtestcard2.c
** Author: Lingli Tang
** Date: 11/13/2018
** Descriptions: this program test remodel card using random testing methods; 
** bug: no longer gain a card
*******************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>



int main() {
    
    int seed = 1000;
    int numPlayer = 2;
    int p;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
   
    

    printf ("TESTING remodelRefactor():\n");

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    srand(time(NULL));   
    p=0;

    int choice1=rand()%6;//randomly pick the card in hand to be trashed 
   // printf("the card in hand to be discarded %d\n", choice1);
    int costTrash=getCost(G.hand[p][choice1]);// get the cost of the card in hand to be trashed 
   // printf("cost of the card in hand to be discarded %d\n", costTrash);
    int choice2=rand()%27;//randomly generate the choice for gained card
    //printf("gained card %d\n", choice2);
    int costCard=getCost(choice2);//get the cost of the randomly chosen card
    //printf("cost of gained card %d\n", costCard);

    int choice3=0;
    int handpos=0;
    bonus=0;
    int cardNum1=G.handCount[p];
    //printf("number of cards in hand%d\n", cardNum1);
    int deckBefore=G.deckCount[p];
    //printf("deck before %d\n", deckBefore);

    int returnCode=cardEffect(remodel, choice1, choice2, choice3, &G, handpos, &bonus);
    int cardNum2=G.handCount[p];
   //printf("number of cards in hand%d\n", cardNum2);

    int extraCost=costCard-costTrash;//extra value of a gained card compared to the card to be discarded
    int gap=cardNum1-cardNum2;//the difference between number of cards in hand before and after
    int deckAfter=G.deckCount[p];
    //printf("deck after %d\n", deckAfter);

    int lessDeck=deckBefore-deckAfter;//number of card drawn after the player pays remodel card

     //output test results
    if(returnCode==-1&&extraCost<2)
        printf("remodelRefactor() PASS when the system does not allow player exchange a card in hand cost %d for a card cost %d\n", costTrash, costCard);
    else if(returnCode==0&&extraCost>=2)
        printf("remodelRefactor() PASS when the system allow player exchange a card in hand cost %d for a card cost %d\n", costTrash, costCard);
    else if(returnCode==-1&&extraCost>=2)
         printf("remodelRefactor() FAIL when the system does not allow player exchange a card in hand cost %d for a card cost %d\n", costTrash, costCard);
    else if(returnCode==0&&extraCost<2)

        printf("remodelRefactor() FAIL when the system allow player exchange a card in hand cost %d for a card cost %d\n", costTrash, costCard);  

    if(lessDeck==1)
        printf("remodelRefactor() PASS when deck has %d less card after he uses remodel card.\n", lessDeck);
    else
        printf("remodelRefactor() FAIL when desk has %d less card after he uses remodel card.\n", lessDeck);   
	if(gap==1)
        printf("remodelRefactor() PASS when player has %d less card in hand after he uses remodel card.\n", gap);
    else
        printf("remodelRefactor() FAIL when player has %d less cards in hand after he uses remodel card.\n", gap);      
       
    return 0;
}