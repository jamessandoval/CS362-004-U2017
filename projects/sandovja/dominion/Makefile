# old CFLAGS - need this to complie on flip
CFLAGS = -Wall -fpic -coverage -lm

OPTIONS = -fprofile-arcs -ftest-coverage

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
runtests: testDrawCard
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

runassignmenttests: cardtests
	./unittest1 &> unittestresults.out
	./unittest2 >> unittestresults.out
	./unittest2 >> unittestresults.out
	./unittest4 >> unittestresults.out
	./cardtest1 >> unittestresults.out
	./cardtest2 &> unittestresults.out
	./cardtest3 >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

unittests: unittest1.c unittest2.c unittest3.c unittest4.c dominion.o rngs.o
	gcc $(OPTIONS) -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
	gcc $(OPTIONS) -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
	gcc $(OPTIONS) -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
	gcc $(OPTIONS) -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)

cardtests: cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o rngs.o
	gcc $(OPTIONS) -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
	gcc $(OPTIONS) -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
	gcc $(OPTIONS) -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
	gcc $(OPTIONS) -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)

randomtests: randomtestadventurer.c randomtestcard1.c randomtestcard2.c dominion.o rngs.o

	gcc $(OPTIONS) -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	gcc $(OPTIONS) -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)
	gcc $(OPTIONS) -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)
	./randomtestadventurer &> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	./randomtestcard1 &> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out
	./randomtestcard2 &> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out

# Sample tests
testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
	gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

# For testing random tests only, oncomment main all when ready for submission:
all: playdom player randomtests 	

# Main All
#all: playdom player testDrawCard testBuyCard badTestDrawCard testUpdateCoins

clean:
	rm -rf *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out *.dSYM testDrawCard testDrawCard.exe