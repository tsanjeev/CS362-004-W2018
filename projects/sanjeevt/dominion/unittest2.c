#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Testing whoseTurn(); check to see whose turn it is

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
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	initializeGame(numPlayers, k, seed, &G);
	memcpy(&testG, &G, sizeof(struct gameState));
	int player1 = whoseTurn(&testG);


	//Cycle through all players to test end turn function and check if correct players turn
	printf("-----TESTING WHOSETURN FUNCITON-----\n");
	printf("Number of Players: %d\n", testG.numPlayers);
	printf("Current Players Turn: Player %d\n", player1);
	printf("Player %d Turn Ends\n", player1);
	endTurn(&testG);

	int player2 = whoseTurn(&testG);
	printf("Current Players Turn: Player %d\n", player2);
	myAssert(player2 == player1+1, "NEXT PLAYER'S TURN", "TURN DID NOT END");
	printf("Player %d Turn Ends\n", player2);
	endTurn(&testG);

	int player3 = whoseTurn(&testG);
	printf("Current Players Turn: Player %d\n", player3);
	myAssert(((player3 == player2+1) && (player3 != player1)), "Player 1 Turn Ended, Player 2 Turn", "TURN DID NOT END" );
	printf("Player %d Turn Ends\n", player3);
	endTurn(&testG);

	int player4 = whoseTurn(&testG);
	printf("Current Players Turn: Player %d\n", player4);
	myAssert(player4 == player1, "Player 2 Turn Ended, Back To Player 0", "TURN DID NOT END" );

	
}