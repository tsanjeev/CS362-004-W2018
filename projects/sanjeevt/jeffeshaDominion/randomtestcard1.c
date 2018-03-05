#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

//test card village + 1 card and + 2 actions
//$ gcc -o randomtestcard1 randomtestcard1.c rngs.c dominion.c

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
	int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    int testRun = 0;
    int playerChoice = 0;
	struct gameState G, testG;
	int card = 14; //village;
	int villageCard = 1;
	int addCards = 1;
	int usedCard = 1;
	int addActions = 2;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	printf(" ----- Random Card Test: Village -----\n");
	int testCardFails = 0;
	int testActionsFails = 0;
	int n;
	for (n = 0; n < 1000; n++)
	{
		numPlayers = rand() % (MAX_PLAYERS - 1) + 2;
		struct gameState G, testG;
		seed = rand() % 1000;
		initializeGame(numPlayers, k, seed, &G);
		memcpy(&testG, &G, sizeof(struct gameState));

    	printf("TEST ITERATION: %d\n", ++testRun);
    	int z;
    	for(z = 0; z < numPlayers; z++)
    	{
			printf("Player %d: Number of Cards Before Playing Village: %d\n",whoseTurn(&testG),numHandCards(&testG) + villageCard);
			cardEffect(card, playerChoice, playerChoice, playerChoice, &testG, 0, 0);
			printf("Player %d: Number of Cards After Playing Village: %d, Expected Number of Cards: %d\n", whoseTurn(&testG), numHandCards(&testG) + villageCard, G.handCount[G.whoseTurn] + addCards - usedCard + villageCard);
			if(!(myAssert(G.handCount[G.whoseTurn] + addCards - usedCard + villageCard == testG.handCount[testG.whoseTurn] + villageCard ,"Player Has Correct Number of Cards\n", "Player Has Incorrect Number of Cards\n")))
				testCardFails++;
			printf("Player %d: Number of Actions After Playing Village: %d, Expected Number: %d\n", whoseTurn(&testG), testG.numActions - villageCard, G.numActions + addActions - villageCard);
			if(!(myAssert(G.numActions + addActions - villageCard == testG.numActions - villageCard, "Player Has Correct Number of Actions\n", "Player Has Incorrect Number of Actions\n")))
				testActionsFails++;
			endTurn(&testG);
		}
	}
	printf("Village Card Random Test\n");
	printf("# of Test Runs: %d\n", testRun);
	printf("Tests Failed With Incorrect Number of Cards: %d\n", testCardFails);
	printf("Tests Failed With Inccorrect Number of Actions: %d\n", testActionsFails);

}