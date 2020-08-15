/*
 * MonPWM.cpp
 *
 *  Created on: 10 janv. 2020
 *      Author: nicolas
 */

#include "SensMoteur.h"
#include "xparameters.h"
SensMoteur::SensMoteur() {
	// TODO Auto-generated constructor stub

}

SensMoteur::~SensMoteur() {
	// TODO Auto-generated destructor stub
}

void SensMoteur::setBaseAddr(u32 aa){
	this->baseAddr = aa;
}

void SensMoteur::RegleSens(u32 rc){


	calog.log_moteur("sens moteur %x", rc);
	Xil_Out32(this->baseAddr,REGISTRE_SENS_ROTATION, rc); //allume l'ampli
}