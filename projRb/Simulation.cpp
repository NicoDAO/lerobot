/*
 * Simulation.cpp
 *
 *  Created on: 26 avr. 2020
 *      Author: nicolas
 */

#include "Simulation.h"

#define BUF_SIZE 8192

Simulation::Simulation() {

}

Simulation::~Simulation() {
	// TODO Auto-generated destructor stub
}

int Simulation::ouvrFichierSimu() {

}
int Simulation::litFichierSimu() {

	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen("simu.txt", "r");
	if (fp == NULL) {
		log_fichiersimu("ouverture impossible");

		exit(EXIT_FAILURE);
	}
	if (fichier_lu == 0) {
		while ((read = getline(&line, &len, fp)) != -1) {
			log_fichiersimu("Retrieved line of length %zu :\n", read);
			int var = atoi(line);
			log_fichiersimu("%s  -> %d", line, var);
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

