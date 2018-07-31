#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"
#include <limits.h>
int main(){
	int randomSeed = rand();
	int* k = kingdomCards(adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy);
	struct gameState* g = newGame();
	
	int tooFewPlayers = initializeGame(1, k, randomSeed, g); 
	if(tooFewPlayers == -1){
		printf("PASS: did not initialize game with too few players\n");	
	} else {
		printf("FAIL: initialized game with too few players\n");
	}

	int twoPlayers = initializeGame(2, k, randomSeed, g);
	int numPlayers = g->numPlayers;
	if(twoPlayers == 0 && numPlayers == 2){
		printf("PASS: initialized game with 2 players\n");	
	} else {
		printf("FAIL: initialized game with 2 players\n");
	}

	int tooManyPlayers = initializeGame(MAX_PLAYERS+1, k, randomSeed, g); 
	if(tooManyPlayers == -1){
		printf("PASS: did not initialize game with too many players\n");	
	} else {
		printf("FAIL: initialized game with too many players\n");
	}

	initializeGame(2, k, randomSeed, g);
	if(g->supplyCount[curse] == 10 && g->supplyCount[estate] == 8 && g->supplyCount[duchy] == 8 &&  g->supplyCount[province] == 8 &&
		g->supplyCount[copper] == 46 && g->supplyCount[silver] == 40 && g->supplyCount[gold] == 30) {
		printf("PASS: basic supplies for 2 players\n");
	} else{
		printf("FAIL: basic supplies for 2 players\n");
	}
	int i = adventurer;	
	for(i = adventurer; i <= treasure_map; i++){
		if(g->supplyCount[i] != 8 && g->supplyCount[i] != 10 && g->supplyCount[i] != -1){
			printf("FAIL: wrong kingdom card count for 2 players\n");
			break;
		}
	}
	if(i == treasure_map + 1){
		printf("PASS: right kingdom card count for 2 players\n");
	}
	
	initializeGame(3, k, randomSeed, g);

	if(g->outpostPlayed == 0 && g->phase == 0 &&  g->numActions == 1 &&  g->numBuys == 1 && g->playedCardCount == 0 &&
		g->whoseTurn == 0 && g->handCount[g->whoseTurn] == 5) {
		printf("PASS: set up first player's turn in 3 player game\n");
	} else {
		printf("FAIL: set up first player's turn in 3 player game\n");
		printf("%i\n", g->outpostPlayed);
		printf("%i\n", g->phase);
		printf("%i\n", g->numActions);
		printf("%i\n", g->numBuys);
		printf("%i\n", g->playedCardCount);
		printf("%i\n", g->whoseTurn);
		printf("%i\n", g->handCount[g->whoseTurn]);
	}
	return 0;


}
