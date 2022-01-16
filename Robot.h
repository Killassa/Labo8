/*
-------------------------------------------------------------------------------------
Nom du fichier  : Robot.h
Nom du labo     : Labo 8 - Survivor
Auteur(s)       : Grégory Rey-Mermet, Cédric Rosat
Date creation   : 14.01.2022

Description     : Cette classe permet de créer des robots en leur assignant une
                  position (x,y). Certains opérateurs ou fonctions permettent
                  d'interagir avec les robots.

Remarque(s)     : Chaque robot a son propre identifiant qui est unique. La
                  destruction du robot ne libère pas son ID.

Modification(s) : -

Compilateur     : Mingw-w64 g++ 11.2.0
-------------------------------------------------------------------------------------
*/

#ifndef ROBOT_H
#define ROBOT_H

#include <ostream>
#include "Coordonnee.h"

template <typename T>
class Terrain;

class Robot {
   /* -------------------------------------------------------------------------------
   *  Fonctions amies
   * -----------------------------------------------------------------------------*/

   template<typename T>
   friend std::ostream& operator<<(std::ostream& os, const Terrain<T>& terrain);

public:
   /* -------------------------------------------------------------------------------
   *  Constructeurs et destructeur
   * -----------------------------------------------------------------------------*/

   /**
    * Contructeur
    *
    * @param coordonnee     Les coordonnées de création du robot
    */
   Robot(const Coordonnee& coordonnee);

   /* -------------------------------------------------------------------------------
    *  Accesseurs
    * -----------------------------------------------------------------------------*/

   /**
    * Permet de lire les coordonnées du robot
    *
    * @return
    */
   Coordonnee getCoordonnee() const;

   /**
    * Permet de lire l'ID du robot
    *
    * @return
    */
   unsigned getId() const;

   /**
    * Permet de lire si le robot est détruit
    *
    * @return
    */
   bool getEstDetruit() const;

   /* -------------------------------------------------------------------------------
    *  Fonctions membres
    * -----------------------------------------------------------------------------*/

   //TODO Changer saut en distance
   /**
    * Permet de déplacer un robot dans une direction défini
    *
    * @param direction  Direction dans laquelle on veut déplacer le robot
    * @param saut       Permet de définir la distance de déplacement
    */
   void deplacer(Coordonnee::Direction direction, unsigned saut = 1);

   /**
    * Detruire un robot
    */
   void destruction();


private:
   /* -------------------------------------------------------------------------------
    *  Données membres
    * -----------------------------------------------------------------------------*/

   //TODO Direction est une propriété de robot plutôt que coordonnée?

   // Directions de déplacement d'un robot
   enum class Directions {UP, DOWN, RIGHT, LEFT} _direction;

   Coordonnee      _coordonnee;
   const unsigned  _id;
   static unsigned _idSuivant;
   bool            _estDetruit;
};

#endif //ROBOT_H
