/*
-----------------------------------------------------------------------------------
Nom du fichier  : Robot.cpp
Nom du labo     : Labo 8 - Survivor
Auteur(s)       : Grégory Rey-Mermet, Cédric Rosat
Date creation   : 14.01.2022

Description     : Ce fichier définit diverses fonctions utiles...

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

Robot::Robot(const Coordonnee& coordonnee)
: _coordonnee(coordonnee), _id(_idSuivant++), _estDetruit(false) {}

/* -------------------------------------------------------------------------------
 *  Accesseurs
 * -----------------------------------------------------------------------------*/

Coordonnee Robot::getCoordonnee() const {
   return _coordonnee;
}

unsigned Robot::getId() const {
   return _id;
}

bool Robot::getEstDetruit() const {
   return _estDetruit;
}

/* -------------------------------------------------------------------------------
 *  Fonctions membres
 * -----------------------------------------------------------------------------*/

void Robot::deplacer(Coordonnee::Direction direction, unsigned saut) {
   _coordonnee.deplacer(direction, saut);
}

void Robot::destruction() {
   _estDetruit = true;
}

/* -------------------------------------------------------------------------------
 *  Données membres
 * -----------------------------------------------------------------------------*/

unsigned Robot::_idSuivant = 1;
