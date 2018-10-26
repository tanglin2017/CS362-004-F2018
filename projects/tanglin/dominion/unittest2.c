/*********************************************
** File: unittest2.c
** Author: Lingli Tang
** Date: 10/25/2018
** Descriptions: this program test function supplyCount.
*********************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


void testSupplyCount()
{
	struct gameState state1;
	struct gameState state2;
	
	
	int duchy = 2;//duchy card, cost 5 coins
	
	 		
	state1.numBuys = 0;
	state1.coins = 5;

	state2.numBuys = 2;
	state2.coins = 5;
	state2.supplyCount[duchy]=2;

	
	
	if (supplyCount(duchy, &state1) == 0)
        printf("supplyCount(): PASS when number of duchy card is 0.\n");
    else
        printf("supplyCount(): FAIL when number of duchy card is 0.\n");

	if (supplyCount(duchy, &state2) == 2)
        printf("supplyCount(): PASS when number of duchy card is 2.\n");
    else
        printf("supplyCount(): FAIL when number of duchy card is 2.\n");

    
		
}

int main(int argc, char *argv[])
{
	testSupplyCount();
	return 0;
}