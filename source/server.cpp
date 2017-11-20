/*
 * server.cpp
 *
 *  Created on: 19 Nov 2017
 *      Author: maxch
 */

/* Enregistrement/suivi des événements (journalisation, gestion de base de données,
 * statistiques, rapports). Définition/adaptation des paramètres de contrôle
 *
 * La communication entre un contrôleur et le serveur se fait selon un protocole
 * (p.ex. écriture-lecture ou requête-réponse fonctionnelles, canal filaire ou sans fil)
 *
 *
 *
 * On assigne des variables dans le serveur ou on les enregistres directement dans
 * le fixhier texte?
 *
 *
 * A chaque fin de tick, phénomène, etat et control envoie leur valeur à Serveur
 * Serveur écrit dans gnuplot.txt:
 * 	- température extérieur, intérieur temps
 * 	- ph, temps
 * Serveur écrit dans journal.txt: toute les variables intéressante dans les triplets + temps


