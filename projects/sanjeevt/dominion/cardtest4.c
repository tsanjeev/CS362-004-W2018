#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//test card village + 1 card and + 2 actions

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
	int card = 14; //village;
	int villageCard = 1;
	int addCards = 1;
	int usedCard = 1;
	int addActions = 2;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	printf(" ----- Card Test 4: Village -----\n");
	printf("Number of Cards Before Playing Village: %d\n",numHandCards(&testG) + villageCard);
	cardEffect(card, playerChoice, playerChoice, playerChoice, &testG, 0, 0);
	printf("Number of Cards After Playing Village: %d, Expected Number of Cards: %d\n", numHandCards(&testG) + villageCard, G.handCount[G.whoseTurn] + addCards - usedCard + villageCard);
	myAssert(G.handCount[G.whoseTurn] + addCards - usedCard + villageCard == testG.handCount[testG.whoseTurn] + villageCard ,"Player Has Correct Number of Cards\n", "Player Has Incorrect Number of Cards\n");
	printf("Number of Actions After Playing Village: %d, Expected Number: %d\n", testG.numActions - villageCard, G.numActions + addActions - villageCard);
	myAssert(G.numActions + addActions - villageCard == testG.numActions - villageCard, "Player Has Correct Number of Actions\n", "Player Has Incorrect Number of Actions\n");


}