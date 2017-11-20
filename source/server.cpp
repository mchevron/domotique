/*
 * server.cpp
 *
 *  Created on: 19 Nov 2017
 *      Author: maxch
 */

/* Enregistrement/suivi des �v�nements (journalisation, gestion de base de donn�es,
 * statistiques, rapports). D�finition/adaptation des param�tres de contr�le
 *
 * La communication entre un contr�leur et le serveur se fait selon un protocole
 * (p.ex. �criture-lecture ou requ�te-r�ponse fonctionnelles, canal filaire ou sans fil)
 *
 *
 *
 * On assigne des variables dans le serveur ou on les enregistres directement dans
 * le fixhier texte?
 *
 *
 * A chaque fin de tick, ph�nom�ne, etat et control envoie leur valeur � Serveur
 * Serveur �crit dans gnuplot.txt:
 * 	- temp�rature ext�rieur, int�rieur temps
 * 	- ph, temps
 * Serveur �crit dans journal.txt: toute les variables int�ressante dans les triplets + temps


