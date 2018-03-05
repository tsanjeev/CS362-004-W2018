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

cardtest1:
	gcc -o cardtest1 cardtest1.c -g rngs.c dominion.c $(CFLAGS)

cardtest2:
	gcc -o cardtest2 cardtest2.c -g rngs.c dominion.c $(CFLAGS)

cardtest3:
	gcc -o cardtest3 cardtest3.c -g rngs.c dominion.c $(CFLAGS)

cardtest4:
	gcc -o cardtest4 cardtest4.c -g rngs.c dominion.c $(CFLAGS)

unittest1:
	gcc -o unittest1 unittest1.c -g rngs.c dominion.c $(CFLAGS)

unittest2:
	gcc -o unittest2 unittest2.c -g rngs.c dominion.c $(CFLAGS)

unittest3:
	gcc -o unittest3 unittest3.c -g rngs.c dominion.c $(CFLAGS)

unittest4:
	gcc -o unittest4 unittest4.c -g rngs.c dominion.c $(CFLAGS)

unittestresults: cardtest1 cardtest2 cardtest3 cardtest4 unittest1 unittest2 unittest3 unittest4
	-./cardtest1 &> unittestresults.out
	-./cardtest2 >> unittestresults.out
	-./cardtest3 >> unittestresults.out
	-./cardtest4 >> unittestresults.out
	-./unittest1 >> unittestresults.out
	-./unittest2 >> unittestresults.out
	-./unittest3 >> unittestresults.out
	-./unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	gcov cardtest1.c dominion.c >> unittestresults.out
	gcov cardtest2.c dominion.c >> unittestresults.out
	gcov cardtest3.c dominion.c >> unittestresults.out
	gcov cardtest4.c dominion.c >> unittestresults.out
	gcov unittest1.c dominion.c >> unittestresults.out
	gcov unittest2.c dominion.c >> unittestresults.out
	gcov unittest3.c dominion.c >> unittestresults.out
	gcov unittest4.c dominion.c >> unittestresults.out

all: playdom player runtests unittestresults

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
