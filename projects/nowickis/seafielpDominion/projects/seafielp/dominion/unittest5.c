#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"
#include <limits.h>
#include <string.h>
#include "interface.c"
#include <math.h>
int main(){
	int* k = kingdomCards(adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy);
	struct gameState* g = newGame();
	int randomSeed = rand();
	initializeGame(2, k, randomSeed, g);

	//game not over
	int notOver = isGameOver(g);
	if(notOver == 0 ){
		printf("PASS: game not over yet\n");
	} else {
		printf("FAIL: game not over yet\n");
	}

	int supplyCountMem = g->supplyCount[province];
	g->supplyCount[province] = 0;
	
	int overNoMoreSupplies = isGameOver(g);

	if(overNoMoreSupplies  == 1 ){
		printf("PASS: game over, no more supplies\n");
	} else {
		printf("FAIL: game should be over, no more supplies\n");
	}

	g->supplyCount[province] = supplyCountMem;
	assert(isGameOver(g) == 0);

	g->supplyCount[0] = 0;
	g->supplyCount[1] = 0;
	g->supplyCount[24] = 0;

	int threeSupplyCountsEmpty = isGameOver(g);
	if(threeSupplyCountsEmpty == 1){
		printf("PASS: game ended, three supply counts empty\n");
	} else {
		printf("FAIL: game should have ended, three supply counts empty\n");
	}
	g->supplyCount[2] = 0;
	int fourSupplyCountsEmpty = isGameOver(g);
	if(fourSupplyCountsEmpty == 1){
		printf("PASS: game ended, four supply counts empty\n");
	} else {
		printf("FAIL: game should have ended, four supply counts empty\n");
	}
	g->supplyCount[0] = 1;
	g->supplyCount[1] = 1;
	int twoSupplyCountsEmpty = isGameOver(g);
	if(twoSupplyCountsEmpty == 0){
		printf("PASS: game not ended, only two supply counts empty\n");
	} else {
		printf("FAIL: game should not have ended, only two supply counts empty\n");
	}

	g->supplyCount[2] = 1;
	g->supplyCount[24] = 1;
	int noSupplyCountsEmpty = isGameOver(g);
	if(noSupplyCountsEmpty == 0){
		printf("PASS: game not ended, no supply counts empty\n");
	} else {
		printf("FAIL: game should not have ended, no supply counts empty\n");
	}





	
	return 0;
	
}
