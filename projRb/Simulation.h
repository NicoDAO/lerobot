/*
 * Simulation.h
 *
 *  Created on: 26 avr. 2020
 *      Author: nicolas
 */

#ifndef SIMULATION_H_
#define SIMULATION_H_
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include "log.h"
class Simulation {
public:
	Simulation();
	virtual ~Simulation();

	int litFichierSimu(void);
private:
	int ouvrFichierSimu(void);
	 FILE *fichier;
	int fp=-1;

};

#endif /* SIMULATION_H_ */
