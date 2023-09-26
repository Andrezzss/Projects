#include <stdio.h>
#include <stdlib.h>
#include "champion.h"

Champ *
createChampion ()
{
  Champ *champ = (Champ *) malloc (sizeof (Champ));
  if (champ == NULL)
    exit (EXIT_FAILURE);
  int number = (1 + rand () % 100);
  if (number <= 25)
    {
      champ->type = MAGE;
      champ->value = 5 + rand () % 4;
    }
  else if (number <= 50)
    {
      champ->type = SUPPORT;
      champ->value = 3 + rand () % 4;
    }
  else if ( number <= 75)
    {
      champ->type = TANK;
      champ->value = 1 + rand () % 8;
    }
    else 
    {
        champ->type = FIGHTER;
      champ->value = 1 + rand () % 4;
    }

  champ->next = NULL;
  return champ;
}

Champ *
removeChampion (Champ * head)
{
  if (head == NULL)
    return head;
  Champ *newHead = head->next;
  free (head);
  return newHead;
}

Champ *
addChampion (Champ * head, Champ * champ)
{
  if (head == NULL)
    return champ;
  if (champ == NULL)
    return head;
  if (champ->value > head->value)
    {
      champ->next = head;
      return champ;
    }
  Champ *prev = NULL;
  Champ *temp = head;
  while (temp != NULL && temp->value >= champ->value)
    {
      prev = temp;
      temp = temp->next;
    }
  champ->next = temp;
  prev->next = champ;
  return head;
}

int
getLength (Champ * head)
{
  int length = 0;
  while (head != NULL)
    {
      length++;
      head = head->next;
    }
  return length;
}

void
printChampion (Champ * champ)
{
  if (champ != NULL)
    {
      char type = 'M';
      if (champ->type == SUPPORT)
	type = 'S';
	 if (champ->type == FIGHTER)
	type = 'F';
      else if (champ->type == TANK)
	type = 'T';
      printf ("%c%d ", type, champ->value);
    }
}

void
printChampions (Champ * head)
{
  Champ *temp = head;
  while (temp != NULL)
    {
      printChampion (temp);
      temp = temp->next;
    }
}

Champ *buildChampionList (int n)
{
  Champ *head = NULL;
  for (int i = 0; i < n; ++i)
    {
      Champ *champ = createChampion ();
      head = addChampion (head, champ);
    }
  return head;
}


Champ *destroyChampions (Champ * head)
{
  do
    {
      head = removeChampion (head);
    }
  while (head != NULL);
  return NULL;
}
