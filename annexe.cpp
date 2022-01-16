/*
-------------------------------------------------------------------------------------
Nom du fichier  : annexe.cpp
Nom du labo     : Labo 8 - Survivor
Auteur(s)       : Grégory Rey-Mermet, Cédric Rosat
Date creation   : 14.01.2022

Description     : Ce fichier définit diverses fonctions utiles dont l'on pourrait
                  avoir besoin dans une multitude de projets différents.

Remarque(s)     : -

Modification(s) : -

Compilateur     : Mingw-w64 g++ 11.2.0
-------------------------------------------------------------------------------------
*/

#include <iostream> //cout, cin
#include <limits>   //numeric_limits
#include <cassert>  //assert

#include "annexe.h"

using namespace std;

void viderBuffer() {
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pause(const string& message) {
   cout << message;
   viderBuffer();
}

/**
 * Vérifie la saisie, si besoin répare le flux et affiche un message d'erreur
 *
 * @param erreur    Statut de l'erreur
 * @param msgErreur Message d'erreur
 */
void verifierSaisie(bool erreur, const string& msgErreur) {
   if (erreur) {
      cout << msgErreur;

      //Réparation du flux d'entrée cin
      cin.clear();
   }

   viderBuffer();
}

/**
 * Initialise la seed pour la fonction rand()
 */
void initRand() {
   static bool init;

   if (not init) {
      init = !init;
      srand((unsigned) time(nullptr));
   }
}
