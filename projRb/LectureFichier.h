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
#include "config_du_system.h"
#include "log.h"
class case_memoire_{
public:
	u16 adresse= 0;
	u16 valeur = 0;
	std::string nom="";
};

class memoire_peripherique{
public:
	std::vector<case_memoire_> parametrage_memoire;
};

class LectureFichier  {
public:
	LectureFichier();
	LectureFichier(std::string fichier);
	virtual ~LectureFichier();

	int litFichierSimu(void);
	int litFichierConfigMemoire(void);
	std::vector<float> parametrage;

	int ouvrFichierSimu(std::string nom);
	void setFichier(std::string);
	int lit_parametre_ligne(std::string,memoire_peripherique*); // on me le contenu du fichier dans la mémoire
	memoire_peripherique* memoire_periph;
private:
	int ouvrFichierSimu(void);

	int fp=-1;
	int fichier_lu = 0;
	unsigned int index_fichier= 0;
	std::string nom_fichier ="simu_capteur_distance.txt";
	GestionLog calog;


};

#endif /* LECTUREFICHIER_H_ */
