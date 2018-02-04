#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//test card smithy + 3 cards

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
	int smithyCard = 1;
	int addCards = 3;
	int usedCard = 1;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	printf(" ----- Card Test 1: Smithy -----\n");
	printf("Number of Cards Before Playing Smithy: %d\n",numHandCards(&testG) + smithyCard);
	cardEffect(card, playerChoice, playerChoice, playerChoice, &testG, 0, 0);
	printf("Number of Cards After Playing Smithy: %d, Expected Number of Cards: %d\n", numHandCards(&testG) - smithyCard, G.handCount[G.whoseTurn] + addCards - usedCard + smithyCard);
	myAssert(G.handCount[G.whoseTurn] + addCards - usedCard + smithyCard == testG.handCount[testG.whoseTurn] - smithyCard ,"Player has correct number of cards\n", "Player has incorrect number of cards\n");


}