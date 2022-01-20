/*
-----------------------------------------------------------------------------------
Nom du fichier  : Robot.cpp
Nom du labo     : Labo 8 - Survivor
Auteur(s)       : Grégory Rey-Mermet, Cédric Rosat
Date creation   : 14.01.2022

Description     : Constructeurs, méthodes et accesseurs pour interagir avec un robot.

Remarque(s)     : -

Modification(s) : -

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include "Robot.h"

using namespace std;

/* -------------------------------------------------------------------------------
 *  Constructeurs et destructeur
 * -----------------------------------------------------------------------------*/

Robot::Robot() : Robot({0, 0}) {}

//--------------------------------------------------------------------------------
Robot::Robot(const Coordonnee& coordonnee) : _coordonnee(coordonnee),
_direction(Direction::UP), _estDetruit(false), _id(_idSuivant++) {}

/* -------------------------------------------------------------------------------
 *  Accesseurs
 * -----------------------------------------------------------------------------*/

Coordonnee Robot::getCoordonnee() const {
   return _coordonnee;
}

//--------------------------------------------------------------------------------
unsigned Robot::getId() const {
   return _id;
}

//--------------------------------------------------------------------------------
bool Robot::getEstDetruit() const {
   return _estDetruit;
}

void Robot::setDirection(const Direction& direction) {
   _direction = direction;
}

/* -------------------------------------------------------------------------------
 *  Fonctions membres
 * -----------------------------------------------------------------------------*/
Robot& Robot::operator=(const Robot& robot) {
   // Cast en non constant pour permettre le changement de valeur
   (unsigned &)_id = robot._id;

   _coordonnee = robot._coordonnee;
   _estDetruit = robot._estDetruit;
   return *this;
}

//--------------------------------------------------------------------------------
void Robot::deplacer(unsigned distance) {

   switch (_direction) {
      case Direction::UP:
         _coordonnee.deplacer(_coordonnee.getPosX(),
                              _coordonnee.getPosY() - distance);
         break;
      case Direction::DOWN:
         _coordonnee.deplacer(_coordonnee.getPosX(),
                              _coordonnee.getPosY() + distance);
         break;
      case Direction::RIGHT:
         _coordonnee.deplacer(_coordonnee.getPosX() + distance,
                              _coordonnee.getPosY());
         break;
      case Direction::LEFT:
         _coordonnee.deplacer(_coordonnee.getPosX() - distance,
                              _coordonnee.getPosY());
         break;
   }
}

//--------------------------------------------------------------------------------
void Robot::destruction() {
   _estDetruit = true;
}

//--------------------------------------------------------------------------------
void Robot::reparation() {
   _estDetruit = false;
}

/* -------------------------------------------------------------------------------
 *  Données membres
 * -----------------------------------------------------------------------------*/

unsigned Robot::_idSuivant = 1;
