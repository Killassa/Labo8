/*
-------------------------------------------------------------------------------------
Nom du fichier : Robot.h
Nom du labo    : Labo 8 - Survivor
Auteur(s)      : Grégory Rey-Mermet, Cédric Rosat
Date creation  : 14.01.2022
Description    : Ce fichier d'en-tête (.h) met à la disposition de l'utilisateur
                 diverses fonctions utiles permettant de gérer un robot
Remarque(s)    : -
Compilateur    : Mingw-w64 g++ 11.2.0
-------------------------------------------------------------------------------------
*/

#ifndef LABO8_ROBOT_H
#define LABO8_ROBOT_H

#include "Coordonnee.h"

class Robot {
public:
   /**
    * Contructeur
    *
    * @param coordonnee     Les coordonnées de création du robot
    */
   Robot(const Coordonnee& coordonnee);

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

   /**
    * Permet de déplacer un robot dans une direction défini
    *
    * @param direction  Direction dans laquelle on veut déplacer le robot
    */
   void deplacer(Coordonnee::Direction direction);

   /**
    * Detruire un robot
    */
   void destruction();


private:
   Coordonnee      coordonnee; //Position du robot
   static unsigned idSuivant;  //Prochain ID à utiliser pour qu'il soit toujours unique
   unsigned        id;         //ID du robot
   bool            estDetruit; //True : Le robot est détruit
                               //False : Le robot n'est pas détruit
};

#endif //LABO8_ROBOT_H
