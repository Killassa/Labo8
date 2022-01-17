/*
-------------------------------------------------------------------------------------
Nom du fichier  : Terrain.h
Nom du labo     : Labo 8 - Survivor
Auteur(s)       : Grégory Rey-Mermet, Cédric Rosat
Date creation   : 14.01.2022

Description     : Ce fichier d'en-tête (.h) met à la disposition de l'utilisateur
                  diverses fonctions utiles...

Remarque(s)     : L'opérateur de flux << peut afficher correctement au maximum 9
                  objets.

Modification(s) : -

Compilateur     : Mingw-w64 g++ 11.2.0
-------------------------------------------------------------------------------------
*/

#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>
#include <ostream>

//TODO Créer un fichier .h pour les déclarations génériques

template <typename T>
using Objets = std::vector<T>;

template <typename T>
class Terrain {
   friend T nouvelObjet<T>(const Terrain<T>& terrain);

   // Affiche les bordures du terrain ainsi que les objets sur ce dernier
   friend std::ostream& operator<< <T>(std::ostream& os, const Terrain<T>& terrain);

public:
   // Constructeur d'initialisation
   Terrain(unsigned largeur, unsigned hauteur);

   // Ajoute un objet sur le terrain
   void ajoutObjet(const T& objet);

private:
   const unsigned _largeur, _hauteur;
   Objets<T>      _objets;
};

#include "Terrain_def.h"

#endif //TERRAIN_H
