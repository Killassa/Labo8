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

#include "annexe.h"

using namespace std;

/* -------------------------------------------------------------------------------
 *  Déclaration des fonctions internes
 * -----------------------------------------------------------------------------*/

/**
 *
 *
 * @tparam T
 * @param largeur
 */
template <typename T>
void afficherLimiteVert(T largeur);


/* -------------------------------------------------------------------------------
 *  Opérateurs
 * -----------------------------------------------------------------------------*/

//TODO Revoir l'algorithmie pour économiser la mémoire et être plus efficace
template <typename T>
ostream& operator<<(ostream& os, const Terrain<T>& terrain) {
   afficherLimiteVert<unsigned>(terrain._largeur + 2);

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
   afficherLimiteVert<unsigned>(terrain._largeur + 2);
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

template <typename T>
T Terrain<T>::nouvelObjet() {

   // Impossible de créer plus d'objets qu'il n'y a de cases
   assert(_objets.size() < _largeur * _hauteur);

   Coordonnee coordonnee;

   // Contrôle si la position de l'objet ne recouvre aucun autre objet
   do {
      // Générations de positions aléatoires dans les limites du terrain
      coordonnee._posX = nbreAleatoire(_largeur);
      coordonnee._posY = nbreAleatoire(_hauteur);

      // Pas de contrôle de recouvrement s'il y a moins de 2 objets
      if ((_objets).size() < 2) {break;}

   } while(any_of((_objets).cbegin(), (_objets).cend(),
                  [coordonnee](const T& elem){return coordonnee == elem.getCoordonnee();}));

   T objet(coordonnee);

   return objet;
}

template <typename T>
void Terrain<T>::deplacerObjets(unsigned distance) {
   unsigned positionInitiale = 0;

   for(T& objet : _objets) {
      if (objet.getEstDetruit()) continue;

      Coordonnee::Direction direction;
      bool estDeplacable;

      do {
         //Prend une direction parmi toutes les directions possibles
         direction = (Coordonnee::Direction)nbreAleatoire((int)Coordonnee::Direction::LEFT + 1);

         switch (direction) {
            case Coordonnee::Direction::UP:
               estDeplacable = objet.getCoordonnee().getPosY() - distance > positionInitiale;
               break;
            case Coordonnee::Direction::DOWN:
               estDeplacable = objet.getCoordonnee().getPosY() + distance < _hauteur;
               break;
            case Coordonnee::Direction::RIGHT:
               estDeplacable = objet.getCoordonnee().getPosX() + distance < _largeur;
               break;
            case Coordonnee::Direction::LEFT:
               estDeplacable = objet.getCoordonnee().getPosX() - distance > positionInitiale;
               break;
         }
      }while(!estDeplacable);

      objet.deplacer(direction, distance);

      //Destruction de l'objet précédemment présent
      for(T& aDetruire : _objets) {
         if (aDetruire.getEstDetruit() || aDetruire.getId() == objet.getId())
            continue;

         if (aDetruire.getCoordonnee() == objet.getCoordonnee()) {
            aDetruire.destruction();
            break;
         }
      }
   }
}

template <typename T>
void Terrain<T>::supprimerObjets() {
   auto it = remove_if(_objets.begin(), _objets.end(),
                       [](T objet) { return objet.getEstDetruit(); });
   _objets.erase(it, _objets.end());
}

template <typename T>
bool Terrain<T>::estTermine() {
   return _objets.size() == 1;
}


/* -------------------------------------------------------------------------------
 *  Définition des fonctions internes
 * -----------------------------------------------------------------------------*/

template <typename T>
void afficherLimiteVert(T largeur) {
   cout << setfill('-') << setw(largeur + 1) << '\n';
}

#endif //TERRAIN_DEF_H