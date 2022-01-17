/*
-----------------------------------------------------------------------------------
Nom du fichier  : main.cpp
Nom du labo     : Labo 8 - Survivor
Auteur(s)       : Grégory Rey-Mermet, Cédric Rosat
Date creation   : 14.01.2022

Description     :

Remarque(s)     : -

Modification(s) : -

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/
#include <cstdlib>
#include <iostream>

#include "annexe.h"
#include "Robot.h"
#include "Survivor.h"
#include "Terrain.h"

using namespace std;

int main() {
   /* -------------------------------------------------------------------------------
    *  Initialisation des messages
    * -----------------------------------------------------------------------------*/

   //Message d'introduction du programme
   const string MSG_INTRO = "Ce programme permet de simuler le mouvement d'un nombre\n"
                            "de robots donnes dans un espace defini par l'utilisateur.\n"
                            "Les robots sont disposes de maniere aleatoire et se\n"
                            "deplace sur la grille, lorsque 2 robots se rencontre\n"
                            "le dernier arrive detruit l'autre et le jeu s'arrete\n"
                            "lorsqu'il ne reste qu'un seul robot.";

   //Message pour la largeur du terrain
   const string MSG_LARGEUR = "largeur";

   //Message pour la hauteur du terrain
   const string MSG_HAUTEUR = "hauteur";

   //Message pour le nombre d'objets'
   const string MSG_OBJET = "nbre object";

   //Message d'erreur
   const string MSG_ERREUR_SAISIE    = "/!\\ Saisie incorrecte ...\n"s;

   //Message de fin pour quitter le programme
   const string MSG_QUITTER          = "Presser ENTER pour quitter";

   /* -------------------------------------------------------------------------------
    *  Initialisation des variables
    * -----------------------------------------------------------------------------*/
   const unsigned MIN_TERRAIN = 10;    //Valeur minimale pour les dimensions du terrain
   const unsigned MAX_TERRAIN = 1000;  //valeur maximale pour les dimensions du terrain
   const unsigned MIN_ROBOT   = 1;     //Nombre minimal d'objets
   const unsigned MAX_ROBOT   = 9;     //Nombre maximal d'objets


   /* -------------------------------------------------------------------------------
    *  Introduction au programme
    * -----------------------------------------------------------------------------*/

   cout << MSG_INTRO << endl;

   // Saisie des diverses valeurs
   const unsigned LARGEUR     = saisir(MSG_LARGEUR, MIN_TERRAIN, MAX_TERRAIN,
                                       MSG_ERREUR_SAISIE);
   const unsigned HAUTEUR     = saisir(MSG_HAUTEUR, MIN_TERRAIN, MAX_TERRAIN,
                                       MSG_ERREUR_SAISIE);
   const unsigned NBRE_OBJETS = saisir(MSG_OBJET, MIN_ROBOT, MAX_ROBOT,
                                       MSG_ERREUR_SAISIE);

   // Initialisation de la seed random
   initRand();

   // Initialisation du terrain
   Terrain<Robot> terrain(LARGEUR, HAUTEUR);

   for (unsigned nbObjets = 0; nbObjets < NBRE_OBJETS; ++nbObjets) {
      terrain.ajoutObjet(nouvelObjet(terrain));
   }

   cout << terrain << endl;

   /* -------------------------------------------------------------------------------
    *  Message de fin
    * -----------------------------------------------------------------------------*/
   pause(MSG_QUITTER);

   return EXIT_SUCCESS;
}