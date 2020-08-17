/*
 * Simulation.cpp
 *
 *  Created on: 26 avr. 2020
 *      Author: nicolas
 */

#include "LectureFichier.h"

#include <string>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#define BUF_SIZE 8192


std::mutex g_num_mutex;


LectureFichier::LectureFichier() {

}
LectureFichier::LectureFichier(std::string fichier) {
	nom_fichier = fichier;
}

LectureFichier::~LectureFichier() {
	// TODO Auto-generated destructor stub
}
void LectureFichier::setFichier(std::string stt){
	nom_fichier = stt;
}
int LectureFichier::ouvrFichierSimu() {
	return 1;
}
int LectureFichier::litFichierSimu() { //valeur entiere venant du capteur

	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *chement;
	chement= get_current_dir_name();
	calog.log_fichiersimu("repertoire courant %s, fichier %s",chement,nom_fichier);
	fp = fopen(nom_fichier.c_str(), "r");
	if (fp == NULL) {
		calog.log_fichiersimu("1ouverture impossible de :%s",nom_fichier.c_str() );

		exit(EXIT_FAILURE);
	}
	if (fichier_lu == 0) { //on lit le fichier de paramtrage en en l'enregistre dans un vecteur
		while ((read = getline(&line, &len, fp)) != -1) {
			//log_fichiersimu("Retrieved line of length %zu :\n", read);
			int var = atoi(line);
			calog.log_fichiersimu("fichier %s / %s  -> %d", nom_fichier.c_str(), line,
					var);
			fichier_lu = 1;
			parametrage.push_back(var);
		}
		//free(line);
	}
	int retour = 0;
	if ((index_fichier >= 0) && (index_fichier < parametrage.size())) {
		retour = parametrage.at(index_fichier);

	}
	if (++index_fichier > parametrage.size())
		index_fichier = 0;
	calog.log_fichiersimu("valeur index[%d]= %d", index_fichier, retour);
	return retour;
}
int LectureFichier::litFichierConfigMemoire() { //on va lire le contenu de la memoire issu du fichier de configuration
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	if(memoire_periph == nullptr) //pour eviter de faire dégueuler la memoire, on est censé venir qu'une seule fois la dedans
	{
		memoire_periph= new memoire_peripherique();
	}
	else {
		calog.log_error("eh Raymond, y'a un truc qui va pas dans le programme !!! %s, %s",__FILE__,__LINE__);
		exit(EXIT_FAILURE);
	}

	case_memoire_ casememe; // on met ça en stack


	char *chement;
	chement= get_current_dir_name();
	calog.log_fichiersimu("repertoire courant %s, fichier =%s\n",chement,nom_fichier.c_str());

	fp = fopen(nom_fichier.c_str(), "r");//on ouvre le fichier texte
	if (fp == NULL) {
		calog.log_fichiersimu("2 ouverture impossible de :%s",nom_fichier.c_str() );

		exit(EXIT_FAILURE);
	}
	if (fichier_lu == 0) { //on lit le fichier de paramtrage en en l'enregistre dans un vecteur
		while ((read = getline(&line, &len, fp)) != -1) {
			calog.log_fichiersimu("Retrieved line of length %zu %s\n", read,line);
			//int var = atoi(line);
			std::string laligne(line) ;
			casememe.nom = laligne; // on met le contenu de la ligne dans l'objet
			calog.log_fichiersimu("fichier memoire: %s=> %s",nom_fichier.c_str(), casememe.nom.c_str());
			fichier_lu = 1;
			lit_parametre_ligne(laligne,memoire_periph);
			//	memoire_periph->parametrage_memoire.push_back(casememe);
		}
		//free(line);
	}
	int retour = 0;
	if ((index_fichier >= 0) && (index_fichier < parametrage.size())) {
		retour = parametrage.at(index_fichier);

	}
	if (++index_fichier > parametrage.size())
		index_fichier = 0;
	calog.log_fichiersimu("valeur index[%d]= %d", index_fichier, retour);
	return retour;
}
int LectureFichier::ouvrFichierSimu(std::string nom) {

	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;



		  g_num_mutex.lock();


	char *chement;
	chement= get_current_dir_name();
	calog.log_fichiersimu("repertoire courant %s, fichier %s",chement,nom_fichier.c_str());
	fp = fopen(nom_fichier.c_str(), "r");

	//fp = fopen("truc.txt","r");
	if (fp == NULL) {
		calog.log_fichiersimu("Ouverture impossible d'ouvrir:%s",nom_fichier.c_str() );

		//exit(EXIT_FAILURE);
	}
	if (fichier_lu == 0) {
		while ((read = getline(&line, &len, fp)) != -1) {
			char *end;
			for (double f = strtof(line, &end); line != end;
					f = strtof(line, &end)) {
				line = end;
				if (errno == ERANGE) {
					calog.log_fichiersimu("range error, got ");
					errno = 0;
				}
				calog.log_fichiersimu("fichier %s -> %f", nom.c_str(), f);
				parametrage.push_back(f);
				//log_fichiersimu("%f\n", f);
			}

			fichier_lu = 1;

		}
		//free(line);
	}
	int retour = 0;
	if ((index_fichier >= 0) && (index_fichier < parametrage.size())) {
		retour = parametrage.at(index_fichier);

	}
	if (++index_fichier > parametrage.size())
		index_fichier = 0;
	calog.log_fichiersimu("valeur index[%d]= %d", index_fichier, retour);
	 g_num_mutex.unlock();
	return retour;
}

int  LectureFichier::lit_parametre_ligne(std::string  ligne,memoire_peripherique* mem){
	case_memoire_ tt;
	std::string nom_reg,adresse,valeure;
	int adresse_int =-1,valeur_int=-1;
	//recherche des separateurs
	//registe:adresse:valeur
	std::size_t position_t1 = ligne.find(":",0);
	std::size_t position_t2 = ligne.find(":",position_t1+1);
	//std::size_t position_t3 = ligne.find(":",position_t2+1);
	calog.log_fichiersimu("%d/%d  " ,position_t1,position_t2);

	if((position_t1 == std::string::npos) || (position_t2 == std::string::npos) )return -1;
	nom_reg = ligne.substr(0,position_t1);
	adresse = ligne.substr(position_t1+1,position_t2-position_t1-1);
	valeure = ligne.substr(position_t2+1);
	std::string temp = "donnees a analyser /" + nom_reg + "/" + adresse + "/" + valeure;

	calog.log_fichiersimu(temp.c_str());
	//	log_fichiersimu("%d/%d  nom_reg %s  adresse : %s  valeure : %s" ,position_t1,position_t2,nom_reg.c_str(), adresse.c_str(),valeure.c_str());

	try
	{
		adresse_int = std::stoi(adresse);
		valeur_int = std::stoi(valeure);
		tt.nom = nom_reg;
		tt.adresse = adresse_int;
		tt.valeur = valeur_int;
		calog.log_fichiersimu( "enregistre: %s, adresse registre : %d, valeur registre : %d",tt.nom.c_str() ,adresse_int,valeur_int);

	}
	catch (std::invalid_argument const &e)
	{
		calog.log_fichiersimu("Bad input: std::invalid_argument thrown");
		return -1;
	}
	catch (std::out_of_range const &e)
	{
		calog.log_fichiersimu( "Integer overflow: std::out_of_range thrown" );
		return -1;
	}

	mem->parametrage_memoire.push_back(tt) ;// tt.adresse = ligne.sp
	//nom:12:01    12 : adresse registre,  01 :  valeur registre

	//https://stackoverflow.com/questions/5167625/splitting-a-c-stdstring-using-tokens-e-g
	return 1;
}

