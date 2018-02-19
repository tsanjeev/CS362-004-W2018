CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

randomtestadventurer:
	gcc -o randomtestadventurer randomtestadventurer.c -g rngs.c dominion.c $(CFLAGS)

randomtestcard1:
	gcc -o randomtestcard1 randomtestcard1.c -g rngs.c dominion.c $(CFLAGS)

randomtestcard2:
	gcc -o randomtestcard2 randomtestcard2.c -g rngs.c dominion.c $(CFLAGS)

runtests: randomtestadventurer randomtestcard1 randomtestcard2
	-./randomtestadventurer &> randomtestadventurer.out
	-./randomtestcard1 &> randomtestcard1.out
	-./randomtestcard2 &> randomtestcard2.out
	gcov randomtestadventurer dominion.c >> randomtestadventurer.out
	gcov randomtestcard1 dominion.c >> randomtestcard1.out
	gcov randomtestcard2 dominion.c >> randomtestcard2.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player runtests

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
