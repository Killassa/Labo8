/*
-----------------------------------------------------------------------------------
Nom du fichier  : Terrain_def.h
Nom du labo     : Labo 8 - Survivor
Auteur(s)       : Grégory Rey-Mermet, Cédric Rosat
Date creation   : 14.01.2022

Description     : Définit toutes les fonctions, opérateurs ou constructeurs
                  nécessaires pour interagir avec le terrain et les objets.

Remarque(s)     : -

Modification(s) : -

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/
#ifndef TERRAIN_DEF_H
#define TERRAIN_DEF_H

#include <string>   // Utilisation des strings
#include <iostream> // Flux de sortie et cout
#include <iomanip>  // setw() et setfill()

#include "annexe.h"

/* -------------------------------------------------------------------------------
 *  Déclaration des fonctions internes
 * -----------------------------------------------------------------------------*/

/**
 * Affiche la limite verticale du terrain
 *
 * @tparam T
 * @param largeur
 * @param caractere
 */
template <typename T>
void afficherLimiteVert(T largeur, char caractere = '-');

/* -------------------------------------------------------------------------------
 *  Opérateurs
 * -----------------------------------------------------------------------------*/

//TODO Revoir l'algorithmie pour économiser la mémoire et être plus efficace
template <typename T>
std::ostream& operator<<(std::ostream& os, const Terrain<T>& terrain) {
   afficherLimiteVert(terrain._largeur + 2U);

   for (unsigned ligne = 0; ligne < terrain._hauteur; ++ligne) {
      // String représentant une ligne sans objets
      std::string contenu(terrain._largeur, ' ');

      auto first = terrain._objets.cbegin();

      // Pour chaque ligne, chercher si une des position Y correspond à la ligne
      while((first = find_if(first, terrain._objets.cend(),
                             [ligne](const T& obj){return obj.getCoordonnee().getPosY() == ligne;}))
            != terrain._objets.cend()) {
         // Remplace les " " par l'ID du robot (len = nb de digits de l'ID)
         std::string id = std::to_string(first->_id);
         contenu.replace(first->getCoordonnee().getPosX(), id.length(), id);

         // Continue la recherche après l'occurrence en cours
         ++first;
      }
      // Affiche la ligne avec les bordures et les robots
      os << "|" << contenu << "|" << std::endl;
   }
   afficherLimiteVert(terrain._largeur + 2U);
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

//--------------------------------------------------------------------------------
template <typename T>
T Terrain<T>::nouvelObjet() {

   // Impossible de créer plus d'objets qu'il n'y a de cases
   assert(_objets.size() < _largeur * _hauteur);

   Coordonnee coord;

   // Contrôle si la position de l'objet ne recouvre aucun autre objet
   do {
      // Génération de positions aléatoires dans les limites du terrain
      coord = Coordonnee(nbreAleatoire(_largeur), nbreAleatoire(_hauteur));

      // Pas de contrôle de recouvrement s'il y a moins de 2 objets
      if ((_objets).size() < 2) {break;}

   } while(any_of((_objets).cbegin(), (_objets).cend(),
                  [coord](const T& obj){return coord == obj.getCoordonnee();}));

   T objet(coord);

   return objet;
}

//--------------------------------------------------------------------------------
template <typename T>
void Terrain<T>::deplacerObjets(unsigned distance) {
   unsigned posInitiale = 0;

   for(T& objet : _objets) {
      if (objet.getEstDetruit()) continue;

      Robot::Direction direction;
      bool estDeplacable;

      do {
         //Prend une direction parmi toutes les directions possibles
         direction = (Robot::Direction)
                      nbreAleatoire((int) Robot::Direction::LEFT + 1);

         switch (direction) {
            case Robot::Direction::UP:
               estDeplacable = objet.getCoordonnee().getPosY() -
                               distance > posInitiale;
               break;
            case Robot::Direction::DOWN:
               estDeplacable = objet.getCoordonnee().getPosY() +
                               distance < _hauteur;
               break;
            case Robot::Direction::RIGHT:
               estDeplacable = objet.getCoordonnee().getPosX() +
                               distance < _largeur;
               break;
            case Robot::Direction::LEFT:
               estDeplacable = objet.getCoordonnee().getPosX() -
                               distance > posInitiale;
               break;
         }
      }while(!estDeplacable);

      objet.deplacer(direction, distance);

      //Destruction de l'objet précédemment présent
      for(T& aDetruire : _objets) {
         if (aDetruire.getEstDetruit() or aDetruire.getId() == objet.getId())
            continue;

         if (aDetruire.getCoordonnee() == objet.getCoordonnee()) {
            aDetruire.destruction();
            break;
         }
      }
   }
}

//--------------------------------------------------------------------------------
template <typename T>
void Terrain<T>::supprimerObjets() {
   auto it = remove_if(_objets.begin(), _objets.end(),
                       [](T objet) { return objet.getEstDetruit(); });
   _objets.erase(it, _objets.end());
}

//--------------------------------------------------------------------------------
template <typename T>
bool Terrain<T>::estTermine() {
   return _objets.size() <= 1;

}

/* -------------------------------------------------------------------------------
 *  Définition des fonctions internes
 * -----------------------------------------------------------------------------*/

template <typename T>
void afficherLimiteVert(T largeur, char caractere) {
   std::cout << std::setfill(caractere) << std::setw((int) largeur + 1) << '\n';
}

//--------------------------------------------------------------------------------
template<>
void afficherLimiteVert(unsigned largeur, char caractere) {
   std::cout << std::setfill(caractere) << std::setw((int) largeur + 1) << '\n';
}

//--------------------------------------------------------------------------------

#endif //TERRAIN_DEF_H