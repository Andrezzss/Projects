makesearch: main.o champion.o

gcc main.o champion.o -o makesearch

main.o: main.c champion.h

gcc -c main.c

champion.o: champion.c champion.h

gcc -c champion.c

clean:
rm *.o makesearch

