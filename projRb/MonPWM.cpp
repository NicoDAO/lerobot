/*
 * MonPWM.cpp
 *
 *  Created on: 10 janv. 2020
 *      Author: nicolas
 */

#include "MonPWM.h"
#include "LitMemoireLinux.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>
CommandePWM::CommandePWM() {
	// TODO Auto-generated constructor stub

}

CommandePWM::~CommandePWM() {
	// TODO Auto-generated destructor stub
}

void CommandePWM::setBaseAddr(u32 aa){ // @suppress("Member declaration not found")
	this->baseAddr = aa;
}

void CommandePWM::RegleRapportCyclique(u32 rc){
    log_pwm("	on RegleRapportCyclique = %d /1000",rc);

	u32 rcloc = rc & 0x03FFFF;//on utilise que les 10 bits de poids faible
	//rcloc |= 20000000;//dans l'IP, le bit 29 sert à router le PWM depuis le bus AXI
	rcloc |= 0x20000000;

	Xil_Out32(this->baseAddr, rcloc,REGISTRE_REGLAGE_VITESSE    ); //allume l'ampli


}
