#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

//gcc -o randomtestadventurer randomtestadventurer.c rngs.c dominion.c

//test card adventurer +2 treasure cards
 int myAssert(int boolean, char *msg1, char *msg2)
{
	if(boolean)
		printf("TEST PASSED: %s\n", msg1);
	else
		printf("TEST FAILED: %s\n", msg2);
	return boolean;
}

void printHand(int nCard, struct gameState *state)
{
	int i;
	for(i = 0; i < nCard; i++)
	{
		if(handCard(i, state) == copper)
			printf("%s\n", "Copper");
		else if(handCard(i, state) == gardens)
			printf("%s\n", "Gardens");
		else if(handCard(i, state) == estate)
			printf("%s\n", "Estate");
		else if(handCard(i, state) == silver)
			printf("%s\n", "Silver");
		else if(handCard(i, state) == village)
			printf("%s\n", "Village");
	}
}

void printDeck(int nDeck, int thisPlayer,  struct gameState *state)
{
	int k;
	for(k = 0; k < nDeck; k++)
	{
		if(state->deck[thisPlayer][k] == copper)
			printf("%s\n", "Copper");
		else if(state->deck[thisPlayer][k] == gardens)
			printf("%s\n", "Gardens");
		else if(state->deck[thisPlayer][k] == silver)
			printf("%s\n", "Silver");
		else if(state->deck[thisPlayer][k] == village)
			printf("%s\n", "Village");
		else if(state->deck[thisPlayer][k] == estate)
			printf("%s\n", "Estate");
	}
}

int numTreasureCards(int deck[])
{
	int numTreasure = 0;
	int i;
	for(i = 0; i < 5; i++)
	{
		if(deck[i] == copper || deck[i] == silver)
		{
			numTreasure++;
		}
	}
	if(numTreasure > 2)
		numTreasure = 2;
	return numTreasure;
}


int main()
{
	srand(time(NULL));
	int seed = 0;
    int numPlayers = 2;
    int thisPlayer = 0;
    int numTests = 100;
    int testRun = 0;
    int playerChoice = 0;
   	int testTwoFails = 0;
   	int testOneFails = 0;
	int card = 7; //adventurer;
	int usedCard = 1;
	int advenCard = 1;
    printf(" ----- Random Test: Adventurer -----\n\n");

    int n;
	for (n = 0; n < 1000; n++)
	{
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
		numPlayers = rand() % (MAX_PLAYERS - 1) + 2;
		struct gameState G, testG;
		seed = rand() % 1000;
		initializeGame(numPlayers, k, seed, &G);
		memcpy(&testG, &G, sizeof(struct gameState));

    	 printf("TEST ITERATION: %d\n", ++testRun);

	printf("TEST 1: DRAW 2 TREASURE CARDS\n");
	
	int numCards = numHandCards(&testG);
	int deckCount = testG.deckCount[thisPlayer];
	
	printf("NUMBER OF CARDS IN HAND BEFORE PLAYING ADVENTURER: %d\n", numCards + advenCard);
	printf("%s\n", "Adventurer");
	printHand(numCards, &testG);
	
	printf("\nNUMBER OF CARDS IN DECK: %d\n", deckCount);
	printDeck(deckCount, thisPlayer, &testG);

	cardEffect(card, playerChoice, playerChoice, playerChoice, &testG, 0, 0);
	numCards = numHandCards(&testG);
	printf("\nCARDS AFTER PLAYING ADVENTURER: %d, EXPECTED NUMBER: %d\n", numCards, G.handCount[G.whoseTurn] + 2);
	printHand(numCards, &testG);

	deckCount = testG.deckCount[thisPlayer];
	printf("\nCARDS IN DECK: %d\n", deckCount);
	printDeck(deckCount, thisPlayer, &testG);

	printf("\n");
	if(!(myAssert(G.handCount[G.whoseTurn] + 2 == testG.handCount[testG.whoseTurn], "Player has correct number of cards\n", "Player has incorrect number of cards\n")))
			testOneFails++;

	printf("TEST 2: RANDOM TREASURE CARDS IN DECK\n");
	memcpy(&testG, &G, sizeof(struct gameState));
	//int newDeck[] = {gold, estate, estate, estate, estate};

	//new random deck of copper/silver/gold/village cards
	int newDeck[5];
	int expectedCoins = 0;
	int z;
	for(z = 0; z < 5; z++)
	{
		int newCard = rand() % 4 + 1;
		//printf("%d\n", newCard);
		if(newCard == 1)
		{
			newDeck[z] = copper;
			expectedCoins += 1;
		}
		else if(newCard == 2)
		{
			newDeck[z] = silver;
			expectedCoins += 2;
		}

		else if(newCard == 3)
		{
			newDeck[z] = gardens;
		}
		else if(newCard == 4)
			newDeck[z]  = village;

	}

	numCards = numHandCards(&testG);
	deckCount = 5;
	testG.deckCount[thisPlayer] = deckCount;

	//SWAP NEW DECK
	int g;
	for(g = 0; g < deckCount; g++)
	{
		testG.deck[thisPlayer][g] = newDeck[g];
	}

	int expectedTreasure = numTreasureCards(newDeck);

	printf("HAND BEFORE PLAYING ADVENTURER: \n");
	printf("%s\n", "Adventurer");
	printHand(numCards, &testG);

	printf("\nDECK: \n");
	printDeck(deckCount, thisPlayer, &testG);

	cardEffect(card, playerChoice, playerChoice, playerChoice, &testG, 0, 0);
	numCards = numHandCards(&testG);
	printf("\nCARDS AFTER PLAYING ADVENTURER: %d, EXPECTED NUMBER: %d\n", numCards, G.handCount[G.whoseTurn] + expectedTreasure);
	printHand(numCards, &testG);

	deckCount = testG.deckCount[thisPlayer];
	printf("\nCARDS IN DECK: %d\n", deckCount);
	printDeck(deckCount, thisPlayer, &testG);
	printf("\n");
	if(!(myAssert(G.handCount[G.whoseTurn] + expectedTreasure == testG.handCount[testG.whoseTurn], "Player has correct number of cards\n", "Player has incorrect number of cards\n")))
			testTwoFails++;


  	}
	printf("Adventurer Random Test Results:\n");
	printf("# of Test Runs: %d\n", testRun);
	printf("Test 1 Failed: %d times\n", testOneFails);
	printf("Test 2 Failed: %d times\n", testTwoFails);

}