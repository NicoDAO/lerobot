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
#define BUF_SIZE 8192

LectureFichier::LectureFichier() {

}
LectureFichier::LectureFichier(std::string fichier) {
	this->nom_fichier = fichier;
}

LectureFichier::~LectureFichier() {
	// TODO Auto-generated destructor stub
}

int LectureFichier::ouvrFichierSimu() {
	return 1;
}
int LectureFichier::litFichierSimu() { //valeur entiere venant du capteur

	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen(nom_fichier.c_str(), "r");
	if (fp == NULL) {
		log_fichiersimu("ouverture impossible de :%s",nom_fichier.c_str() );

		exit(EXIT_FAILURE);
	}
	if (fichier_lu == 0) { //on lit le fichier de paramtrage en en l'enregistre dans un vecteur
		while ((read = getline(&line, &len, fp)) != -1) {
			//log_fichiersimu("Retrieved line of length %zu :\n", read);
			int var = atoi(line);
			log_fichiersimu("fichier %s / %s  -> %d", nom_fichier.c_str(), line,
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
	log_fichiersimu("valeur index[%d]= %d", index_fichier, retour);
	return retour;
}
int LectureFichier::ouvrFichierSimu(std::string nom) {

	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen(nom.c_str(), "r");
	if (fp == NULL) {
		log_fichiersimu("ouverture impossible de :%s",nom_fichier.c_str() );

		exit(EXIT_FAILURE);
	}
	if (fichier_lu == 0) {
		while ((read = getline(&line, &len, fp)) != -1) {
			char *end;
			for (double f = strtof(line, &end); line != end;
					f = strtof(line, &end)) {
				line = end;
				if (errno == ERANGE) {
					log_fichiersimu("range error, got ");
					errno = 0;
				}
				log_fichiersimu("fichier %s -> %f", nom.c_str(), f);
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
	log_fichiersimu("valeur index[%d]= %d", index_fichier, retour);
	return retour;
}

