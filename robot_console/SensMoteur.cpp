/*
 * MonPWM.cpp
 *
 *  Created on: 10 janv. 2020
 *      Author: nicolas
 */

#include "SensMoteur.h"

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

	Xil_Out32(this->baseAddr, rc); //allume l'ampli



}
