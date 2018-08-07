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
	//test refactored function

	//random kingdom
	int *k1 = kingdomCards(great_hall, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy);
	int *k2 = kingdomCards(adventurer, council_room, feast, gardens, remodel, smithy, village, baron, great_hall, minion);
	int *k3 = kingdomCards(great_hall, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map);
	int * kingdoms[3];
	kingdoms[0] = k1;
	kingdoms[1] = k2;
	kingdoms[2] = k3;


	struct gameState* game = newGame();
	int n = 0;	
	for(n = 0; n < 2000; n++) {
	
	int randomPlayerCount = rand() % (4 + 1 -2) + 2;

	int player = rand() % (randomPlayerCount  - 0) + 0;
	int randomSeed = rand();

	int randomKingdom = rand()% (2 + 1-0) + 0;
			
	
	initializeGame(randomPlayerCount, kingdoms[randomKingdom], randomSeed, game);


	int countBefore = game->handCount[player];
	int mod = countBefore + 1;
	int handPos = 0;
	if(mod!=0){
		handPos = rand() % mod;
	}
 

	int actionsBefore = game->numActions;
	int playedCardsBefore = game->playedCardCount;
	
	int great = callGreatHall(player, game, handPos);

	if(great != 0){
		printf("FAIL: callGreatHall failed\n");
	}

	int countAfter = game->handCount[player];

	if(countBefore  != countAfter) {
		printf("FAIL: card count before and after great hall differs\n");
	}

	int actionsAfter = game->numActions;
	if(actionsAfter - actionsBefore != 1) {
		printf("FAIL: 1 action not gained\n");
	}
	int playedCardsAfter = game->playedCardCount;
	if(playedCardsAfter != playedCardsBefore + 1) {
		printf("FAIL: playedCards did not increase by 1\n");
	}
	
	


}
	
	
	return 0;
}

