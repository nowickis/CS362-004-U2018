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
	int handPos = 0;
  	int countBefore = game->handCount[player];
	int playedCardsBefore = game->playedCardCount;
	int * cardDiscardedAddress = &(game->hand[player][handPos]);
	
	//int c = callSmithy(handPos, player, game);
	int c = ce_smithy(game, handPos);
	int countAfter = game->handCount[player];
	int playedCardsAfter = game->playedCardCount;
	int * cardDiscardedNewAddress = &(game->playedCards[playedCardsAfter]);
	
	printf("refactored function results\n");
	if(c != 0){
		printf("FAIL: callSmithy failed\n");
	}

	if(countAfter - countBefore == 2){
		printf("PASS: 3 cards picked up, 1 card discarded\n");
	} else{
		printf("FAIL: picked up or discarded wrong amount of cards\n");
	}

	if(playedCardsAfter == playedCardsBefore + 1) {
		printf("PASS: playedCards increased by 1\n");
	} else	{
		printf("FAIL: playedCards did not increase by 1\n");
	}

	if(cardDiscardedAddress != cardDiscardedNewAddress){
		printf("PASS: 1 card removed from deck\n");
	} else {
		printf("FAIL: 1 card not removed from deck\n");
	}
	//test cardEffect version
	k = kingdomCards(adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy);
	game = newGame();
	randomSeed = rand();
	initializeGame(2, k, randomSeed, game);
	player = 0;
	handPos = 0;
  	countBefore = game->handCount[player];
	playedCardsBefore = game->playedCardCount;
	cardDiscardedAddress = &(game->hand[player][handPos]);
	int card = smithy;
	int choice1, choice2, choice3 = 0;
	int *bonus;
//	int c = callSmithy(handPos, player, game);
	c = cardEffect(card, choice1, choice2, choice3, game, handPos, bonus);
	countAfter = game->handCount[player];
	playedCardsAfter = game->playedCardCount;
	cardDiscardedNewAddress = &(game->playedCards[playedCardsAfter]);
	
	printf("cardEffect results\n");
	if(c != 0){
		printf("FAIL: callSmithy failed\n");
	}

	if(countAfter - countBefore == 2){
		printf("PASS: 3 cards picked up, 1 card discarded\n");
	} else{
		printf("FAIL: picked up or discarded wrong amount of cards\n");
	}

	if(playedCardsAfter == playedCardsBefore + 1) {
		printf("PASS: playedCards increased by 1\n");
	} else	{
		printf("FAIL: playedCards did not increase by 1\n");
	}

	if(cardDiscardedAddress != cardDiscardedNewAddress){
		printf("PASS: 1 card removed from deck\n");
	} else {
		printf("FAIL: 1 card not removed from deck\n");
	}

	return 0;

}
