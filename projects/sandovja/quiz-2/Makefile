
CFLAGS = -Wall -fpic -coverage -lm

testme: testme.c
	gcc -o testme testme.c $(CFLAGS)
	./testme 

run: testme
	./testme 

all: testme run clean

clean: 
	rm -f *.o *.gcno testme *.gcda

 


