/*
-------------------------------------------------------------------------------------
Nom du fichier  : annexe.h
Nom du labo     : Labo 8 - Survivor
Auteur(s)       : Grégory Rey-Mermet, Cédric Rosat
Date creation   : 14.01.2022

Description     : Fonctions utilisables dans tout le code n'étant pas spécifiques
                  à une classe ou à un algorithme précis.

Remarque(s)     : Avant d'utiliser la fonction nbreAleatoire() il faut initialiser
                  la seed en appelant une seule fois la fonction initRand() (s'il y
                  a plus d'un appel, la seed ne sera initialisée qu'une seule fois).

Modification(s) : -

Compilateur     : Mingw-w64 g++ 11.2.0
-------------------------------------------------------------------------------------
*/

#ifndef ANNEXE_H
#define ANNEXE_H

#include <string> // Utilisation des strings

/* -------------------------------------------------------------------------------
 *  Fonctions ordinaires
 * -----------------------------------------------------------------------------*/

/**
 * Affiche un message et met en pause le programme jusqu'à ce que l'utilisateur
 * presse la touche ENTER
 *
 * @param message Message à afficher lors de la pause
 */
void pause(const std::string& message);

//--------------------------------------------------------------------------------
/**
 * Vide le buffer
 */
void viderBuffer();

//--------------------------------------------------------------------------------
/**
 * Initialise la seed pour la fonction rand() (utilisée dans nbreAleatoire())
 */
void initRand();

/* -------------------------------------------------------------------------------
 *  Fonctions génériques
 * -----------------------------------------------------------------------------*/

/**
 * Saisie dans un intervalle donné (saisie controllée)
 *
 * @tparam T         Type de la saisie
 * @param  msgSaisie Message pour indiquer la saisie à effectuer
 * @param  min       Valeur min
 * @param  max       Valeur max
 * @param  msgErreur Message d'erreur ("" par défaut)
 * @return           Entier saisi
 */
template <typename T>
T saisir(const std::string& msgSaisie, T min, T max,
         const std::string& msgErreur = "");

//--------------------------------------------------------------------------------
/**
 * Génère un nombre aléatoire entre [0, borneSup]
 *
 * @tparam T        Type du nombre généré
 * @param  borneSup Borne supérieure (incluse)
 * @return          Nombre semi-aléatoire
 */
template <typename T>
T nbreAleatoire(T borneSup);

//--------------------------------------------------------------------------------

#include "annexe_def.h"

#endif //ANNEXE_H
