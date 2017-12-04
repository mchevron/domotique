/*
 * parser.cpp
 *
 *  Created on: 13 Nov 2017
 *      Author: maxch
 */

#include "parser.h"

Simulator* parser()
{
	string journal;
	vector<Process*> Process_list;		    //vecteur contenant les pointeurs vers toutes les instances des classes filles de process
	//-------------LECTURE DU FICHIER XML ET GESTION ERREUR -------------------------------
	// import local adress of folder and use it to open paysage.xml
	TiXmlDocument doc( "C:/Users/maxch/Desktop/paysage.xml" );
	bool loadOkay = doc.LoadFile();
	if ( !loadOkay )
	{
		printf( "Lecture impossible du fichier 'landscape.xml'. Error='%s' \n", doc.ErrorDesc() );
		exit( 1 );
	} else
	{
		printf( "Lecture correcte du fichier 'landscape.xml'.\n");
	}
	TiXmlElement* child1 = doc.FirstChildElement();
		//méthode d'élément permet d'accéder au premier fils de l'arborescence qui est l'élément Paysage
		Server* Server = new Server(child1->Attribute("tick_unit")); 		//instancie de la classe serveur
		Server->create_file(); 												//créer le fichier journal
		cout << "Nombre de Ticks : " << child1->Attribute("nTicks") <<endl;
		journal = "Nombre de Ticks : " << child1->Attribute("nTicks");
		Server->log_file(journal);
		cout << "Durée de la simulation : " << child1->Attribute("nTicks") << child1->Attribute("Tick_unit") <<endl;
		//--------------------- EXTRACTION DES ZONES: NIVEAU 1 -----------------------
		for( TiXmlElement* child2 = child1->FirstChild("zone")->ToElement();
			child2;
			child2=child2->NextSiblingElement())
		{ //BOUCLE pour extraire l'ensemble des triplets "zone" du paysage

			if (strcmp(child2->Value(),"zone")==0){ // Détection d'un élément zone NIVEAU 2 -------
				cout << "Nom de la zone : " << child2->Attribute("name") <<endl;
				// EXTRACTION attribut nom de la zone: NIVEAU 3
				cout << "ID unique de la zone : " << child2->Attribute( "ID") <<endl;
				// ----------------- EXTRACTION attribut ID de la zone: NIVEAU 3 ---------------------------------

				// ------------------------------ EXTRACTION DE l'ETAT DE LA ZONE: NIVEAU 2
				TiXmlElement* child5 = child2->FirstChild("state")->ToElement();
				cout << "Nom de l'état : " << child5->Attribute( "name") <<endl;
				TiXmlElement* child6 = child5->FirstChild("name")->ToElement();
				cout << "Valeur iphen : " << child6->Attribute( "iphen") <<endl;
				cout << "Valeur ictrl : " << child6->Attribute( "ictrl") <<endl;
				int val_phen = 0;
				int state_curr = 0;
				if (!child6->Attribute("val_phen")) val_phen = child6->Attribute("val_phen");
				if (!child6->Attribute("state_curr")) state_curr = child6->Attribute("state_curr");
				State* State = new State(child5->Attribute("name"), child2->Attribute( "ID"), child6->Attribute("iphen"), child6->Attribute("ictrl"), val_phen, state_curr);
				// EXTRACTION attribut nom de l'état: NIVEAU 3

				// ------------------------------ EXTRACTION DU PHENOMENE: NIVEAU 2 --------------------
				TiXmlElement* child3 = child2->FirstChild("phenomenon")->ToElement () ;
				Phenomenon* Phenomenon;
				cout << "Nom du phénomène : " << child3->Attribute( "name") <<endl;
				// EXTRACTION attribut nom du phenomene: NIVEAU 3
				cout << "type du phénomène : " << child3->Attribute( "type") <<endl ;
				//----------- EXTRACTION attribut type du phenomene: NIVEAU 3 -------------------------
				// --------------------- EXTRACTION DES PARAMETRES DU PHENOMENE SELON SON TYPE : NIVEAU 4 ---------
				if (strcmp(child3->Attribute("type"),"random")==0){
					// Détection d'un phénomène random
					TiXmlElement* child4 = child3->FirstChild("param")->ToElement();
					Phenomenon* Rand = new Rand(child3->Attribute( "name"), child2->Attribute( "ID"), State, child4->Attribute("min"), child4->Attribute("max"));
					// ---------- EXTRACTION d’une seule série de paramètres pour le sinus: NIVEAU 4 -------------
					cout << "phénomène minimum : " << child4->Attribute( "min") <<endl;
					// EXTRACTION paramètre offset du phenomene: NIVEAU 5
					cout << "phénomène maximum : " << child4->Attribute( "max") <<endl;
					// EXTRACTION paramètre ampl du phenomene: NIVEAU 5
				}


				// ------------------------------ EXTRACTION DU CONTROLE DE LA ZONE: NIVEAU 2
				TiXmlElement* child7 = child2->FirstChild("control")->ToElement();
				Control* Control;
				cout << "Nom du controle : " << child7->Attribute( "name") <<endl;
				// EXTRACTION attribut nom du contrôle: NIVEAU 3
				cout << "Type du controle : " << child7->Attribute( "type") <<endl;
				// EXTRACTION attribut type du contrôle: NIVEAU 3
				if (strcmp(child7->Attribute("type"),"TOR")==0){
					// Détection d'un controleur de type tout ou rien
					TiXmlElement* child8 = child7->FirstChild("TOR")->ToElement();
					Control* TOR = new TOR(child3->Attribute( "name"), child2->Attribute( "ID"), Server, State, child8->Attribute("tresh-high"), child8->Attribute("ctrl_min"), val_phen, state_curr);
					Control = TOR;
				} else cout << "Ce n'est pas une zone, il s'agit de la balise : " << child2->Value() << endl;
				// élément autre que zone

				// population de la liste de processus dans le bon ordre
				Process_list.push_back(Phenomenon);
				Process_list.push_back(State);
				Process_list.push_back(Control);
			}
		}
		Process_list.push_back(Server);
		Simulator* Sim = new Simulator(Process_list, child1->Attribute("nTicks"));
		return Sim;
}


