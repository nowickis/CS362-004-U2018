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

	int handPos = 0;
	int countBefore = game->handCount[player];

	int mod = countBefore + 1;

	if(mod!=0){
		handPos = rand() % mod;
	}
 
  	int playedCardsBefore = game->playedCardCount;
	int * cardDiscardedAddress = &(game->hand[player][handPos]);
	
	int c = ce_smithy(game, handPos);//callSmithy(handPos, player, game);
	int countAfter = game->handCount[player];
	int playedCardsAfter = game->playedCardCount;
	int * cardDiscardedNewAddress = &(game->playedCards[playedCardsAfter]);
	
	
	if(c != 0){
		printf("FAIL: callSmithy failed\n");
	}

	if(countAfter - countBefore != 2){
		printf("FAIL: picked up or discarded wrong amount of cards\n");
	}

	if(playedCardsAfter != playedCardsBefore + 1) {
		printf("FAIL: playedCards did not increase by 1\n");
	}

	if(cardDiscardedAddress == cardDiscardedNewAddress){
		printf("FAIL: 1 card not removed from deck\n");
	}

}

	return 0;
}
