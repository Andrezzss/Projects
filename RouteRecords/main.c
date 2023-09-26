#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "routerecords.h"

int main (int argc, char *argv[])
{
  char key1[MAX_LENGTH];
  char key2[MAX_LENGTH];
  char x;
  SearchType type;
  int length;
  char input;
  RouteRecord *record = NULL;
  FILE *fileIn = NULL;

  fileIn = fopen ("data.csv", "r");
  if (fileIn == NULL)
    {
      printf ("ERROR: Could not open file");
      return -1;
    }

  record = createRecords (fileIn);
  length = fillRecords (record, fileIn);
  fclose (fileIn);

  while (input != 53)
    {

      printMenu ();
      scanf (" %c", &input);
      while ((x = getchar ()) != '\n' && x != EOF);


      if (input < 48 && input > 53)
	{
	  printf ("invalid choice\n");
	  printMenu ();
	  scanf (" %c", &input);
	  while ((x = getchar ()) != '\n' && x != EOF);

	}


      switch (input)
	{

	case 49:
	  type = ROUTE;

	  printf ("Enter origin: ");
	  fgets (key1, MAX_LENGTH, stdin);
	  key1[strcspn (key1, "\n")] = 0;
	  upperCase(key1);
	  while ((x = getchar ()) != '\n' && x != EOF);

	  printf ("Enter destination: ");
	  fgets (key2, MAX_LENGTH, stdin);
	  key2[strcspn (key2, "\n")] = 0;
	  upperCase(key2);
	  printf ("\nSearching by route...\n");
	  searchRecords (record, length, key1, key2, type);
	  break;

	case 50:
	  type = ORIGIN;

	  printf ("Enter origin: ");
	  fgets (key1, MAX_LENGTH, stdin);
	  key1[strcspn (key1, "\n")] = 0;
	  upperCase(key1);
	  printf ("\nSearching by origin...\n");
	  searchRecords (record, length, key1, key2, type);
	  break;

	case 51:
	  type = DESTINATION;

	  printf ("Enter the destination: ");
	  fgets (key1, MAX_LENGTH, stdin);
	  key1[strcspn (key1, "\n")] = 0;
	  upperCase(key1);
	  printf ("\nSearching by destination...\n");
	  searchRecords (record, length, key1, key2, type);
	  break;

	case 52:
	  type = AIRLINE;

	  printf ("Entere the airline: ");
	  fgets (key1, MAX_LENGTH, stdin);
	  key1[strcspn (key1, "\n")] = 0;
	  upperCase(key1);
	  printf ("\nSearching by airline...\n");
	  searchRecords (record, length, key1, key2, type);
	  break;

	case 53:

	  free (record);
	  printf ("Goodbye!\n");
	  break;
	}
    }
  return 0;
}
