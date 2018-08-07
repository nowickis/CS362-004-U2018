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
	int randomSeed = rand();
	int* k = kingdomCards(adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy);
	struct gameState* g = newGame();
	
	initializeGame(2, k, randomSeed, g);
	
	
	int deckCount = g->deckCount[0];
	int deckBeforeShuffle[deckCount];
	int deckAfterShuffle[deckCount];
  	int deckIndex;
  //	printf("Player %d's deck:\n", 0);
 // 	if(deckCount > 0) printf("#  Card\n");
  	for(deckIndex = 0; deckIndex < deckCount; deckIndex++) {
    		int card = g->deck[0][deckIndex];
		deckBeforeShuffle[deckIndex] = card;
    		char name[MAX_STRING_LENGTH];
    		cardNumToName(card, name);
    //		printf("%-2d %-13s\n", deckIndex, name);
  	}	
  //	printf("\n");
	
	int shuffled = shuffle(0, g);
	if(shuffled != 0){
		printf("FAIL: shuffle failed\n");
	}
	int deckCountAfterShuffled = g->deckCount[0];

	if(deckCount == deckCountAfterShuffled){
		printf("PASS: same amount of cards after shuffle\n");
	} else {
		printf("FAIL: different amount of cards after shuffle\n");
	}
		
	

	//check that cards are in different order
	for(deckIndex = 0; deckIndex < deckCount; deckIndex++) {
    		int card = g->deck[0][deckIndex];
		deckAfterShuffle[deckIndex] = card;
    		char name[MAX_STRING_LENGTH];
    		cardNumToName(card, name);
    //		printf("%-2d %-13s\n", deckIndex, name);
  	}
	int isShuffled = 1;
	for(deckIndex = 0; deckIndex < deckCount; deckIndex++){
		if(deckBeforeShuffle[deckIndex] != deckAfterShuffle[deckIndex]){
			isShuffled = 0;
			break;
		}
	}

	if(isShuffled == 0){
		printf("PASS: deck was shuffled\n");
	} else {
		printf("FAIL: deck was not shuffled\n");
	}

	//check that same cards are in deck
	
	for(deckIndex = 0; deckIndex < deckCount; deckIndex++) {
		int i = 0;
		for(i = 0; i < deckCount; i++){
			if(deckAfterShuffle[deckIndex] == deckBeforeShuffle[i]){
				deckBeforeShuffle[i] = -999;
				break;
			}
		}
	}
	int sameCardsAfter = 0;
	for(deckIndex = 0; deckIndex < deckCount; deckIndex++){
			if(deckBeforeShuffle[deckIndex] != -999){
				sameCardsAfter = -1;
				break;
			}
		}
	if(sameCardsAfter == 0){
		printf("PASS: deck contains same cards after shuffle\n");
	} else {
		printf("FAIL: deck contains different cards after shuffle\n");
	}

	int shuffleBadPlayer = shuffle(3, g);
	if(shuffleBadPlayer == -1){
		printf("PASS: shuffle caught bad player\n");
	} else {
		printf("FAIL: shuffle did not catch bad player\n");
	}
	
	
	return 0;	
}
