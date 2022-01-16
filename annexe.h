/*
-------------------------------------------------------------------------------------
Nom du fichier  : annexe.h
Nom du labo     : Labo 8 - Survivor
Auteur(s)       : Grégory Rey-Mermet, Cédric Rosat
Date creation   : 14.01.2022

Description     : Ce fichier d'en-tête (.h) met à la disposition de l'utilisateur
                  diverses fonctions utiles dont l'on pourrait avoir besoin dans une
                  multitude de projets différents.

Remarque(s)     : -

Modification(s) : -

Compilateur     : Mingw-w64 g++ 11.2.0
-------------------------------------------------------------------------------------
*/

#ifndef ANNEXE_H
#define ANNEXE_H

#include <string>

//TODO Ajouter la fonction nbreAleatoire + fichier .h pour les fonctions génériques

/**
 * Affiche un message et met en pause le programme jusqu'à ce que l'utilisateur
 * presse la touche ENTER
 *
 * @param message Message à afficher lors de la pause
 */
void pause(const std::string& message);


/**
 * Saisir dans un intervalle (saisie controllée)
 *
 * @tparam T        Type utilisé pour la saisie
 * @param msgSaisie Message pour indiquer la saisie à effectuer
 * @param min       Valeur min
 * @param max       Valeur max
 * @param msgErreur Message d'erreur ("" par défaut)
 * @return          Entier saisi
 */
template <typename T>

T saisir(const std::string& msgSaisie, T min, T max,
         const std::string& msgErreur = "");


/**
 * Vide le buffer
 */
void viderBuffer();

/**
 * Initialise la seed pour la fonction rand()
 */
void initRand();

#include "annexe_def.h"

#endif //ANNEXE_H
