#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//test card smithy +3 cards
//gcc -o randomtestcard2 randomtestcard2.c rngs.c dominion.c

int myAssert(int boolean, char *msg1, char *msg2)
{
	if(boolean)
		printf("TEST PASSED: %s\n", msg1);
	else
		printf("TEST FAILED: %s\n", msg2);
	return boolean;
}


int main()
{
	int seed = rand() % 1000;
    int thisPlayer = 0;
    int playerChoice = 0;

	struct gameState G, testG;
	int card = 13; //smithy
	int addCards = 3;
	int usedCard = 1;
	int smithyCard = 1;
	int testRun = 0;
	int testFails = 0;
	int numPlayers = rand() % (MAX_PLAYERS - 1) + 2;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));
	

	printf(" ----- Smithy Random Testing-----\n");

	int z;
	for(z = 0; z < 1000; z++)
	{
		printf("TEST ITERATION: %d\n", ++testRun);
	
		int j;
		for(j = 0; j < numPlayers; j++)
		{
			gainCard(card, &testG, 2, whoseTurn(&testG));
			printf("Player %d: Number of Cards Before Playing Smithy: %d\n", whoseTurn(&testG) ,numHandCards(&testG));
			cardEffect(card, playerChoice, playerChoice, playerChoice, &testG, 0, 0);
			printf("Player %d: Number of Cards After Playing Smithy: %d, Expected Number of Cards: %d\n", whoseTurn(&testG), numHandCards(&testG), G.handCount[G.whoseTurn] + addCards - usedCard + smithyCard);
			if(!(myAssert(G.handCount[G.whoseTurn] + addCards - usedCard + smithyCard == testG.handCount[testG.whoseTurn],"Player has correct number of cards\n", "Player has incorrect number of cards\n")))
			{
				testFails++;
			}
			endTurn(&testG);
		}
	}

	printf("Smithy Random Test\n");
	printf("# of Test Runs: %d\n", testRun);
	printf("Tests Failed With Incorrect Number of Cards: %d\n", testFails);

}