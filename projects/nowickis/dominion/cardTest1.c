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
	struct gameState* game = newGame();
	int randomSeed = rand();
	initializeGame(2, k, randomSeed, g);

	int handBeforeSmithy[handCount];
	int handAfterSmithy[handCount*2]; //extra room to allow for bugs
	int handCount = game->handCount[player];
	int handIndex;
  	printf("Player %d's hand:\n", player);
  	if(handCount > 0) printf("#  Card\n");
  	for(handIndex = 0; handIndex < handCount; handIndex++) {
    		int card = game->hand[player][handIndex];
		handBeforeSmithy[handIndex] = card;
    		char name[MAX_STRING_LENGTH];
    		cardNumToName(card, name);
    		printf("%-2d %-13s\n", handIndex, name);
  	}
	  printf("\n");

	int c = callSmithy(0, game);
	if(c != 0){
		printf("FAIL: callSmithy failed\n");
	}
	for(handIndex = 0; handIndex < handCount; handIndex++) {
    		int card = game->hand[player][handIndex];
		handAfterSmithy[handIndex] = card;
    		char name[MAX_STRING_LENGTH];
    		cardNumToName(card, name);
    		printf("%-2d %-13s\n", handIndex, name);
  	}
	printf("\n");
	int i = 0;
	while(handBeforeSmithy[i] != NULL) {
		i++;
	}
	int j = 0;
	while(handBeforeSmithy[j] != NULL) {
		j++;
	}
	if(i+2 == j){
		printf("PASS: 3 cards picked up, 1 card discarded\n")
	} else{
		printf("FAIL: picked up or discarded wrong amount of cards\n");
	}




}
