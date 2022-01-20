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

#include <ostream>      // Flux de sortie
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
   //Les directions de déplacement du robot
   enum class Direction {UP, DOWN, RIGHT, LEFT};

   /* -------------------------------------------------------------------------------
    *  Constructeurs et destructeur
    * -----------------------------------------------------------------------------*/

   /**
    * Constructeur par défaut (position par défaut à (0,0))
    */
   Robot();

   /**
    * Constructeur d'initialisation
    *
    * @param coordonnee Les coordonnées de création du robot
    */
   explicit Robot(const Coordonnee& coordonnee);

   /*
    * Constructeur de copie par défaut
    */
   Robot(const Robot& robot) = default;

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

   /**
    * Permet d'écrire la direction de déplacement du robot
    *
    * @param direction Direction de déplacement
    */
   void setDirection(const Direction& direction);

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
    * @param distance   Permet de définir la distance de déplacement
    */
   void deplacer(unsigned distance = 1);

   /**
    * Détruire un robot
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

   Coordonnee        _coordonnee; // Les coordonnées du Robot
   Direction         _direction;  // Direction de déplacement du robot
   bool              _estDetruit; // Indique si le robot est détruit ou non
   const  unsigned   _id;         // L'ID unique du robot

   static unsigned   _idSuivant;  // ID pour le robot suivant
};

#endif //ROBOT_H
