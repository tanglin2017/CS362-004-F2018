CFLAGS = -Wall -fpic -coverage -lm -std=c99

default: randomtestcard1.out randomtestcard2.out randomtestadventurer.out

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
	rm randomtestcard1.out randomtestcard2.out randomtestadventurer.out

cleanall: 
	rm randomtestcard1.out randomtestcard2.out randomtestadventurer.out randomtestcard1 randomtestcard2 randomtestadventurer *.gcda *.gcno *.gcov

