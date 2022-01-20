/*
-----------------------------------------------------------------------------------
Nom du fichier  : main.cpp
Nom du labo     : Labo 8 - Survivor
Auteur(s)       : Grégory Rey-Mermet, Cédric Rosat
Date creation   : 14.01.2022

Description     : Ce programme simule des robots autonomes dans un espace donné.
                  L'utilisateur doit saisir la taille du terrain ainsi que le nombre
                  de robots qu'il souhaite y ajouter. Les robots sont ajoutés de
                  façon aléatoire. Lorsqu'il y a un recouvrement, l'un des robots
                  est détruits. La partie s'arrête quand il ne reste plus qu'un
                  seul robot.

Remarque(s)     : -

Modification(s) : -

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>   // EXIT_SUCCESS
#include <iostream>  // cout
#include <thread>    // this_thread::sleep_for(...)

#include "annexe.h"
#include "Robot.h"
#include "Terrain.h"

using namespace std;

int main() {
   /* -------------------------------------------------------------------------------
    *  Initialisation des messages
    * -----------------------------------------------------------------------------*/

   const string MSG_INTRO         = "Ce programme simule des robots autonomes dans "
                                   "un espace donne.\n\nL'utilisateur doit saisir "
                                   "la taille du terrain ainsi que le nombre de "
                                   "robots qu'il souhaite y ajouter.\nLes robots "
                                   "sont ajoutes de facon aleatoire. Lorsqu'il y a "
                                   "un recouvrement, l'un des robots est detruits.\n"
                                   "La partie s'arrete quand il ne reste plus qu'un "
                                   "seul robot.\n",
                MSG_LARGEUR       = "Entrez la largeur du terrain",
                MSG_HAUTEUR       = "Entrez la hauteur du terrain",
                MSG_NB_ROBOTS     = "Entrez le nombre de robots a ajouter",
                MSG_ERREUR_SAISIE = "/!\\ Saisie incorrecte ...\n",
                MSG_QUITTER       = "Partie terminee, pressez ENTER pour quitter";

   /* -------------------------------------------------------------------------------
    *  Initialisation des constantes
    * -----------------------------------------------------------------------------*/

   // Bornes dimensions terrain
   const unsigned MIN_TERRAIN = 10,
                  MAX_TERRAIN = 1000;

   // Bornes quantité robots
   const unsigned MIN_ROBOT = 1,
                  MAX_ROBOT = 9;

   // Délai entre 2 affichages du terrain
   const chrono::duration DELAIS_AFFICHAGE = 250ms;

   /* -------------------------------------------------------------------------------
    *  Message explicatif et saisie des données
    * -----------------------------------------------------------------------------*/

   cout << MSG_INTRO << endl;

   const unsigned LARGEUR     = saisir(MSG_LARGEUR, MIN_TERRAIN, MAX_TERRAIN,
                                       MSG_ERREUR_SAISIE),
                  HAUTEUR     = saisir(MSG_HAUTEUR, MIN_TERRAIN, MAX_TERRAIN,
                                       MSG_ERREUR_SAISIE),
                  NBRE_ROBOTS = saisir(MSG_NB_ROBOTS, MIN_ROBOT, MAX_ROBOT,
                                       MSG_ERREUR_SAISIE);

   /* -------------------------------------------------------------------------------
    *  Initialisation du terrain et des robots
    * -----------------------------------------------------------------------------*/

   Terrain<Robot> terrain(LARGEUR, HAUTEUR, NBRE_ROBOTS);

   // Initialise et ajoute les robots sur le terrain
   for (unsigned nbRobots = 0; nbRobots < NBRE_ROBOTS; ++nbRobots) {
      terrain.ajoutObjet(terrain.nouvelObjet());
   }

   cout << terrain << endl;

   /* -------------------------------------------------------------------------------
    *  Déroulement du jeu
    * -----------------------------------------------------------------------------*/

   // Boucle tant qu'il y a plus d'un robot
   while (not terrain.objetEstSeul()) {
      terrain.deplacerObjets();
      terrain.supprimerObjets();

      this_thread::sleep_for(DELAIS_AFFICHAGE);
      system("clear");

      cout << terrain << endl;
   }

   /* -------------------------------------------------------------------------------
    *  Fin de programme
    * -----------------------------------------------------------------------------*/

   pause(MSG_QUITTER);

   return EXIT_SUCCESS;
}