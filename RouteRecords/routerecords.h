#ifndef ROUTE_RECORDS_H
#include <stdio.h>
#define ROUTE_RECORDS_H
#define MAX_LENGTH 4

typedef struct RouteRecord
{
  char origin[4];
  char destination[4];
  char airline[3];
  int passCount[6];

} RouteRecord;

typedef enum SearchType { ROUTE, ORIGIN, DESTINATION, AIRLINE } SearchType;

RouteRecord *createRecords (FILE * fileIn);

int fillRecords (RouteRecord * r, FILE * fileIn);

int findAirlineRoute (RouteRecord * r, int length, const char *origin,
		      const char *destination, const char *airline,
		      int curIdx);

void searchRecords (RouteRecord * r, int length, const char *key1,
		    const char *key2, SearchType st);

void printMenu ();

void upperCase(char y[]);


#endif //ROUTE_RECORDS_H
