CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: unittestresults.out randomtestcard1.out randomtestcard2.out randomtestadventurer.out

unittestresults.out: cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.c rngs.c
	
	echo "cardtest1.c:" >> unittestresults.out
	gcc -o cardtest1 dominion.c rngs.c cardtest1.c $(CFLAGS)
	./cardtest1 >> unittestresults.out
	gcov dominion.c -f -b>> unittestresults.out

	echo "cardtest2.c:" >> unittestresults.out
	gcc -o cardtest2 dominion.c rngs.c cardtest2.c $(CFLAGS)
	./cardtest2 >> unittestresults.out
	gcov dominion.c -f -b>> unittestresults.out

	echo "cardtest3.c:" >> unittestresults.out
	gcc -o cardtest3 dominion.c rngs.c cardtest3.c $(CFLAGS)
	./cardtest3 >> unittestresults.out
	gcov dominion.c -f -b>> unittestresults.out

	echo "cardtest4.c:" >> unittestresults.out
	gcc -o cardtest4 dominion.c rngs.c cardtest4.c $(CFLAGS)
	./cardtest4 >> unittestresults.out
	gcov dominion.c -f -b>> unittestresults.out

randomtestcard1.out: randomtestcard1.c dominion.c rngs.c
	
	echo "Result for running random tests:" > randomtestcard1.out
	echo "randomtestcard1.c:" >> randomtestcard1.out
	gcc -o randomtestcard1 dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	./randomtestcard1 >> randomtestcard1.out
	gcov dominion.c -f -b>> randomtestcard1.out

randomtestcard2.out: randomtestcard2.c dominion.c rngs.c
	
	echo "Result for running random tests:" > randomtestcard2.out
	echo "randomtestcard2.c:" >> randomtestcard2.out
	gcc -o randomtestcard2 dominion.c rngs.c randomtestcard2.c $(CFLAGS)
	./randomtestcard2 >> randomtestcard2.out
	gcov dominion.c -f -b>> randomtestcard2.out

randomtestadventurer.out: randomtestadventurer.c dominion.c rngs.c
	
	echo "Result for running random tests:" > randomtestadventurer.out
	echo "randomtestadventurer.c:" >> randomtestadventurer.out
	gcc -o randomtestadventurer dominion.c rngs.c randomtestadventurer.c $(CFLAGS)
	./randomtestadventurer >> randomtestadventurer.out
	gcov dominion.c -f -b>> randomtestadventurer.out	


clean:
	rm unittestresults.out randomtestcard1.out randomtestcard2.out randomtestadventurer.out

cleanall: 
	rm unittestresults.out randomtestcard1.out randomtestcard2.out randomtestadventurer.out cardtest1 cardtest2 cardtest3 cardtest4 *.gcda *.gcno *.gcov

