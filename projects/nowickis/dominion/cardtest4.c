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
 	
	printf("refactored funtion test\n");
	
	int choice1 = 1;
	int choice2 = 2;
	int choice3 = 3;
	int s = callSteward(choice1, choice2, choice3, player, game, handPos);

	if(s != 0){
		printf("FAIL: callSteward failed\n");
	}
	//choice 1
	int countAfter = game->handCount[player];
 	if(countAfter == countBefore + 1) {
		printf("PASS: choice1 = 1 took two cards and discarded one\n");
	} else {
		printf("FAIL: choice1 = 1 did not take two cards and discared one\n");
	}

	choice1 = 2;
	int coinCountBefore = game->coins;
	s = callSteward(choice1, choice2, choice3, player, game, handPos);
	int coinCountAfter = game->coins;
	if(coinCountAfter == coinCountBefore + 2) {
		printf("PASS: choice1 = 2 increased coins by 2\n");
	} else {
		printf("FAIL: choice1 = 2 did not increase coins by 2\n");
	}

	choice1 = 3;
	countBefore = game->handCount[player];
	s =  callSteward(choice1, choice2, choice3, player, game, handPos);
	countAfter = game->handCount[player];
  	if(countAfter == countBefore - 3) {
		printf("PASS: choice1 != 1 or 2 discarded 3 cards\n");
	} else {
		printf("FAIL: choice1 != 1 or  2 did not discard 3 cards\n");
	}


	//card effect
	k = kingdomCards(adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy);
	game = newGame();
	randomSeed = rand();
	initializeGame(2, k, randomSeed, game);
	handPos = 0;
	player = 0;	
	countBefore = game->handCount[player];
	
	 printf("cardEfect test\n");
	
	choice1 = 1;
	choice2 = 2;
	choice3 = 3;
	int *bonus;
	s = cardEffect(steward, choice1, choice2, choice3, game, handPos, bonus);

	if(s != 0){
		printf("FAIL: callSteward failed\n");
	}
	//choice 1
	countAfter = game->handCount[player];
 	if(countAfter == countBefore + 1) {
		printf("PASS: choice1 = 1 took two cards and discarded one\n");
	} else {
		printf("FAIL: choice1 = 1 did not take two cards and discared one\n");
	}

	choice1 = 2;
	coinCountBefore = game->coins;
	s = cardEffect(steward, choice1, choice2, choice3, game, handPos, bonus);
	coinCountAfter = game->coins;
	if(coinCountAfter == coinCountBefore + 2) {
		printf("PASS: choice1 = 2 increased coins by 2\n");
	} else {
		printf("FAIL: choice1 = 2 did not increase coins by 2\n");
	}

	choice1 = 3;
	countBefore = game->handCount[player];
	s = cardEffect(steward, choice1, choice2, choice3, game, handPos, bonus);
	countAfter = game->handCount[player];
  	if(countAfter == countBefore - 3) {
		printf("PASS: choice1 != 1 or 2 discarded 3 cards\n");
	} else {
		printf("FAIL: choice1 != 1 or  2 did not discard 3 cards\n");
	}
	return 0;
}
