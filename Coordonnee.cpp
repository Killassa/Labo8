/*
-----------------------------------------------------------------------------------
Nom du fichier  : Coordonnee.cpp
Nom du labo     : Labo 8 - Survivor
Auteur(s)       : Grégory Rey-Mermet, Cédric Rosat
Date creation   : 14.01.2022

Description     : Constructeurs et méthodes pour interagir avec les coordonnées.

Remarque(s)     : -

Modification(s) : -

Compilateur     : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/
#include "Coordonnee.h"

/* -------------------------------------------------------------------------------
 *  Constructeurs et destructeur
 * -----------------------------------------------------------------------------*/

Coordonnee::Coordonnee() : Coordonnee(0u, 0u) {}

//--------------------------------------------------------------------------------
Coordonnee::Coordonnee(unsigned posX, unsigned posY) : _posX(posX), _posY(posY) {}

/* -------------------------------------------------------------------------------
 *  Fonctions membres
 * -----------------------------------------------------------------------------*/

void Coordonnee::deplacer(unsigned posX, unsigned posY) {
   _posX = posX;
   _posY = posY;
}

/* -------------------------------------------------------------------------------
 *  Opérateurs
 * -----------------------------------------------------------------------------*/

bool Coordonnee::operator==(const Coordonnee& coordonnee) const {
   return _posX == coordonnee._posX and _posY == coordonnee._posY;
}

/* -------------------------------------------------------------------------------
 *  Accesseurs
 * -----------------------------------------------------------------------------*/

unsigned Coordonnee::getPosX() const {
   return _posX;
}

//--------------------------------------------------------------------------------
unsigned Coordonnee::getPosY() const {
   return _posY;
}