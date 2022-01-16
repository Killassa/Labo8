/*
-----------------------------------------------------------------------------------
Nom du fichier : Coordonnee.cpp
Nom du labo    : Labo 8 - Survivor
Auteur(s)      : Grégory Rey-Mermet, Cédric Rosat
Date creation  : 14.01.2022
Description    : Ce fichier définit une classe permettant de gérer des coordonnées
Remarque(s)    : -
Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include "Coordonnee.h"

Coordonnee::Coordonnee(unsigned posX, unsigned posY) {
   this->posX = posX;
   this->posY = posY;
}

bool Coordonnee::operator==(const Coordonnee &coordonnee) {
   return this->posX == coordonnee.posX && this->posY == coordonnee.posY;
}

void Coordonnee::deplacer(Coordonnee::Direction direction, unsigned saut) {
   switch (direction) {
      case Direction::UP:
         this->posY += saut;
         break;
      case Direction::DOWN:
         this->posY -= saut;
         break;
      case Direction::RIGHT:
         this->posX += saut;
         break;
      case Direction::LEFT:
         this->posX -= saut;
         break;
   }
}

unsigned Coordonnee::getPosX() const {
   return this->posX;
}

unsigned Coordonnee::getPosY() const {
   return this->posY;
}
