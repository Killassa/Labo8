/*
-------------------------------------------------------------------------------------
Nom du fichier  : Survivor.h
Nom du labo     : Labo 8 - Survivor
Auteur(s)       : Grégory Rey-Mermet, Cédric Rosat
Date creation   : 15.01.2022

Description     : Ce fichier d'en-tête (.h) met à la disposition de l'utilisateur
                  diverses fonctions utiles...

Remarque(s)     : -

Modification(s) : -

Compilateur     : Mingw-w64 g++ 11.2.0
-------------------------------------------------------------------------------------
*/

#ifndef SURVIVOR_H
#define SURVIVOR_H

#include "Terrain.h"

// Créé un nouveau robot et le place sur le terrain
template <typename T>
T nouvelObjet(const Terrain<T>& terrain);

#include "Survivor_def.h"

#endif //SURVIVOR_H
