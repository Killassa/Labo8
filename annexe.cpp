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

#include <iostream> // cout, cin
#include <limits>   // numeric_limits

#include "annexe.h"

using namespace std;

//--------------------------------------------------------------------------------
void viderBuffer() {
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//--------------------------------------------------------------------------------
void pause(const string& message) {
   cout << message;
   viderBuffer();
}

//--------------------------------------------------------------------------------
void initRand() {
   static bool init;

   if (not init) {
      init = !init;
      srand((unsigned) time(nullptr));
   }
}
