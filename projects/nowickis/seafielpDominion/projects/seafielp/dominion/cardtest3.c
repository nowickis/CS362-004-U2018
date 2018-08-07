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
	int handPos = 0;
	int player = 0;	
	int countBefore = game->handCount[player];
 	int handIndex;
	int handBefore[countBefore];
  	for(handIndex = 0; handIndex < countBefore; handIndex++) {
    		int card = game->hand[player][handIndex];
		handBefore[handIndex] = card;
  	}
//	printf("refactored funtion test\n");
	int actionsBefore = game->numActions;
	int playedCardsBefore = game->playedCardCount;
	int playerDeckCountBefore = game->deckCount[player];
	int great; // = callGreatHall(player, game, handPos);

/*	if(great != 0){
		printf("FAIL: callGreatHall failed\n");
	}*/

	int countAfter = game->handCount[player];

/*	if(countBefore  == countAfter) {
		printf("PASS: 1 card discarded, 1 card gained\n");
	} else	{
		printf("FAIL: card count before and after great hall differs\n");
	}*/

	int actionsAfter = game->numActions;
/*	if(actionsAfter - actionsBefore == 1) {
		printf("PASS: 1 action gained\n");
	} else	{
		printf("FAIL: 1 action not gained\n");
	}*/
	int playedCardsAfter = game->playedCardCount;
/*	if(playedCardsAfter == playedCardsBefore + 1) {
		printf("PASS: playedCards increased by 1\n");
	} else	{
		printf("FAIL: playedCards did not increase by 1\n");
	}*/
	
	int playerDeckCountAfter = game->deckCount[player];
/*	if(playerDeckCountAfter == playerDeckCountBefore - 1) {
		printf("PASS: player deck decreased by 1\n");
	} else	{
		printf("FAIL: player deck did not decrease by 1\n");
	}*/

	//test cardEffect
	k = kingdomCards(adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy);
	game = newGame();
	randomSeed = rand();
	initializeGame(2, k, randomSeed, game);
	handPos = 0;
	player = 0;	
	countBefore = game->handCount[player];
 	handIndex;
	handBefore[countBefore];
  	for(handIndex = 0; handIndex < countBefore; handIndex++) {
    		int card = game->hand[player][handIndex];
		handBefore[handIndex] = card;
  	}
	printf("cardEffect tests\n");
	actionsBefore = game->numActions;
	playedCardsBefore = game->playedCardCount;
	playerDeckCountBefore = game->deckCount[player];
	int choice1, choice2, choice3 = 0;
	handPos = 0;
	int *bonus;

	great = cardEffect(great_hall, choice1, choice2, choice3, game, handPos, bonus);


	if(great != 0){
		printf("FAIL: callGreatHall failed\n");
	}

	countAfter = game->handCount[player];

	if(countBefore  == countAfter) {
		printf("PASS: 1 card discarded, 1 card gained\n");
	} else	{
		printf("FAIL: card count before and after great hall differs\n");
	}

	actionsAfter = game->numActions;
	if(actionsAfter - actionsBefore == 1) {
		printf("PASS: 1 action gained\n");
	} else	{
		printf("FAIL: 1 action not gained\n");
	}
	playedCardsAfter = game->playedCardCount;
	if(playedCardsAfter == playedCardsBefore + 1) {
		printf("PASS: playedCards increased by 1\n");
	} else	{
		printf("FAIL: playedCards did not increase by 1\n");
	}
	
	playerDeckCountAfter = game->deckCount[player];
	if(playerDeckCountAfter == playerDeckCountBefore - 1) {
		printf("PASS: player deck decreased by 1\n");
	} else	{
		printf("FAIL: player deck did not decrease by 1\n");
	}
	return 0;
}
