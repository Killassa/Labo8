/*
-----------------------------------------------------------------------------------
Nom du fichier  : Terrain_def.h
Nom du labo     : Labo 8 - Survivor
Auteur(s)       : Grégory Rey-Mermet, Cédric Rosat
Date creation   : 14.01.2022

Description     : Ce fichier définit diverses fonctions utiles...

Remarque(s)     : -

Modification(s) : -

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/
#ifndef TERRAIN_DEF_H
#define TERRAIN_DEF_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

/* -------------------------------------------------------------------------------
 *  Déclaration des fonctions internes
 * -----------------------------------------------------------------------------*/

// Génère la limite verticale (longueur du terrain + 2 limites horizontales)
template <typename T>
void afficherLimiteVert(T largeur);

/* -------------------------------------------------------------------------------
 *  Opérateurs
 * -----------------------------------------------------------------------------*/

//TODO Revoir l'algorithmie pour économiser la mémoire et être plus efficace
template <typename T>
ostream& operator<<(ostream& os, const Terrain<T>& terrain) {
   afficherLimiteVert<unsigned>(terrain._largeur);

   for (unsigned ligne = 0; ligne < terrain._hauteur; ++ligne) {
      // String représentant une ligne sans objets
      string contenu(terrain._largeur, ' ');

      auto first = terrain._objets.cbegin();

      // Pour chaque ligne, chercher si une des position Y correspond à la ligne
      while((first = find_if(first, terrain._objets.cend(),
                             [ligne](const T& obj){return obj.getCoordonnee().getPosY() == ligne;}))
            != terrain._objets.cend()) {
         // Remplace les " " par l'ID du robot (len = nb de digits de l'ID)
         string id = to_string(first->_id);
         contenu.replace(first->getCoordonnee().getPosX(), id.length(), id);

         // Continue la recherche après l'occurrence en cours
         ++first;
      }
      // Affiche la ligne avec les bordures et les robots
      os << "|" << contenu << "|" << endl;
   }
   afficherLimiteVert<unsigned>(terrain._largeur);
   return os;
}

/* -------------------------------------------------------------------------------
 *  Constructeurs
 * -----------------------------------------------------------------------------*/

template <typename T>
Terrain<T>::Terrain(unsigned largeur, unsigned hauteur)
   : _largeur(largeur), _hauteur(hauteur), _objets({}) {}

/* -------------------------------------------------------------------------------
 *  Fonctions membres
 * -----------------------------------------------------------------------------*/

template <typename T>
void Terrain<T>::ajoutObjet(const T& objet) {
   _objets.push_back(objet);
}

/* -------------------------------------------------------------------------------
 *  Définition des fonctions internes
 * -----------------------------------------------------------------------------*/

template <typename T>
void afficherLimiteVert(T largeur) {
   cout << setfill('-') << setw((int) largeur) << endl;
}

#endif //TERRAIN_DEF_H