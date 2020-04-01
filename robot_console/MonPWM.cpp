/*
 * MonPWM.cpp
 *
 *  Created on: 10 janv. 2020
 *      Author: nicolas
 */

#include "MonPWM.h"

CommandePWM::CommandePWM() {
	// TODO Auto-generated constructor stub

}

CommandePWM::~CommandePWM() {
	// TODO Auto-generated destructor stub
}

void CommandePWM::setBaseAddr(u32 aa){
	this->baseAddr = aa;
}

void CommandePWM::RegleRapportCyclique(u32 rc){
//	xil_printf("	on RegleRapportCyclique = %d /1000, this->baseAddr = %x \r",rc,this->baseAddr);

	u32 rcloc = rc & 0x03FFFF;//on utilise que les 10 bits de poids faible
	//rcloc |= 20000000;//dans l'IP, le bit 29 sert à router le PWM depuis le bus AXI
	rcloc |= 0x20000000;
	Xil_Out32(this->baseAddr, rcloc); //allume l'ampli


}
