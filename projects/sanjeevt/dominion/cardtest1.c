#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    int playerChoice = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	printf(" ----- Card Test 1: Smithy -----\n");
	cardEffect(smithy, playerChoice, playerChoice, playerChoice, &testG, 0, 0);
	printf("Expected Number of Cards: %d, Result: %d\n", G.handCount[G.whoseTurn] + 3, testG.handCount[testG.whoseTurn]);


}