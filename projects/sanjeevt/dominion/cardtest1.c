#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//test card smithy

void myAssert(int boolean, char *msg1, char *msg2)
{
	if(boolean)
		printf("TEST PASSED: %s\n", msg1);
	else
		printf("TEST FAILED: %s\n", msg2);
}


int main()
{
	int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    int playerChoice = 0;
	struct gameState G, testG;
	int card = 13; //smithy;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	printf(" ----- Card Test 1: Smithy -----\n");
	printf("Number of Cards Before Playing Smithy: %d\n",numHandCards(&testG));
	cardEffect(card, playerChoice, playerChoice, playerChoice, &testG, 0, 0);
	printf("Number of Cards After Playing Smithy: %d, Expected Number of Cards: %d\n", numHandCards(&testG), G.handCount[G.whoseTurn] + 2);
	myAssert(G.handCount[G.whoseTurn] + 2 == testG.handCount[testG.whoseTurn], "Player has correct number of cards\n", "Player has incorrect number of cards\n");


}