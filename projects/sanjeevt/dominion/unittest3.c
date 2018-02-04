#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Testing gainCard(); check to see if player adds card to hand

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
    char *cardName;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));
	int player1 = whoseTurn(&testG);


	//Cycle through all players to test end turn function and check if correct players turn
	printf("-----TESTING GAINCARD FUNCITON-----\n");
	int numCards = numHandCards(&testG);
	printf("Number of Cards in Hand: %d\n", numCards);
	printf("Cards in hand: \n");
	for(int i = 0; i < numCards; i++)
	{
		if(testG.hand[thisPlayer][i] == 4)
			cardName = "Copper";
		else if(testG.hand[thisPlayer][i] == 1)
			cardName = "Estate";
		printf("%d - %s\n", testG.hand[thisPlayer][i], cardName);
	}
	
	for (int i = 0; i < testG.handCount[thisPlayer]; i++){
    	testG.discard[thisPlayer][testG.discardCount[thisPlayer]++] = testG.hand[thisPlayer][i];//Discard
    	testG.hand[thisPlayer][i] = -1;//Set card to -1
  	}
  	printf("Discarding All Cards and Drawing 5 Cards");

  	testG.handCount[thisPlayer] = 0;//Reset hand count
  	numCards = numHandCards(&testG);
	printf("Number of Cards in Hand: %d\n", numCards);
	gainCard(province, &testG, 2, thisPlayer); //number 3
	gainCard(copper, &testG, 2, thisPlayer);	//number 4
	gainCard(gold, &testG, 2, thisPlayer);		//number 6
	gainCard(smithy, &testG, 2, thisPlayer);	//number 13
	gainCard(estate, &testG, 2, thisPlayer);	//number 1
	numCards = numHandCards(&testG);
	printf("Number of Cards in Hand: %d\n", numCards);
	myAssert(numCards == 5, "Correct Number of Cards Added", "Incorrect Number of Cards Added");
	printf("Cards in hand: \n");
	for(int i = 0; i < numCards; i++)
	{
		if(testG.hand[thisPlayer][i] == 4)
			cardName = "Copper";
		else if(testG.hand[thisPlayer][i] == 3)
			cardName = "Province";
		else if(testG.hand[thisPlayer][i] == 13)
			cardName = "Smithy";
		else if(testG.hand[thisPlayer][i] == 6)
			cardName = "Gold";
		else if(testG.hand[thisPlayer][i] == 1)
			cardName = "Estate";
		printf("%d - %s\n", testG.hand[thisPlayer][i], cardName);
	}
	myAssert(testG.hand[thisPlayer][0] == 3 &&
				testG.hand[thisPlayer][1] == 4 &&
				testG.hand[thisPlayer][2] == 6 &&
				testG.hand[thisPlayer][3] == 13 &&
				testG.hand[thisPlayer][4] == 1, "Correct Cards in Hand", "Incorrect Cards in Hand");
}