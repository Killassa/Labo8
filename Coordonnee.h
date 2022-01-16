/*
-------------------------------------------------------------------------------------
Nom du fichier  : Coordonnee.h
Nom du labo     : Labo 8 - Survivor
Auteur(s)       : Grégory Rey-Mermet, Cédric Rosat
Date creation   : 14.01.2022

Description     : Ce fichier d'en-tête (.h) met à la disposition de l'utilisateur
                  une classe permettant de gérer des coordonnées

Remarque(s)     : -

Modification(s) : -

Compilateur     : Mingw-w64 g++ 11.2.0
-------------------------------------------------------------------------------------
*/

#ifndef COORDONNEE_H
#define COORDONNEE_H

template <typename T>
class Terrain;

class Coordonnee {
   /* -------------------------------------------------------------------------------
    *  Fonctions amies
    * -----------------------------------------------------------------------------*/

   // Permet à la classe Robot d'accéder aux coordonnées X et Y
   friend class Robot;

   // Créé un nouvel objet avec des coordonnées aléatoires
   template <typename T>
   friend T nouvelObjet(const Terrain<T>& terrain);

   /**
    * Opérateur de comparaison d'une coordonnée
    *
    * @param coordonnee Coordonnée avec laquelle on fait une comparaison
    * @return           True  : Les coordonnées sont identiques
    *                   False : Les coordéonnes sont différentes
    */
   friend bool operator==(const Coordonnee& lhs, const Coordonnee& rhs);

public:
   //Les directions de déplacement d'une coordonnée
   enum class Direction {UP, DOWN, RIGHT, LEFT};

   /* -------------------------------------------------------------------------------
    *  Constructeurs et destructeur
    * -----------------------------------------------------------------------------*/

   /**
    * Constructeur par défaut
    *
    */
   Coordonnee();

   /**
    * Constructeur
    *
    * @param posX Coordonnée X
    * @param posY Coordonnée Y
    */
   Coordonnee(unsigned posX, unsigned posY);

   /* -------------------------------------------------------------------------------
    *  Fonctions membres
    * -----------------------------------------------------------------------------*/

   /**
    * Déplacement d'une coordonnées sur un axe
    *
    * @param direction La direction dans laquelle le déplacement est effectué
    * @param saut      Le nombre d'unité de déplacement
    */
   void deplacer(Direction direction, unsigned saut = 1);

   /* -------------------------------------------------------------------------------
    *  Accesseurs
    * -----------------------------------------------------------------------------*/

   /**
    * Permet de lire la valeur de X de la coordonnée
    *
    * @return Coordonnée X
    */
   unsigned getPosX() const;

   /**
    * Permet de lire la valeur de Y de la coordonnée
    *
    * @return Coordonnée Y
    */
   unsigned getPosY() const;


private:
   /* -------------------------------------------------------------------------------
    *  Données membres
    * -----------------------------------------------------------------------------*/

   unsigned _posX, _posY;
};

#endif //COORDONNEE_H