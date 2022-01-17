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
    * @return   Coordonnées du robot
    */
   Coordonnee getCoordonnee() const;

   /**
    * Permet de lire l'ID du robot
    *
    * @return   ID du robot
    */
   unsigned getId() const;

   /**
    * Permet de lire si le robot est détruit
    *
    * @return   Si le robot est détruit ou non
    */
   bool getEstDetruit() const;

   /* -------------------------------------------------------------------------------
    *  Fonctions membres
    * -----------------------------------------------------------------------------*/
   /**
    * Opérateur d'affectation par copie d'un robot
    *
    * @param robot  Robot à copier
    * @return       Robot actuel
    */
   Robot& operator=(const Robot& robot);

   /**
    * Permet de déplacer un robot dans une direction défini
    *
    * @param direction  Direction dans laquelle on veut déplacer le robot
    * @param distance       Permet de définir la distance de déplacement
    */
   void deplacer(Coordonnee::Direction direction, unsigned distance = 1);

   /**
    * Detruire un robot
    */
   void destruction();

   /**
    * Réparer un robot
    */
   void reparation();


private:
   /* -------------------------------------------------------------------------------
    *  Données membres
    * -----------------------------------------------------------------------------*/

   const  unsigned   _id;        //L'ID unique du robot
   static unsigned   _idSuivant; //ID pour le robot suivant
          Coordonnee _coordonnee;//Les coordonnées du Robot
          bool       _estDetruit;//Indique si le robot est détruit ou non
};

#endif //ROBOT_H
