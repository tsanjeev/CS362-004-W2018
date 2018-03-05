#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Testing updateCoins() - update new coins

void myAssert(int boolean, char *msg1, char *msg2)
{
	if(boolean)
		printf("TEST PASSED: %s\n", msg1);
	else
		printf("TEST FAILED: %s\n", msg2);
}

int main(int argc, char const *argv[])
{
	int seed = 1000;
    int numPlayers = 3;
    int thisPlayer = 0;
	struct gameState G, testG;
	int playersCoins = 0;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));
	int player1 = whoseTurn(&testG);
	int currCoins = 0;

	//Cycle through all players to test end turn function and check if game is over
	printf("-----TESTING UPDATECOINS FUNCITON-----\n");
	playersCoins = testG.coins;
	currCoins = playersCoins;
	printf("Number of Coins: %d\n", playersCoins);
	gainCard(copper, &testG, 2, thisPlayer);
	updateCoins(thisPlayer, &testG, 0);
	int copper = 1;
	myAssert(currCoins + copper == 5, "Correct Number of Coins", "Incorrect Number of Coins");
	int silverCoin = 2;
	int goldCoin = 3;

	gainCard(silver, &testG, 2, thisPlayer);
	updateCoins(thisPlayer, &testG, 0);
	playersCoins = testG.coins;
	currCoins = playersCoins;
	printf("Number of Coins: %d\n", playersCoins);

	myAssert(currCoins  == 7, "Correct Number of Coins", "Incorrect Number of Coins");

	gainCard(gold, &testG, 2, thisPlayer);
	updateCoins(thisPlayer, &testG, 0);
	playersCoins = testG.coins;
	currCoins = playersCoins;
	printf("Number of Coins: %d\n", playersCoins);

	myAssert(currCoins  == 10, "Correct Number of Coins", "Incorrect Number of Coins");
	
}