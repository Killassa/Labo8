/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Nom du labo    : Labo 8 - Survivor
Auteur(s)      : Grégory Rey-Mermet, Cédric Rosat
Date creation  : 14.01.2022
Description    :
Remarque(s)    : -
Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/
#include <cstdlib>
#include <iostream>
#include <limits>

#include "annexe.h"

using namespace std;

void viderBuffer();

int main() {
   /* -------------------------------------------------------------------------------
    *  Initialisation des messages
    * -----------------------------------------------------------------------------*/
   //Message d'introduction du programme
   const string MSG_INTRO = "Ce programme permet de...";

   //Message de fin pour quitter le programme
   const string MSG_QUITTER          = "Presser ENTER pour quitter";

   /* -------------------------------------------------------------------------------
    *  Initialisation des variables
    * -----------------------------------------------------------------------------*/



   /* -------------------------------------------------------------------------------
    *  Introduction au programme
    * -----------------------------------------------------------------------------*/
      cout << MSG_INTRO << endl;


   /* -------------------------------------------------------------------------------
    *  Message de fin
    * -----------------------------------------------------------------------------*/
   pause(MSG_QUITTER);

   return EXIT_SUCCESS;
}

void viderBuffer() {
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
}