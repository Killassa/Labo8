/*
-----------------------------------------------------------------------------------
Nom du fichier : Robot.cpp
Nom du labo    : Labo 8 - Survivor
Auteur(s)      : Grégory Rey-Mermet, Cédric Rosat
Date creation  : 14.01.2022
Description    : Ce fichier définit diverses fonctions utiles permettant de gérer un
                 robot
Remarque(s)    : -
Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/

#include "Robot.h"

//Permet d'avoir un ID unique pour chaque Robot en commençant depuis 1
unsigned Robot::idSuivant = 1;

Robot::Robot(const Coordonnee &coordonnee) : coordonnee(coordonnee), id(idSuivant) {
   ++idSuivant;
   estDetruit = false;
}

Coordonnee Robot::getCoordonnee() const {
   return this->coordonnee;
}

unsigned Robot::getId() const {
   return this->id;
}

void Robot::deplacer(Coordonnee::Direction direction) {
   this->coordonnee.deplacer(direction);
}

void Robot::destruction() {
   this->estDetruit = true;
}

bool Robot::getEstDetruit() const {
   return this->estDetruit;
}
