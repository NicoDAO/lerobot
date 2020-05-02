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
#include <vector>

class Simulation {
public:
	Simulation();
	virtual ~Simulation();

	int litFichierSimu(void);
	 std::vector<int> simul;

private:
	int ouvrFichierSimu(void);
	int fp=-1;
	int fichier_lu = 0;
	unsigned int index_simu= 0;

};

#endif /* SIMULATION_H_ */
