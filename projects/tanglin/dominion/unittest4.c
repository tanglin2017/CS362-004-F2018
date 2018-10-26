/*********************************************
** File: unittest4.c
** Author: Lingli Tang
** Date: 10/25/2018
** Descriptions: this program test function getCost.
*********************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


void testGetCost()
{
	
	
	if (getCost(0) == 0)
        printf("getCost(): PASS when the cost of curse card is 0 coin.\n");
    else
        printf("getCost(): FAIL when the cost of curse card is 0 coin.\n");

    if (getCost(1) == 2)
        printf("getCost(): PASS when the cost of estate card is 2 coins.\n");
    else
        printf("getCost(): FAIL when the cost of estate card is 2 coins.\n");

    if (getCost(2) == 5)
        printf("getCost(): PASS when the cost of duchy card is 5 coins.\n");
    else
        printf("getCost(): FAIL when the cost of duchy card is 5 coins.\n");

    if (getCost(3) == 8)
        printf("getCost(): PASS when the cost of province card is 8 coins.\n");
    else
        printf("getCost(): FAIL when the cost of province card is 8 coins.\n");

    if (getCost(4) == 0)
         printf("getCost(): PASS when the cost of copper card is 0 coin.\n");
    else
        printf("getCost(): FAIL when the cost of copper card is 0 coin.\n");

	if (getCost(5) == 3)
        printf("getCost(): PASS when the cost of silver card is 3 coins.\n");
    else
        printf("getCost(): FAIL when the cost of silver card is 3 coins.\n");
}

int main(int argc, char *argv[])
{
	testGetCost();
	return 0;
}