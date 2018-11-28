/*******************************************************************************
** File: randomtestadventurer.c
** Author: Lingli Tang
** Date: 11/13/2018
** Descriptions: this program test adventurer card using random testing methods; bug(When the player draws 
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
#include <time.h>


int main() {
        printf ("TESTING adventurerRefactor():\n");

    int seed = 1000;
    int numPlayer = 2;
    int p;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

    initializeGame(numPlayer, k, seed, &G); // initialize a new game
   
    // randomly generate an array of cards on deck for each player, the cards only consist of copper, silver and gold
    int i, j;   
    srand(time(NULL));   
     for (i = 0; i < numPlayer; i++){
            for(j = 0;j < MAX_DECK; j++){
                int randNum=rand() % 3;
                if(randNum == 0){
                    G.deck[i][j] = copper;
                } else if(randNum == 1){
                    G.deck[i][j] = silver;
                }
                else {
                    G.deck[i][j] = gold;
                }
            }
         } 

    int choice1=0, choice2=0, choice3=0, handpos=0;
    bonus=0;

	cardEffect(adventurer, choice1, choice2, choice3, &G, handpos, &bonus);//call cardEffect function to let player 0 use adventurer card
	p=0;
	//count number of copper, silver and gold in discard pile of player 0.
	int discardCopper = 0;
    int discardSilver = 0;
    int discardGold = 0;
    int q;
        for(q = 0; q < G.discardCount[p]; q++){
            if(G.discard[p][q] == copper) {
                discardCopper++;
            } else if(G.discard[p][q] == silver) {
                discardSilver++;
            } else if(G.discard[p][q] == gold) {
                discardGold++;
            }
        }
     //output test results
    if(discardCopper != 0){
            printf("adventurerRefactor() FAIL when copper was discarded.\n");
          
        }
	if(discardCopper == 0){
            printf("adventurerRefactor() PASS when NO copper was discarded.\n");
          
        }
    if(discardSilver != 0){
            printf("adventurerRefactor() FAIL when silver was discarded.\n");
           
        }
 	if(discardSilver == 0){
            printf("adventurerRefactor() PASS when NO silver was discarded.\n");
           
        }
    if(discardGold != 0){
            printf("adventurerRefactor() FAIL when gold was discarded.\n");
           
        }
 	if(discardGold == 0){
            printf("adventurerRefactor() PASS when NO gold was discarded.\n");
           
        }
    return 0;
}