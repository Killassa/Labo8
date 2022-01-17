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

template <typename T>
using Objets = std::vector<T>;

template <typename T>
class Terrain {
   /**
    *
    * @param os
    * @param terrain
    */
   friend std::ostream& operator<< <T>(std::ostream& os, const Terrain<T>& terrain);

public:
   /**
    * Constructeur d'initialisation
    *
    * @param largeur
    * @param hauteur
    */
   Terrain(unsigned largeur, unsigned hauteur);

   /**
    * Ajoute un objet sur le terrain
    *
    * @param objet
    */
   void ajoutObjet(const T& objet);

   /**
    *
    * @return
    */
   T nouvelObjet();

   /**
    * Déplace tous les objets contenus dans le terrain
    *
    * @param distance   La distance utilisée pour le déplacement des objets
    *                   (Défaut : 1)
    */
   void deplacerObjets(unsigned distance = 1);

   /**
    * Supprime un objet présent si un autre objet vient se positionner sur lui
    */
   void supprimerObjets();

   /**
    * Indique si le déplacement des objets dans le terminé, lorsqu'il ne reste plus
    * qu'un objet non détruit dans la liste d'objets du terrain
    *
    * @return   True  : Il ne reste qu'un objet dans la liste d'objets
    *           False : Il reste plusieurs objets dans la liste d'objets
    */
   bool estTermine();

private:
   const unsigned _largeur, _hauteur;
   Objets<T>      _objets;
};

#include "Terrain_def.h"

#endif //TERRAIN_H
