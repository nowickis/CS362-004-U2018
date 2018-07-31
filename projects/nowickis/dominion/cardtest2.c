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
	int* k = kingdomCards(adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy);
	struct gameState* game = newGame();
	int randomSeed = rand();
	initializeGame(2, k, randomSeed, game);
	
	int player = 0;
	int temphand[MAX_HAND];
	

	
	int z = 0;
	int drawntreasure = 0;
	int countBefore = game->handCount[player];
 	int handIndex;
	int handBefore[countBefore];
  	for(handIndex = 0; handIndex < countBefore; handIndex++) {
    		int card = game->hand[player][handIndex];
		handBefore[handIndex] = card;
  	}
	printf("refactored funtion test\n");
	int a = callAdventurer(drawntreasure, player, game, temphand, z);
	if(a == 0){
		printf("PASS: adventurer worked\n");
	} else	{
		printf("FAIL: adventurer did not work\n");	
	}

	int countAfter = game->handCount[player];

	if(countAfter-countBefore == 2) {
		printf("PASS: player picked up two cards\n");
	} else {
		printf("FAIL: player did not pick up two cards\n");
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
	if(treasureGained == 2){
		printf("PASS: 2 treasure gained\n");
	} else {
		printf("FAIL: 2 treasure not gained\n");
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

	} else {
		printf("PASS: no treaure discarded\n");

	}



	//cardeffect
	printf("cardEffect tests\n");
	k = kingdomCards(adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy);
	game = newGame();
	randomSeed = rand();
	initializeGame(2, k, randomSeed, game);
	
	player = 0;
	
	

	
	z = 0;
	drawntreasure = 0;
	countBefore = game->handCount[player];
 	
	
 	for(handIndex = 0; handIndex < countBefore; handIndex++) {
    		int card = game->hand[player][handIndex];
		handBefore[handIndex] = card;
  	}

  	int choice1, choice2, choice3 = 0;
	int handPos = 0;
	int *bonus;

	a = cardEffect(adventurer, choice1, choice2, choice3, game, handPos, bonus);
	if(a == 0){
		printf("PASS: adventurer worked\n");
	} else	{
		printf("FAIL: adventurer did not work\n");	
	}

	countAfter = game->handCount[player];

	if(countAfter-countBefore == 2) {
		printf("PASS: player picked up two cards\n");
	} else {
		printf("FAIL: player did not pick up two cards\n");
	}
	
 	for(handIndex = 0; handIndex < countAfter; handIndex++) {
    		int card = game->hand[player][handIndex];
		handAfter[handIndex] = card;
  	}


	i = 0;
	j = 0;
	for(i = 0; i <  countAfter; i++){
		for(j = 0; j < countBefore; j++) {
			if(handAfter[i] == handBefore[j]){
				handBefore[j] = -999;
				handAfter[i] = -999;
				break;
			}
		}
	}
	treasureGained = 0;
	for(i = 0; i < countAfter; i++) {
		if(handAfter[i] != -999 && ( handAfter[i] == copper || handAfter[i] == silver || handAfter[i] == gold)){
			treasureGained++;
		}
	}
	if(treasureGained == 2){
		printf("PASS: 2 treasure gained\n");
	} else {
		printf("FAIL: 2 treasure not gained\n");
	}
	treasureDiscarded = 0;
	for(i = 0; i < z; i++){
		if(temphand[z-1] == copper || temphand[z-1] == silver || temphand[z-1] == gold) {
				treasureDiscarded = 1;
				break;
		}
	}
	if(treasureDiscarded == 1) {
		printf("FAIL: incorrectly discarded treasure\n");

	} else {
		printf("PASS: no treaure discarded\n");

	}

	return 0;
}
