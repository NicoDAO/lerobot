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

	/* Create input file descriptor */
	fp = open("simu.txt", O_RDONLY);
	if (fp == -1) {
		perror("open");
		return 2;
	}
	log_fichiersimu("fichier simu ouvert");
}
int Simulation::litFichierSimu() {

	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen("simu.txt", "r");
	if (fp == NULL){
		log_fichiersimu("ouverture impossible");

		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fp)) != -1) {
		log_fichiersimu("Retrieved line of length %zu :\n", read);
		log_fichiersimu("%s", line);
	}

	free(line);

}


