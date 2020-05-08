/*
 * Simulation.h
 *
 *  Created on: 26 avr. 2020
 *      Author: nicolas
 */

#ifndef LECTUREFICHIER_H_
#define LECTUREFICHIER_H_
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>
#include "log.h"
#include <vector>

class LectureFichier {
public:
	LectureFichier();
	LectureFichier(std::string fichier);
	virtual ~LectureFichier();

	int litFichierSimu(void);
	std::vector<int> simul;
	int ouvrFichierSimu(std::string nom);
private:
	int ouvrFichierSimu(void);

	int fp=-1;
	int fichier_lu = 0;
	unsigned int index_simu= 0;
	std::string nom_fichier ="simu.txt";

};

#endif /* LECTUREFICHIER_H_ */
