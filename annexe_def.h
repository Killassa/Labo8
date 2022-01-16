/*
-------------------------------------------------------------------------------------
Nom du fichier  : annexe_def.h
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
#ifndef ANNEXE_DEF_H
#define ANNEXE_DEF_H

#include <iostream> //cout, cin
#include <limits>   //numeric_limits
#include <cassert>  //assert

#include "annexe.h"

void verifierSaisie(bool erreur, const std::string& msgErreur);

template <typename T>
T saisir(const std::string& msgSaisie, T min, T max, const std::string& msgErreur) {
   //Arrêt si min plus grand que max
   assert(min <= max);

   T saisie;
   bool erreur;

   do {
      std::cout << msgSaisie << " [" << min << ".." << max << "] :";
      std::cin >> saisie;

      //Vérifie si la valeur se situe dans les bornes
      erreur = std::cin.fail() || saisie < min || saisie > max;
      verifierSaisie(erreur, msgErreur);
   } while (erreur);

   return saisie;
}

#endif // ANNEXE_DEF_H