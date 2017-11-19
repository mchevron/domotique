/*
 * parser.cpp
 *
 *  Created on: 13 Nov 2017
 *      Author: maxch
 */

#include "../TinyXML/tinyxml.h"


using namespace std;

void parser()
{
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
		//m�thode d'�l�ment permet d'acc�der au premier fils de l'arborescence qui est l'�l�ment Paysage

		//--------------------- EXTRACTION DES ZONES: NIVEAU 1 -----------------------
		for( TiXmlElement* child2 = child1->FirstChild("zone")->ToElement();
			child2;
			child2=child2->NextSiblingElement())
		{ //BOUCLE pour extraire l'ensemble des triplets "zone" du paysage

			if (strcmp(child2->Value(),"zone")==0){ // D�tection d'un �l�ment zone NIVEAU 2 -------
				cout << "Nom de la zone : " << child2->Attribute("name") <<endl;
				// EXTRACTION attribut nom de la zone: NIVEAU 3
				cout << "ID unique de la zone : " << child2->Attribute( "ID") <<endl;
				// ----------------- EXTRACTION attribut ID de la zone: NIVEAU 3 ---------------------------------
				// ------------------------------ EXTRACTION DU PHENOMENE: NIVEAU 2 --------------------
				TiXmlElement* child3 = child2->FirstChild("phenomenon")->ToElement () ;
				cout << "Nom du ph�nom�ne : " << child3->Attribute( "name") <<endl;
				// EXTRACTION attribut nom du phenomene: NIVEAU 3
				cout << "type du ph�nom�ne : " << child3->Attribute( "type") <<endl ;
				//----------- EXTRACTION attribut type du phenomene: NIVEAU 3 -------------------------
				// --------------------- EXTRACTION DES PARAMETRES DU PHENOMENE SELON SON TYPE : NIVEAU 4 ---------
				if (strcmp(child3->Attribute("type"),"sinus")==0){
					// D�tection d'un ph�nom�ne sinuso�dal
					TiXmlElement* child4 = child3->FirstChild("param")->ToElement();
					// ---------- EXTRACTION d�une seule s�rie de param�tres pour le sinus: NIVEAU 4 -------------
					cout << "offset ph�nom�ne : " << child4->Attribute( "offset") <<endl;
					// EXTRACTION param�tre offset du phenomene: NIVEAU 5
					cout << "amplitude du ph�nom�ne : " << child4->Attribute( "ampl") <<endl;
					// EXTRACTION param�tre ampl du phenomene: NIVEAU 5
					cout << "p�riode du ph�nom�ne : " << child4->Attribute( "period") <<endl;
					// EXTRACTION param�tre periode du phenomene: NIVEAU 5
				}
				else
				if (strcmp(child3->Attribute("type"),"pulse")==0)
				{// D�tection d'un ph�nom�ne puls�
					for( TiXmlElement* child4 = child3->FirstChild("param")->ToElement();
						child4;
						child4=child4->NextSiblingElement())
					{ 	//BOUCLE pour extraire plusieurs s�ries de param�tres "param" du phenomene puls�.
						//----- EXTRACTION d�une s�rie de param�tres pour le puls�: NIVEAU 4 ----------
						cout << "interval du ph�nom�ne : " << child4->Attribute( "interval") <<endl;
						// ----------- EXTRACTION param�tre interval du phenomene: NIVEAU 5 -------------------
						cout << "d�but de la tranche en mn : " << child4->Attribute( "begin") <<endl;
						// EXTRACTION param�tre "begin" du phenomene: NIVEAU 5
						cout << "fin de la tranche en minutes : " << child4->Attribute( "end") <<endl;
						// EXTRACTION param�tre "end" du phenomene: NIVEAU 5
						cout << "pente de la tranche : " << child4->Attribute( "slope") <<endl;
						// EXTRACTION param�tre "slope" du phenomene: NIVEAU 5
						cout << "offset de l�intervalle: " << child4->Attribute( "offset") <<endl;
						// EXTRACTION param�tre offset du phenomene: NIVEAU 5
						}
					}

			// ------------------------------ EXTRACTION DE l'ETAT DE LA ZONE: NIVEAU 2
			TiXmlElement* child5 = child2->FirstChild("state")->ToElement();
			cout << "Nom de l'�tat : " << child5->Attribute( "name") <<endl;
			// EXTRACTION attribut nom de l'�tat: NIVEAU 3

			// ------------------------------ EXTRACTION DU CONTROLE DE LA ZONE: NIVEAU 2
			TiXmlElement* child6 = child2->FirstChild("control")->ToElement();
			cout << "Nom du controle : " << child6->Attribute( "name") <<endl;
			// EXTRACTION attribut nom du contr�le: NIVEAU 3
			cout << "Type du controle : " << child6->Attribute( "type") <<endl;
			// EXTRACTION attribut type du contr�le: NIVEAU 3
			} else cout << "Ce n'est pas une zone, il s'agit de la balise : " << child2->Value() << endl;
			// �l�ment autre que zone
		}

}


