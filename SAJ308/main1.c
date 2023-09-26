#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "champion.h"


void printEndingChampions(Champ* player1, Champ* player2) {
    printf ("\n====== GAME OVER =====\n");
    printf ("Player 1 ending champions: ");
    printChampions(player1); printf ("\n");
    printf ("Player 2 ending champions: ");
    printChampions(player2); printf ("\n");
}
bool isGameRunning(Champ* player1, Champ* player2){
    int length1 = getLength(player1);
    int length2 = getLength(player2);
    if (length1 == 0 && length2 == 0) {
        printEndingChampions(player1, player2);
        printf ("\nTIE -- both players ran out of champions..\n");
        return false;
    } else if (length1 == 0) {
        printEndingChampions(player1, player2);
        printf ("\nPlayer 1 ran out of champions. Player 2 wins.\n");
        return false;
    } else if (length2 == 0) {
        printEndingChampions(player1, player2);
        printf ("\nPlayer 2 ran out of champions. Player 1 wins.\n");
        return false;
    }

    return true;
}

int main(int argc, char const *argv[]){
    srand (time(NULL));
    if (argc != 2) {
        printf ("Error: Invalid number of command line arguments\n");
        exit (EXIT_SUCCESS);
    } else {
        int n = atoi(argv[1]);
        if (n > 0) {
            printf ("====== PLAYER 1 VS PLAYER 2 SHOWDOWN =====\n");
            Champ* player1 = buildChampionList(n);
            Champ* player2 = buildChampionList(n);


            int round = 0;
            while (true){
                printf ("\n----- Round %d -----\n", ++round);
                printf ("Player 1 (%d): ", getLength(player1));
                printChampion(player1);printChampions(player1); printf ("\n");
                printf ("Player 2 (%d): ", getLength(player2));
                printChampion(player2);printChampions(player2); printf ("\n");
                ChampType type1 = player1->type;
                ChampType type2 = player2->type;

                int value1 = player1->value;
                int value2 = player2->value;

                player1 = removeChampion(player1);
                player2 = removeChampion(player2);

                if (type1 == MAGE && type2 == MAGE) {
                    printf ("Player 1 is MAGE.\n");
                    printf ("Player 2 is MAGE.\n");
                    if (value1 > value2) {
                        printf ("Player 1(MAGE) wins and gains one champion.\n");
                        printf ("Player 2(MAGE)loses one next champion into the abyss.\n");
                        Champ* champ = createChampion();
                        player1 = addChampion(player1, champ);
                        player2 = removeChampion(player2);
                    } else if (value1 < value2) {
                         printf ("Player 1(MAGE) loses  and loses one champion.\n");
                        printf ("Player 2(MAGE) wins and gains one champion.\n");
                        Champ* champ = createChampion();
                        player1 = removeChampion(player1);
                        player2 = addChampion(player2, champ);
                    } else {
                        printf ("Nothing happens - no penalty or reward.\n");
                    
                    }
                } else if (type1 == SUPPORT && type2 == SUPPORT) {
                    printf ("Player 1 is SUPPORT.\n");
                    printf ("Player 2 is SUPPORT.\n");
                     printf ("Player 1(SUPPORT) loses one champion.\n");
                      printf ("Player 2(SUPPORT) loses one champion.\n");
                    player1 = removeChampion(player1);
                    player2 = removeChampion(player2);
                } else if (type1 == TANK && type2 == TANK) {
                    printf ("Both players TANK away.\n");
                } else if (type1 == FIGHTER && type2 == FIGHTER) {
                    printf ("Player 1 is FIGHTER.\n");
                    printf ("Player 2 is FIGHTER.\n");
                     printf ("Player 1(FIGHTER) gains one champion.\n");
                      printf ("Player 2(FIGHTER) gains one champion.\n");
                    Champ* champ = createChampion();
                    player2 = addChampion(player2, champ);
                    player1 = addChampion(player1, champ);
                
                } else if (type1 == MAGE && type2 == SUPPORT) {
                    printf ("Player 1 is MAGE\n");
                    printf("Player 2 is SUPPORT\n");
                    if (value1 == value2) {
                        printf ("Nothing happens - no penalty or reward.\n");
                    } else if (value1 > value2) {
                        printf ("Player 1(MAGE) wins and gains one champion.\n"); 
                        printf("Player 2(SUPPORT) loses two champions.\n");
                        Champ* champ = createChampion();
                        player1 = addChampion(player1, champ);
                        player2 = removeChampion(player2);
                        player2 = removeChampion(player2);
                    } else {
                        printf ("Player 1(MAGE) loses and loses one champion.\n"); 
                        printf("Player 2(SUPPORT) wins and gains two champions.\n");
                         Champ* champ = createChampion();
                        player1 = removeChampion(player1);
                        player2 = addChampion(player2,champ);
                        player2 = addChampion(player2,champ);
                    }
                } else if (type1 == SUPPORT && type2 == MAGE) {
                    printf ("Player 1 is SUPPORT\n");
                    printf( "Player 2 is MAGE\n");
                    if (value1 == value2) {
                        printf ("Nothing happens - no penalty or reward.\n");
                    } else if (value1 < value2) {
                        printf("Player 1(Support) loses and loses two champions\n");
                        printf ("Player 2(MAGE) wins and gains one champion.\n");
                        Champ* champ = createChampion();
                        player2 =addChampion(player2,champ);
                        player1 = removeChampion(player1);
                        player1 = removeChampion(player1);
                    } else {
                        printf("Player 1(Support) wins and gains two champions\n");
                        printf ("Player 2(MAGE) loses and loses one champion.\n");
                         Champ* champ = createChampion();
                        player2 = removeChampion(player2);
                        player1 = addChampion(player1,champ);
                        player1 = addChampion(player1,champ);
                    }
                } else if (type1 == MAGE && type2 == TANK) {
                    printf ("Player 1 is MAGE\n");
                    printf("Player is 2 TANK\n");
                    printf("Player 1(MAGE) wins and gains a champion\n");
                    printf("Player 2(TANK) loses and loses a champion\n");
                    Champ* champ = createChampion();
                    player2 = removeChampion(player2);
                    player1 = addChampion(player1,champ);
                } else if (type1 == TANK && type2 == MAGE) {
                    printf ("Player 1 is TANK\n");
                    printf("Player 2 is MAGE.\n");
                    printf ("Player 1(TANK) loes and loses one champion\n");
                    printf("iPlayer 2(MAGE) wins and gains a champion.\n");
                    Champ* champ = createChampion();
                    player2 = addChampion(player2, champ);
                    player1 = removeChampion(player1);
                } else if (type1 == SUPPORT && type2 == TANK) {
                    printf ("Player 1 is SUPPORT\n");
                    printf("Player 2 is TANK.\n");
                    printf("Player 1(SUPPORT) loses but gets no penalty\n");
                    printf ("Player 2(TANK) wins and gains one champion\n");
                    Champ* champ = createChampion();
                    player2 = addChampion(player2, champ);
                } else if (type1 == TANK && type2 == SUPPORT) {
                    printf ("Player 1 is TANK\n");
                    printf("Player 2 is SUPPORT.\n");
                    printf("Player 1(TANK) wins and gains one champion\n");
                    printf ("Player 2(SUPPORT) loses but gets no penalty\n");
                    Champ* champ = createChampion();
                    player1 = addChampion(player1, champ);
                }else if (type1 == FIGHTER && type2 == MAGE) {
                printf("Player 1 is FIGHTER\n");
                printf("Player 2 is MAGE\n");
                    if (value1 == value2) {
                        printf ("Nothing happens - no penalty or reward\n");
                    } else if (value1 > value2) {
                        printf ("Player 1(FIGHTER) wins but gets no reward\n");
                        printf("Player 2(MAGE) loses and loses one champion\n");
                        player2 = removeChampion(player2);
                    } else {
                        printf ("Player 1(FIGHTER) loses but gets no penalty\n");
                        printf("Player 2(MAGE) wins and gains one champion\n");
                         Champ* champ = createChampion();
                        player2 = addChampion(player2,champ);
                    }
                }else if (type1 == MAGE && type2 == FIGHTER) {
                    printf("Player 1 is MAGE\n");
                    printf("Player 2 is FIGHTER\n");
                
                    if (value1 == value2) {
                        printf ("Nothing happens - no penalty or reward.\n");
                    } else if (value1 < value2) {
                        printf ("Player 1(MAGE) loses and loses one champion\n");
                        printf("Player 2(FIGHTER) wins but gets no reward\n");
                        player1 = removeChampion(player1);
                    } else {
                        printf ("Player 1(MAGE) wins and gains one champion\n");
                        printf("Player 2(FIGHTER) loses but gets no penalty\n");
                         Champ* champ = createChampion();
                        player1 = addChampion(player1,champ);
                    }
                }else if( type1 == FIGHTER && type2 == SUPPORT ) {
                  printf("Player 1 is FIGHTER\n");
                  printf("Player 2 is SUPPORT\n");
                    if (value1 == value2) {
                        printf ("Nothing happens - no penalty or reward.\n");
                    } else if (value1 > value2) {
                        printf ("Player 1(FIGHTER) wins but gets no reward\n");
                        printf("Player 2(SUPPORT) loses and loses 1 champion\n");
                        player2 = removeChampion(player2);
                    } else {
                        printf ("Player 1(FIGHTER) loses but gets no penalty\n");
                        printf("Player 2(SUPPORT) wins and gains 1 champion\n");                       
                         Champ* champ = createChampion();
                        player2 = addChampion(player2,champ);
                    }
                }else if (type1 == SUPPORT && type2 == FIGHTER) {
                    printf("Player 1 is SUPPORT\n");
                    printf("Player 2 is FIGHTER\n");
                    if (value1 == value2) {
                        printf ("Nothing happens - no penalty or reward.\n");
                    } else if (value1 > value2) {
                         printf("Player 1(SUPPORT) wins but gets no reward\n");
                         printf("Player 2(FIGHTER) loses and loses one champion\n");
                        player2 = removeChampion(player2);
                    } else {
                         printf("Player 1(SUPPORT) loses but gets no penalty\n");
                         printf("Player 2(FIGHTER) wins and gains one champion\n");
                         Champ* champ = createChampion();
                        player2 = addChampion(player2,champ);  
                } 
                }else if( type1 == FIGHTER && type2 == TANK){
                    printf("Player 1 is FIGHTER\n");
                    printf("Player 2 is TANK\n");
                    printf("Player 1(FIGHTER) wins and gains one champion\n");
                    printf("Player 2(TANK) loses but gets no penalty\n");
                    Champ* champ = createChampion();
                    player1 = addChampion(player1,champ);
                }else if( type1 == TANK && type2 == FIGHTER){                    
                    printf("Player 1 is TANK\n");
                    printf("Player 2 is FIGHTER\n");
                    printf("Player 1(TANK) loses but gets no penalty\n");
                    printf("Player 2(FIGHTER) wins and gains one champion\n");
                     Champ* champ = createChampion();
                    player2 = addChampion(player2,champ);
                }
            if (!isGameRunning(player1, player2)) {
                    destroyChampions(player1);
                    destroyChampions(player2);
                    break;
                }
            }
        }
        
    }
    return 0;
    free;
}