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
 *  Fonctions amies
 * -----------------------------------------------------------------------------*/

bool operator==(const Coordonnee& lhs, const Coordonnee& rhs) {
   return lhs._posX == rhs._posX and lhs._posY == rhs._posY;
}

/* -------------------------------------------------------------------------------
 *  Constructeurs et destructeur
 * -----------------------------------------------------------------------------*/

Coordonnee::Coordonnee() : Coordonnee(0, 0) {}

Coordonnee::Coordonnee(unsigned posX, unsigned posY) : _posX(posX), _posY(posY) {}

/* -------------------------------------------------------------------------------
 *  Fonctions membres
 * -----------------------------------------------------------------------------*/

void Coordonnee::deplacer(Coordonnee::Direction direction, unsigned saut) {
   switch (direction) {
      case Direction::UP:
         _posY += saut;
         break;
      case Direction::DOWN:
         _posY -= saut;
         break;
      case Direction::RIGHT:
         _posX += saut;
         break;
      case Direction::LEFT:
         _posX -= saut;
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
