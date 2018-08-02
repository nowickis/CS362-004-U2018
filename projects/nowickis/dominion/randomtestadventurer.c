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
	int *k1 = kingdomCards(adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy);
	int *k2 = kingdomCards(adventurer, council_room, feast, gardens, remodel, smithy, village, baron, great_hall, minion);
	int *k3 = kingdomCards(adventurer, steward, tribute, ambassador, cutpurse, embargo, outpost, salvager, sea_hag, treasure_map);
	int * kingdoms[3];
	kingdoms[0] = k1;
	kingdoms[1] = k2;
	kingdoms[2] = k3;


	struct gameState* game = newGame();
	int temphand[MAX_HAND];
	int n = 0;	
	for(n = 0; n < 2000; n++) {
		
		int z = 0;
		int drawntreasure = 0;

		
		int randomSeed = rand();

		int randomKingdom = rand()% (2 + 1-0) + 0;
		int randomPlayerCount = rand() % (4 + 1 -2) + 2;
		int player = rand() % (randomPlayerCount  - 0) + 0;

	
		initializeGame(randomPlayerCount, kingdoms[randomKingdom], randomSeed, game);
		
		int countBefore = game->handCount[player];
 		int handIndex;
		int handBefore[countBefore];
  		for(handIndex = 0; handIndex < countBefore; handIndex++) {
    			int card = game->hand[player][handIndex];
			handBefore[handIndex] = card;
  		}
		

		int a = callAdventurer(drawntreasure, player, game, temphand, z);

	if(a != 0){
		printf("FAIL: adventurer did not work\n");	
	}

	int countAfter = game->handCount[player];

	if(countAfter>countBefore + 2) {
		printf("FAIL: player has too many cards after adventurer\n");
	}
	
	int handAfter[countAfter];
  	for(handIndex = 0; handIndex < countAfter; handIndex++) {
    		int card = game->hand[player][handIndex];
		handAfter[handIndex] = card;
   	}
  


	int i, j = 0;
	for(i = 0; i <  countAfter; i++){
		for(j = 0; j < countBefore; j++) {
			if(handAfter[i] == handBefore[j]){
				handBefore[j] = -999;
				handAfter[i] = -999;
				break;
			}
		}
	}
	int treasureGained = 0;
	for(i = 0; i < countAfter; i++) {
		if(handAfter[i] != -999 && ( handAfter[i] == copper || handAfter[i] == silver || handAfter[i] == gold)){
			treasureGained++;
		}
	}
	if(treasureGained != 2){
		printf("FAIL: 2 treasure not gained\n");
		printf("%i treasure was gained\n", treasureGained);
	}
	int treasureDiscarded = 0;
	for(i = 0; i < z; i++){
		if(temphand[z-1] == copper || temphand[z-1] == silver || temphand[z-1] == gold) {
				treasureDiscarded = 1;
				break;
		}
	}
	if(treasureDiscarded == 1) {
		printf("FAIL: incorrectly discarded treasure\n");

	}

}
	
	
	return 0;
}

