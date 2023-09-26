#include "routerecords.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

RouteRecord* createRecords (FILE * fileIn)
{
  char buffer[200];
  int count = 0;
  RouteRecord *newRecord = NULL;
  fgets (buffer, 100, fileIn);

  while (fgets (buffer, 100, fileIn) != NULL)
    {
      count = count + 1;
    }

  newRecord = (RouteRecord *) malloc (count * sizeof (RouteRecord));

  for (int i = 0; i < 6; i++)
    {
      for (int j = 0; j < count; j++)
	{
	  newRecord[j].passCount[i] = 0;
	}
    }

  rewind (fileIn);
  return newRecord;
}

int fillRecords (RouteRecord * r, FILE * fileIn)
{

  char origin[4];
  char destination[4];
  char airline[4];
  int month;
  int count = 0;
  int i = 1;
  int passCount;
  char buffer[100];
  char type[20];
  fgets (buffer, 100, fileIn);


  while (fgets (buffer, 100, fileIn) != NULL)
    {

      sscanf (buffer, "%d,%[^,],%[^,],%[^,],%[^,],%d", &month, origin,destination, airline, type, &passCount);

      if (strlen (airline) < 3)
	{
	  count = findAirlineRoute (r, i, origin, destination, airline, 0);

	  if (count == -1)
	    {
	      strcpy (r[i].origin, origin);
	      strcpy (r[i].destination, destination);
	      strcpy (r[i].airline, airline);
	      r[i].passCount[month - 1] = passCount;
	    }

	  else
	    {
	      r[count].passCount[month - 1] = passCount;
	    }
	  i++;
	}
    }
  return i;
}

int findAirlineRoute (RouteRecord * r, int length, const char *origin,const char *destination, const char *airline, int curIdx)
{
  if (curIdx == length)
    {
      return -1;
    }
  if (strcmp (r[curIdx].origin, origin) == 0
      && strcmp (r[curIdx].destination, destination) == 0
      && strcmp (r[curIdx].airline, airline) == 0)
    {

      return curIdx;
    }
  return findAirlineRoute (r, length, origin, destination, airline,
			   curIdx + 1);
}


void searchRecords (RouteRecord * r, int length, const char *key1,
	       const char *key2, SearchType st)
{
  int found = 0;
  int month[6] = { 0, 0, 0, 0, 0, 0 };
  int total = 0;
  int count = 0;

  for (int i = 0; i < length; i++)
    {

      if (st == ORIGIN)
	{

	  if (strcmp (r[i].origin, key1) == 0)
	    {
	      printf ("%s (%s-%s) ", r[i].airline, r[i].origin,
		      r[i].destination);

	      for (int j = 0; j < 6; j++)
		{
		  month[j] += r[i].passCount[j];
		  total += r[i].passCount[j];
		}

	      found++;
	    }
	}
      else if (st == DESTINATION)
	{

	  if (strcmp (r[i].destination, key1) == 0)
	    {
	      printf ("%s (%s-%s) ", r[i].airline, r[i].origin,
		      r[i].destination);

	      for (int j = 0; j < 6; j++)
		{
		  month[j] += r[i].passCount[j];
		  total += r[i].passCount[j];
		}
	      found++;
	    }
	}
      else if (st == AIRLINE)
	{

	  if (strcmp (r[i].airline, key1) == 0)
	    {
	      printf ("%s (%s-%s) ", r[i].airline, r[i].origin,
		      r[i].destination);

	      for (int j = 0; j < 6; j++)
		{
		  month[j] += r[i].passCount[j];
		  total += r[i].passCount[j];
		}
	      found++;
	    }
	}
      else
	{

	  if (strcmp (r[i].origin, key1) == 0
	      && (strcmp (r[i].destination, key2) == 0))
	    {
	      printf ("%s (%s-%s) ", r[i].airline, r[i].origin,
		      r[i].destination);

	      for (int j = 0; j < 6; j++)
		{
		  month[j] += r[i].passCount[j];
		  total += r[i].passCount[j];
		}
	      found++;
	    }
	}
    }

  printf ("\n%d matches were found.\n\n", found);

 
  printf ("Statistics\n");
  printf ("Total Passengers: %d\n", total);

  for (int k = 0; k < 6; k++)
    {
      printf ("Total Passengers in Month %d: %d\n", k + 1, month[k]);
    }
  printf ("\n\nAverage Passengers per Month: %.lf\n", total / 6.0);
}


void printMenu ()
{
  printf ("\n\n######### Airline Route Records Database MENU #########\n");
  printf ("1. Search by Route\n");
  printf ("2. Search by Origin Airport\n");
  printf ("3. Search by Destination Airport\n");
  printf ("4. Search by Airline\n");
  printf ("5. Quit\n");
  printf ("Enter your selection: ");
}


void upperCase (char y[])
{
  for (int u = 0; u < strlen (y); u++)
   {
     y[u] = toupper (y[u]);
    }
}
