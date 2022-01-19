/*
-------------------------------------------------------------------------------------
Nom du fichier  : Coordonnee.h
Nom du labo     : Labo 8 - Survivor
Auteur(s)       : Grégory Rey-Mermet, Cédric Rosat
Date creation   : 14.01.2022

Description     : Met à disposition des coordonnées 2D ainsi qu'un opérateur
                  permettant de tester si 2 coordonnées sont similaires.

Remarque(s)     : -

Modification(s) : -

Compilateur     : Mingw-w64 g++ 11.2.0
-------------------------------------------------------------------------------------
*/

#ifndef COORDONNEE_H
#define COORDONNEE_H

class Coordonnee {
public:
   /* -------------------------------------------------------------------------------
    *  Constructeurs et destructeur
    * -----------------------------------------------------------------------------*/

   /**
    * Constructeur par défaut (x et y sont à 0)
    */
   Coordonnee();

   /**
    * Constructeur d'initialisation
    *
    * @param posX Coordonnée X
    * @param posY Coordonnée Y
    */
   Coordonnee(unsigned posX, unsigned posY);



   /* -------------------------------------------------------------------------------
    *  Fonctions membres
    * -----------------------------------------------------------------------------*/

   /**
    * Opérateur de comparaison d'une coordonnée
    *
    * @param coordonnee Coordonnée avec laquelle on fait une comparaison
    * @return           True  : Les coordonnées sont identiques
    *                   False : Les coordéonnes sont différentes
    */
   bool operator==(const Coordonnee& coordonnee) const;


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

   /**
    * Permet de modifier la coordonnée X
    *
    * @param posX
    */
   void setPosX(unsigned posX);

   /**
    * Permet de modifier la coordonnée Y
    *
    * @param posY
    */
   void setPosY(unsigned posY);



private:
   /* -------------------------------------------------------------------------------
    *  Données membres
    * -----------------------------------------------------------------------------*/

   unsigned _posX, _posY;
};

#endif //COORDONNEE_H