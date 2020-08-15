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
	calog.log_pwm("	on RegleRapportCyclique = %d /1000",rc);

	u32 rcloc = rc & 0x03FFFF;//on utilise que les 10 bits de poids faible
	//rcloc |= 20000000;//dans l'IP, le bit 29 sert à router le PWM depuis le bus AXI
	rcloc |= 0x20000000;

	Xil_Out32(this->baseAddr, rcloc,REGISTRE_REGLAGE_VITESSE    ); //allume l'ampli

}
void CommandePWM::RegleMoteur(u32 vitesse, u32 sens){

    calog.log_pwm("la on RegleRapportCyclique = %d /1000, sens = %x",vitesse, sens);

	u32 rcloc = vitesse & 0x03FFFF;//on utilise que les 10 bits de poids faible
	//rcloc |= 20000000;//dans l'IP, le bit 29 sert à router le PWM depuis le bus AXI
	rcloc |= 0x20000000;
	u32 commande[10];

	memset(commande,0,sizeof(commande));

	commande[0] = rcloc;
	commande[1] = sens;
	//commande[2] = sens;
	//commande[3] = sens;
	//commande[4] = sens;
	Xil_Out32_tab(this->baseAddr, commande,10   ); //allume l'ampli

}
