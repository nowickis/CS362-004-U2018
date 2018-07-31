/*int* kingdomCards(int k1, int k2, int k3, int k4, int k5, int k6, int k7,
		  int k8, int k9, int k10) {
  int* k = malloc(10 * sizeof(int));
  k[0] = k1;
  k[1] = k2;
  k[2] = k3;
  k[3] = k4;
  k[4] = k5;
  k[5] = k6;
  k[6] = k7;
  k[7] = k8;
  k[8] = k9;
  k[9] = k10;
  return k;
}
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <limits.h>
int main(){
	
	int *k = kingdomCards(1,2,3,4,5,6,7,8,9,10);
	int i = 0;	
	for(i = 0; i < 10; i++){
		if(k[i] != i+1){
			printf("FAIL: array of different values  not properly intialized\n");
			break;
		}
	}
	if(i==10){
		printf("PASS: array of different values initialized\n");
	}
	
	
	int *j = kingdomCards(1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
	i = 0;	
	for(i = 0; i < 10; i++){
		if(j[i] != 1){
			printf("FAIL: array of all same values not properly intialized\n");
			break;
		}
	}
	if(i==10){
		printf("PASS: array of all same values initialized\n");
	}
	
	
	int *l = kingdomCards(INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX);
	i = 0;
	for(i = 0; i < 10; i++){
		if(l[i] != INT_MAX){
			printf("FAIL: all int_max\n");
			break;
		}
	}
	if(i==10){
		printf("PASS: all int_max\n");
	}
	int *m = kingdomCards(INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN);
	i = 0;
	for(i = 0; i < 10; i++){
		if(m[i] != INT_MIN){
			printf("FAIL: all int_min\n");
			break;
		}
	}
	if(i==10){
		printf("PASS: all int_min\n");
	}
	
	struct gameState state;
	int kDeck = initializeGame(2, k, 2, &state);
	if(kDeck == 0){
		printf("PASS: game intialized with deck of unique cards\n");
	} else {
		printf("FAIL: game not initialized with deck of unique cards\n");
	}

	struct gameState state2;
	int jDeck = initializeGame(2, j, 2, &state2);
	if(jDeck == -1){
		printf("PASS: game not intialized with bad deck\n");
	} else {
		printf("FAIL: game initialized with bad deck\n");
	}
	
	return 0;

}
