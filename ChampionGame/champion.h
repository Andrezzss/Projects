
#ifndef CHAMPIONS_H
#define CHAMPIONS_H


typedef enum ChampType{ 
MAGE, SUPPORT, TANK ,FIGHTER
} ChampType;

typedef struct Champ
{
  ChampType type;
  int value;
  struct Champ *next;
} Champ;


Champ *createChampion ();
Champ *removeChampion (Champ * head);
Champ *addChampion (Champ * head, Champ * champ);
int getLength (Champ * head);
void printChampion (Champ * champ);
void printChampions (Champ * head);
Champ *buildChampionList (int n);
Champ *destroyChampions (Champ * champ);

#endif
