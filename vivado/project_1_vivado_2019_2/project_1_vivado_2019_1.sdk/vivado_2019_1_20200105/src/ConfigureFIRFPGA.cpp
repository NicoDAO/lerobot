/*
 * ConfigureFIRFPGA.cpp
 *
 *  Created on: Jan 23, 2019
 *      Author: nicolas
 */

#include "ConfigureFIRFPGA.h"

ConfigureFIR_FPGA::ConfigureFIR_FPGA() {
	// TODO Auto-generated constructor stub

}

ConfigureFIR_FPGA::~ConfigureFIR_FPGA() {
	// TODO Auto-generated destructor stub
}


void ConfigureFIR_FPGA::RegleCoefFIR(unsigned int * coef,int taille){
	this->lescoefs = coef;
	this->taille_filtre = taille;
}
