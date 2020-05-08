/*
 * Simulation.cpp
 *
 *  Created on: 26 avr. 2020
 *      Author: nicolas
 */

#include "LectureFichier.h"

#include <string>
#define BUF_SIZE 8192

LectureFichier::LectureFichier() {

}
LectureFichier::LectureFichier(std::string fichier){
	this->nom_fichier = fichier;
}

LectureFichier::~LectureFichier() {
	// TODO Auto-generated destructor stub
}

int LectureFichier::ouvrFichierSimu() {
return 1;
}
int LectureFichier::litFichierSimu() {

	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen(nom_fichier.c_str(), "r");
	if (fp == NULL) {
		log_fichiersimu("ouverture impossible");

		exit(EXIT_FAILURE);
	}
	if (fichier_lu == 0) {
		while ((read = getline(&line, &len, fp)) != -1) {
			//log_fichiersimu("Retrieved line of length %zu :\n", read);
			int var = atoi(line);
			log_fichiersimu("fichier %s / %s  -> %d", nom_fichier.c_str(),line, var);
			fichier_lu = 1;
			simul.push_back(var);
		}
		free(line);
	}
	int retour=0;
	if((index_simu>= 0)&& (index_simu < simul.size())){
		retour = simul.at(index_simu);

	}
	if(++index_simu> simul.size())index_simu = 0;
	log_fichiersimu("valeur index[%d]= %d",index_simu, retour);
	return retour;
}
int LectureFichier::ouvrFichierSimu(std::string nom) {

	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen(nom.c_str(), "r");
	if (fp == NULL) {
		log_fichiersimu("ouverture impossible");

		exit(EXIT_FAILURE);
	}
	if (fichier_lu == 0) {
		while ((read = getline(&line, &len, fp)) != -1) {
			int var = atoi(line);
			log_fichiersimu("fichier %s : %s  -> %d", nom.c_str(),line, var);
			fichier_lu = 1;
			simul.push_back(var);
		}
		free(line);
	}
	int retour=0;
	if((index_simu>= 0)&& (index_simu < simul.size())){
		retour = simul.at(index_simu);

	}
	if(++index_simu> simul.size())index_simu = 0;
	log_fichiersimu("valeur index[%d]= %d",index_simu, retour);
	return retour;
}


