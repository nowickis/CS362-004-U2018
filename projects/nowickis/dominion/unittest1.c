/*
 * Testing the compare function
 * int compare(const void* a, const void* b) {
 * if (*(int*)a > *(int*)b)
 *    return 1;
 *  if (*(int*)a < *(int*)b)
 *    return -1;
 *  return 0;
}
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {

	int a = 1;
	int b = 2;
	int d = 1;
	int c;
	
	c  = compare(&a, &b);
	if(c == -1){
		printf("PASS: less than operation\n");
	} else {
		printf("FAIL: less than operation\n"); 
	}

	c = compare(&b, &a);
	if(c == 1){
		printf("PASS: greater than operation\n");
	} else {
		printf("FAIL: greater than operation\n");
	}

	c = compare(&a, &d);
	if(c == 0){
		printf("PASS: equivalence\n");
	} else {
		printf("FAIL: equivalnece\n");
	}

	c = compare(&a, &a);
	if(c == 0){
		printf("PASS: self comparision\n");
	} else {
		printf("FAIL: self comparision\n");
	}

	int n, nn;
	
	c = compare(&n, &a);
	if(c == -1) {
		printf("PASS: less than comparision to null pointer\n");
	} else {
		printf("FAIL: less than comparision to null pointer\n");
	}

	c = compare(&a, &n);
	if(c == 1) {
		printf("PASS: greater than comparision to null pointer\n");
	} else {
		printf("FAIL: greater than comparision to null pointer\n");
	}

	c = compare(&n, &nn);
	if(c == 0) {
		printf("PASS: equivalence of null pointers\n");
	} else {
		printf("FAIL: equivalence of null pointers\n");
	}

	

	c = compare(&n, &n);
	if(c == 0) {
		printf("PASS: self comparision of null pointer\n");
	} else {
		printf("FAIL: self than comparision of null pointer\n");
	}

	//do some big ints too
	return 0;

}
