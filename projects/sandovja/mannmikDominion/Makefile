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

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

mytests: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
	./unittest1 &>unittestresult.out
	gcov -b -c unittest1.c >> unittestresult.out
	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
	./unittest2 >> unittestresult.out
	gcov -b -c unittest2.c >> unittestresult.out
	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
	./unittest3 >> unittestresult.out
	gcov -b -c unittest3.c >> unittestresult.out
	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
	./unittest4 >> unittestresult.out
	gcov -b -c unittest4.c >> unittestresult.out
	gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
	./cardtest1 >> unittestresult.out
	gcov -b -c cardtest1.c >> unittestresult.out
	gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
	./cardtest2 >> unittestresult.out
	gcov -b -c cardtest2.c >> unittestresult.out
	gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
	./cardtest3 >> unittestresult.out
	gcov -b -c cardtest3.c >> unittestresult.out
	gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
	./cardtest4 >> unittestresult.out
	gcov -b -c cardtest4.c >> unittestresult.out

refactored: playdom player
	gcc $(OPTIONS) -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	gcc $(OPTIONS) -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)
	gcc $(OPTIONS) -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)
	gcc $(OPTIONS) -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)
	gcc $(OPTIONS) -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
	gcc $(OPTIONS) -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
	gcc $(OPTIONS) -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)

randomtestcard1: randomtestcard1
	gcc -o random1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)
	./random1 &> randomtestcard1.out
	gcov -c -b randomtestcard1.c >> randomtestcard1.out

randomtestcard2: randomtestcard2
	 gcc -o random2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)
	 ./random2 &> randomtestcard2.out
	 gcov -c -b randomtestcard2.c >> randomtestcard2.out

randomtestadventurer: randomtestadventurer
	gcc -o randomAdventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
	./randomAdventurer &> randomtestadventurer.out
	gcov -c -b randomtestadventurer.c >> randomtestadventurer.out

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
