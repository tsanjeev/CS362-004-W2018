#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//test card adventurer

void myAssert(int boolean, char *msg1, char *msg2)
{
	if(boolean)
		printf("TEST PASSED: %s\n", msg1);
	else
		printf("TEST FAILED: %s\n", msg2);
}

void printHand(int nCard, struct gameState *state)
{
	for(int i = 0; i < nCard; i++)
	{
		if(handCard(i, state) == copper)
			printf("%s\n", "Copper");
		else if(handCard(i, state) == gold)
			printf("%s\n", "Gold");
		else if(handCard(i, state) == estate)
			printf("%s\n", "Estate");
	}
}

void printDeck(int nDeck, int thisPlayer,  struct gameState *state)
{
	for(int k = 0; k < nDeck; k++)
	{
		if(state->deck[thisPlayer][k] == copper)
			printf("%s\n", "Copper");
		else if(state->deck[thisPlayer][k] == gold)
			printf("%s\n", "Gold");
		else if(state->deck[thisPlayer][k] == estate)
			printf("%s\n", "Estate");
	}
}

int main()
{
	int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    int playerChoice = 0;
	struct gameState G, testG;
	int card = 7; //adventurer;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));

	printf(" ----- Card Test 2: Adventurer -----\n");
	printf("TEST 1: DRAW 2 TREASURE CARDS\n");
	int numCards = numHandCards(&testG);
	int deckCount = testG.deckCount[thisPlayer];
	
	printf("NUMBER OF CARDS IN HAND BEFORE PLAYING ADVENTURER: %d\n", numCards);
	printHand(numCards, &testG);
	
	printf("NUMBER OF CARDS IN DECK: %d\n", deckCount);
	printDeck(deckCount, thisPlayer, &testG);

	cardEffect(card, playerChoice, playerChoice, playerChoice, &testG, 0, 0);
	numCards = numHandCards(&testG);
	printf("\nCARDS AFTER PLAYING ADVENTURER: %d, EXPECTED NUMBER: %d\n", numCards, G.handCount[G.whoseTurn] + 2);
	printHand(numCards, &testG);

	deckCount = testG.deckCount[thisPlayer];
	printf("\nCARDS IN DECK: %d\n", deckCount);
	printDeck(deckCount, thisPlayer, &testG);

	printf("\n");
	myAssert(G.handCount[G.whoseTurn] + 2 == testG.handCount[testG.whoseTurn], "Player has correct number of cards\n", "Player has incorrect number of cards\n");

	printf("TEST 2: 1 TREASURE CARD IN DECK\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	int newDeck[] = {gold, estate, estate, estate, estate};

	numCards = numHandCards(&testG);
	deckCount = 5;
	testG.deckCount[thisPlayer] = deckCount;

	//SWAP NEW DECK
	for(int g = 0; g < deckCount; g++)
	{
		testG.deck[thisPlayer][g] = newDeck[g];
	}

	printf("HAND BEFORE PLAYING ADVENTURER: \n");
	printHand(numCards, &testG);

	printf("\nDECK: \n");
	printDeck(deckCount, thisPlayer, &testG);

	cardEffect(card, playerChoice, playerChoice, playerChoice, &testG, 0, 0);
	numCards = numHandCards(&testG);
	printf("\nCARDS AFTER PLAYING ADVENTURER: %d, EXPECTED NUMBER: %d\n", numCards, G.handCount[G.whoseTurn] + 1);
	printHand(numCards, &testG);

	deckCount = testG.deckCount[thisPlayer];
	printf("\nCARDS IN DECK: %d\n", deckCount);
	printDeck(deckCount, thisPlayer, &testG);
	printf("\n");
	myAssert(G.handCount[G.whoseTurn] + 1 == testG.handCount[testG.whoseTurn], "Player has correct number of cards\n", "Player has incorrect number of cards\n");


}