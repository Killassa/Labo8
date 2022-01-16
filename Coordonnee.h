/*
-------------------------------------------------------------------------------------
Nom du fichier : Coordonnee.h
Nom du labo    : Labo 8 - Survivor
Auteur(s)      : Grégory Rey-Mermet, Cédric Rosat
Date creation  : 14.01.2022
Description    : Ce fichier d'en-tête (.h) met à la disposition de l'utilisateur
                 une classe permettant de gérer des coordonnées
Remarque(s)    : -
Compilateur    : Mingw-w64 g++ 11.2.0
-------------------------------------------------------------------------------------
*/

#ifndef LABO8_COORDONNEE_H
#define LABO8_COORDONNEE_H

class Coordonnee {
public:
   //Les directions de déplacement d'une coordonnée
   enum class Direction {UP, DOWN, RIGHT, LEFT};

   /**
    * Constructeur
    *
    * @param posX   Coordonnée X
    * @param posY   Coordonnée Y
    */
   Coordonnee(unsigned posX, unsigned posY);

   /**
    * Opérateur de comparaison d'une coordonnée
    *
    * @param coordonnee Coordonnée avec laquelle on fait une comparaison
    * @return           True  : Les coordonnées sont identiques
    *                   False : Les coordéonnes sont différentes
    */
   bool operator==(const Coordonnee& coordonnee);

   /**
    * Déplacement d'une coordonnées sur un axe
    *
    * @param direction La direction dans laquelle le déplacement est effectué
    * @param saut      Le nombre d'unité de déplacement
    */
   void deplacer(Direction direction, unsigned saut = 1);

   /**
    * Permet de lire la valeur de X de la coordonnée
    *
    * @return   Coordonnée X
    */
   unsigned getPosX() const;

   /**
    * Permet de lire la valeur de Y de la coordonnée
    *
    * @return   Coordonnée Y
    */
   unsigned getPosY() const;


private:
   unsigned posX; //Coordonnée X
   unsigned posY; //Coordonnée Y
};

#endif //LABO8_COORDONNEE_H
