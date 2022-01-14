/*
-------------------------------------------------------------------------------------
Nom du fichier : annexe.h
Nom du labo    : Labo 8 - Survivor
Auteur(s)      : Grégory Rey-Mermet, Cédric Rosat
Date creation  : 14.01.2022
Description    : Ce fichier d'en-tête (.h) met à la disposition de l'utilisateur
                 diverses fonctions utiles dont l'on pourrait avoir besoin dans une
                 multitude de projets différents.
Remarque(s)    : -
Compilateur    : Mingw-w64 g++ 11.2.0
-------------------------------------------------------------------------------------
*/

#ifndef LABO8_ANNEXE_H
#define LABO8_ANNEXE_H

#include <string>

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
 * @param msgSaisie Message pour indiquer la saisie à effectuer
 * @param min       Valeur min
 * @param max       Valeur max
 * @param msgErreur Message d'erreur ("" par défaut)
 * @return          Entier saisi
 */
int saisir(const std::string& msgSaisie, int min, int max, const std::string& msgErreur = "");


/**
 * Vide le buffer
 */
void viderBuffer();

#endif //LABO6_ANNEXE_H
