#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//test card council room +4 cards, +1 buy, everyone draws 1 card

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
	int card = 8; //council room
	int addCards = 4;
	int usedCard = 1;
	int oneCard = 1;

	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	printf(" ----- Card Test 3: Council Room -----\n");
	printf("Number of Cards Before Playing Council Room: %d\n",numHandCards(&testG));
	printf("Number of Cards of Opponent's Hand: %d\n", testG.handCount[1]);
	cardEffect(card, playerChoice, playerChoice, playerChoice, &testG, 0, 0);
	printf("Number of Cards After Playing Council Room: %d, Expected Number of Cards: %d\n", numHandCards(&testG), G.handCount[G.whoseTurn] + addCards - usedCard);
	myAssert(G.handCount[G.whoseTurn] + addCards - usedCard == testG.handCount[testG.whoseTurn], "Player has correct number of cards\n", "Player has incorrect number of cards\n");
	int extraBuy = 1;
	myAssert(testG.numBuys == G.numBuys + extraBuy, "Player has correct number of buys\n", "Player has incorrect number of buys\n");
	int i;
	for(i = 1; i < numPlayers; i++)
	{
		myAssert(testG.handCount[i] == G.handCount[i] + oneCard, "Other Players Gained 1 Card\n", "Other Players Did Not Gain 1 Card\n");
	}
	

}