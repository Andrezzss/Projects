makesearch: main.o routeRecords.o

gcc main.o routeRecords.o -o makesearch

main.o: main.c routeRecords.h

gcc -c main.c

routeRecords.o: routeRecords.c routeRecords.h

gcc -c routeRecords.c

clean:
rm *.o makesearch

