/*********************************************
** File: unittest1.c
** Author: Lingli Tang
** Date: 10/25/2018
** Descriptions: this program test function buyCard.
*********************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


void testBuyCard()
{
	struct gameState state1;
	struct gameState state2;
	struct gameState state3;
	struct gameState state4;
	struct gameState state5;
	struct gameState state6;
	struct gameState state7;
	
	int duchy = 2;//duchy card, cost 5 coins
	int province = 3;//province card, cost 8 coins
	 		
	state1.numBuys = 0;
	state1.coins = 5;

	state2.numBuys = 2;
	state2.coins = 5;
	state2.supplyCount[duchy]=2;

	state3.numBuys = 2;
	state3.coins = 5;
	state3.supplyCount[duchy]=0;

	state4.numBuys=2;
	state4.coins=5;
	state4.supplyCount[province]=2;

	state5.numBuys=2;
	state5.coins=10;
	state5.supplyCount[province]=2;

	state6.numBuys=2;
	state6.coins=10;
	state6.supplyCount[province]=2;
	state6.whoseTurn=0;//set player0's turn
	state6.handCount[0]=5;//set the number of cards in hand is 5

	state7.numBuys=2;
	state7.coins=10;
	state7.supplyCount[province]=2;
	
	
	if (buyCard(duchy, &state1) == -1)
        printf("buyCard(): PASS when player with 5 coins can NOT buy a duchy card because he does not have any buy left.\n");
    else
        printf("buyCard(): FAIL when player with 5 coins can NOT buy a duchy card because he does not have any buy left.\n");

	if (buyCard(duchy, &state2) == 0)
        printf("buyCard(): PASS when player with 5 coins and 2 buy can buy a duchy card (2 duchy cards available).\n");
    else
        printf("buyCard(): FAIL when player with 5 coins and 2 buy can buy a duchy card (2 duchy cards available)..\n");

    if (buyCard(duchy, &state3) == -1)
        printf("buyCard(): PASS when player with 5 coins and 2 buy can NOT buy a duchy card because 0 duchy card available.\n");
    else
        printf("buyCard(): FAIL when player with 5 coins and 2 buy can NOT buy a duchy card because 0 duchy card available.\n");

    if (buyCard(province, &state4) == -1)
        printf("buyCard(): PASS when player with 5 coins and 2 buy can NOT buy a province card (2 province cards available).\n");
    else
        printf("buyCard(): FAIL when player with 5 coins and 2 buy can NOT buy a province card (2 province cards available).\n");

    if (buyCard(province, &state5) == 0)
        printf("buyCard(): PASS after a player with 10 coins and 2 buys purchases a province card, he has %d coins and %d buy left.\n", state5.coins, state5.numBuys);
    else
        printf("buyCard(): FAIL after a player with 10 coins and 2 buys purchases a province card, he has %d coins and %d buy left.\n", state5.coins, state5.numBuys);

    if (buyCard(province, &state6) == 0 && state6.handCount[0]==6)
        printf("buyCard(): PASS after a player%d purchases a province card, he has %d cards in total. (He had 5 cards before this purchase)\n", state6.whoseTurn, state6.handCount[0]);
    else
        printf("buyCard(): FAIL after a player%d purchases a province card, he has %d cards in total. (He had 5 cards before this purchase)\n", state6.whoseTurn, state6.handCount[0]);

    if (buyCard(province, &state7) == 0 && state7.supplyCount[province]==1)
        printf("buyCard(): PASS after a player purchases a province card (2 province cards available), it has %d province card left.\n", state7.supplyCount[province]);
    else
        printf("buyCard(): FAIL after a player purchases a province card (2 province cards available), it has %d province card left.\n", state7.supplyCount[province]);

}

int main(int argc, char *argv[])
{
	testBuyCard();
	return 0;
}