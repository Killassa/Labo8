/*
-----------------------------------------------------------------------------------
Nom du fichier  : Survivor.cpp
Nom du labo     : Labo 8 - Survivor
Auteur(s)       : Grégory Rey-Mermet, Cédric Rosat
Date creation   : 15.01.2022

Description     : Ce fichier définit diverses fonctions utiles...

Remarque(s)     : -

Modification(s) : -

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <algorithm>
#include <cassert>
#include "Coordonnee.h"

#include "Robot.h"
using namespace std;

/* -------------------------------------------------------------------------------
 *  Déclaration des fonctions internes
 * -----------------------------------------------------------------------------*/

// Retourne un nombre aléatoire entre [0, borneSup[
template <typename T>
T nbreAleatoire(T borneSup) {
   return (T) rand() % borneSup;
}

/* -------------------------------------------------------------------------------
 *  Fonctions de la librairie
 * -----------------------------------------------------------------------------*/

// Créé un nouvel objet qui ne recouvre aucun des objets existant sur le terrain
template <typename T>
T nouvelObjet(const Terrain<T>& terrain) {

   // Impossible de créer plus d'objets qu'il n'y a de cases
   assert(terrain._objets.size() < terrain._largeur * terrain._hauteur);

   Coordonnee coordonnee;

   // Contrôle si la position de l'objet ne recouvre aucun autre objet
   do {
      // Générations de positions aléatoires dans les limites du terrain
      coordonnee._posX = nbreAleatoire(terrain._largeur);
      coordonnee._posY = nbreAleatoire(terrain._hauteur);

      // Pas de contrôle de recouvrement s'il y a moins de 2 objets
      if ((terrain._objets).size() < 2) {break;}

   } while(any_of((terrain._objets).cbegin(), (terrain._objets).cend(),
                  [coordonnee](const T& elem){return coordonnee == elem.getCoordonnee();}));

   T objet(coordonnee);

   return objet;
}

/* -------------------------------------------------------------------------------
 *  Définition des fonctions internes
 * -----------------------------------------------------------------------------*/
