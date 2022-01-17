/*
-----------------------------------------------------------------------------------
Nom du fichier  : Coordonnee.cpp
Nom du labo     : Labo 8 - Survivor
Auteur(s)       : Grégory Rey-Mermet, Cédric Rosat
Date creation   : 14.01.2022

Description     : Ce fichier définit une classe permettant de gérer des coordonnées

Remarque(s)     : -

Modification(s) : -

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include "Coordonnee.h"
/* -------------------------------------------------------------------------------
 *  Constructeurs et destructeur
 * -----------------------------------------------------------------------------*/
Coordonnee::Coordonnee() : Coordonnee(0, 0) {}

Coordonnee::Coordonnee(unsigned posX, unsigned posY) : _posX(posX), _posY(posY) {}



/* -------------------------------------------------------------------------------
 *  Fonctions membres
 * -----------------------------------------------------------------------------*/
bool Coordonnee::operator==(const Coordonnee& coordonnee) const {
   return this->_posX == coordonnee._posX and this->_posY == coordonnee._posY;
}

void Coordonnee::deplacer(Coordonnee::Direction direction, unsigned distance) {
   switch (direction) {
      case Direction::UP:
         _posY -= distance;
         break;
      case Direction::DOWN:
         _posY += distance;
         break;
      case Direction::RIGHT:
         _posX += distance;
         break;
      case Direction::LEFT:
         _posX -= distance;
         break;
   }
}



/* -------------------------------------------------------------------------------
 *  Accesseurs
 * -----------------------------------------------------------------------------*/
unsigned Coordonnee::getPosX() const {
   return _posX;
}

unsigned Coordonnee::getPosY() const {
   return _posY;
}