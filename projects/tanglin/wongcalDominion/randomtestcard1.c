/*******************************************************************************
** File: randomtestcard1.c
** Author: Lingli Tang
** Date: 11/13/2018
** Descriptions: this program test smithy card using random testing methods; 
** bug(draw 2 cards instead of 3)
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
    printf ("TESTING smithyRefactor():\n");
    int numPlayer;
    int p;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    
    srand(time(NULL));      
    int seed = rand()%1000+1;//random seed 1-1000
    numPlayer=rand()%4+2;//randomly generate 2-4 players
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    p=0;//player 0    
       int handCard = G.handCount[p] ;
       int handpos=rand()%handCard+handCard-1;//randomly select a card to play which will be discarded
        //personal checks
        int deckBefore = G.deckCount[p];
     //   printf("deck before %d\n", deckBefore);
        int handBefore = G.handCount[p];
     //   printf("Hand before %d\n",handBefore);
        int discardBefore = G.discardCount[p];
     //   printf("Discard before %d\n", discardBefore);        

    int choice1=0, choice2=0, choice3=0;
    bonus=0;
   
   cardEffect(smithy, choice1, choice2, choice3, &G, handpos, &bonus);
   int  deckAfter = G.deckCount[0];
   //     printf("deck after %d\n", deckAfter);
    int handAfter = G.handCount[0];
    //    printf("hand After %d\n", handAfter);
    int discardAfter = G.discardCount[p];
   //     printf("Discard After %d\n\n", discardAfter);
    int moreCards=handAfter-handBefore;
    int numberDiscard=discardAfter-discardBefore;
    int lessDeck=deckBefore-deckAfter;

    //output test results
    if (lessDeck==3)
        printf("smithyRefactor(): PASS when deck has %d less cards after player plays smithy card.\n", lessDeck);
    else
        printf("smithyRefactor(): FAIL when deck has %d less cards after player plays smithy card. (should be 3)\n", lessDeck);  
    if (moreCards==2)
        printf("smithyRefactor(): PASS when player has %d more cards in hand after he plays smithy card.\n", moreCards);
    else
        printf("smithyRefactor(): FAIL when player has %d more cards in hand after he plays smithy card. (should be 2)\n", moreCards);   
    if (numberDiscard==1)
        printf("smithyRefactor(): PASS when player discard %d card after he plays smithy card.\n", numberDiscard);
    else
        printf("smithyRefactor(): FAIL when player discard %d card after he plays smithy card. (should be 1)\n", numberDiscard);    
   
       
    return 0;
}