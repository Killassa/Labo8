/*
-------------------------------------------------------------------------------------
Nom du fichier  : Terrain.h
Nom du labo     : Labo 8 - Survivor
Auteur(s)       : Grégory Rey-Mermet, Cédric Rosat
Date creation   : 14.01.2022

Description     : Cette classe permet d'instancier un terrain pouvant contenir des
                  objets pour autant que ces derniers aient une coordonnée (voir
                  classe coordonnée). Ajoute aussi certaines fonctions pour interagir
                  avec le terrain et son fonctionnement.

Remarque(s)     : L'opérateur de flux << peut afficher correctement au maximum 9
                  objets.
                  Chaque objet doit avoir comme propriété une coordonnée (voir classe
                  coordonnée)
                  //TODO Ajout de l'appel d'initRand() ?
                  Si la méthode nouvel objet est utilisée, il faut initialiser la
                  seed pour la fonction rand().

Modification(s) : -

Compilateur     : Mingw-w64 g++ 11.2.0
-------------------------------------------------------------------------------------
*/

#ifndef TERRAIN_H
#define TERRAIN_H

#include <vector>  // Vecteur d'objets
#include <ostream> // Flux de sortie

template <typename T>
using Objets = std::vector<T>;

template <typename T>
class Terrain {
   /**
    *  Affiche le terrain ainsi que les objets dessus
    *
    * @param os      Flux courant
    * @param terrain Terrain à afficher
    */
   friend std::ostream& operator<< <T>(std::ostream& os, const Terrain<T>& terrain);

public:
   /* -------------------------------------------------------------------------------
    *  Constructeurs et destructeur
    * -----------------------------------------------------------------------------*/

   /**
    * Constructeur d'initialisation
    *
    * @param largeur Largeur du terrain
    * @param hauteur Hauteur du terrain
    */
   Terrain(unsigned largeur, unsigned hauteur);

   //TODO Destructeur implicite pas suffisant, destruction en profondeur
   // Si le terrain est détruit, tous les objets sont détruits avec

   /* -------------------------------------------------------------------------------
    *  Fonctions membres
    * -----------------------------------------------------------------------------*/

   /**
    * Ajoute un objet sur le terrain
    *
    * @param objet Objet à ajouter sur le terrain
    */
   void ajoutObjet(const T& objet);

   /**
    * Créé un nouvel objet et lui attribue des coordonnées aléatoires uniques
    *
    * @return Retourne un objet avec des coordonnées uniques
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
    * Supprime un objet du terrain (vecteur d'objets)
    */
   void supprimerObjets();

   /**
    * Indique si le nombre d'objets présents sur le terrain est <= 1
    *
    * @return   True  : Il ne reste un objet ou moins dans la liste d'objets
    *           False : Il reste plusieurs objets dans la liste d'objets
    */
   bool estTermine();

private:
   /* -------------------------------------------------------------------------------
    *  Données membres
    * -----------------------------------------------------------------------------*/

   const unsigned _largeur, _hauteur;
   Objets<T>      _objets;
};

#include "Terrain_def.h"

#endif //TERRAIN_H
