/*********************************************
** File: unittest3.c
** Author: Lingli Tang
** Date: 10/25/2018
** Descriptions: this program test function whoseTurn.
*********************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


void testWhoseTurn()
{
	struct gameState state1;
	struct gameState state2;
	
	
	state1.whoseTurn = 1;	
	state2.whoseTurn = 2;
	
	
	
	if (whoseTurn(&state1) == 1)
        printf("whoseTurn(): PASS when it is player1's turn.\n");
    else
        printf("whoseTurn(): FAIL when it is player1's turn.\n");

	if (whoseTurn(&state2) == 2)
        printf("whoseTurn(): PASS when it is player2's turn.\n");
    else
        printf("whoseTurn(): FAIL when it is player2's turn.\n");

    
		
}

int main(int argc, char *argv[])
{
	testWhoseTurn();
	return 0;
}