/*
-------------------------------------------------------------------------------------
Nom du fichier  : annexe_def.h
Nom du labo     : Labo 8 - Survivor
Auteur(s)       : Grégory Rey-Mermet, Cédric Rosat
Date creation   : 14.01.2022

Description     : Implémentation des fonctions génériques.

Remarque(s)     : -

Modification(s) : -

Compilateur     : Mingw-w64 g++ 11.2.0
-------------------------------------------------------------------------------------
*/
#ifndef ANNEXE_DEF_H
#define ANNEXE_DEF_H

#include <iostream> // cout, cin
#include <cassert>  // assert

//--------------------------------------------------------------------------------
template <typename T>
T saisir(const std::string& msgSaisie, T min, T max, const std::string& msgErreur) {
   //Arrêt si min plus grand que max
   assert(min <= max);

   T saisie;
   bool erreurSaisie;
   do {
      std::cout << msgSaisie << " [" << min << ".." << max << "] :";
      std::cin >> saisie;

      //Vérifie si le flux est en ordre et si la valeur se situe dans les bornes
      erreurSaisie = std::cin.fail() or saisie < min or saisie > max;
      if (erreurSaisie) {
         std::cout << msgErreur;
         std::cin.clear();
      }

      viderBuffer();

   } while (erreurSaisie);

   return saisie;
}

//--------------------------------------------------------------------------------
template <typename T>
T nbreAleatoire(T borneSup) {
   return T(rand() % ((int) borneSup + 1));
}

#endif // ANNEXE_DEF_H