/*
 * GereLed.cpp
 *
 *  Created on: Feb 1, 2019
 *      Author: nicolas
 */

#include "GereLed.h"
#include "config_du_system.h"
GereLed::GereLed() {
	// TODO Auto-generated constructor stub
	printf("le constructeur GereLed() \r\n");
	printf(".... \r\n");

}

GereLed::~GereLed() {
	// TODO Auto-generated destructor stub
}

void GereLed::allumeLed(char num) {
	switch (num) {
	case 1:
		mem.Xil_Out32(0x43C00000 + AXI_SLV_REG0_OFFSET, 1); //reg0
		break;
	case 2:
		mem.Xil_Out32(0x43C00000 + PMOD_AUDIO_S00_AXI_SLV_REG1_OFFSET, 1); //reg1
		break;
	case 3:
		mem.Xil_Out32(0x43C00000 + AXI_SLV_REG2_OFFSET, 1); //reg2
		break;
	case 4:
		mem.Xil_Out32(0x43C00000 + PMOD_AUDIO_S00_AXI_SLV_REG3_OFFSET, 1); //reg3
		break;
	}
}

void GereLed::eteintLed(char num) {
	switch (num) {
	case 1:
		Xil_Out32(this->adresseAXI + AXI_SLV_REG0_OFFSET, 0); //reg0
		break;
	case 2:
		Xil_Out32(this->adresseAXI  + PMOD_AUDIO_S00_AXI_SLV_REG1_OFFSET, 0); //reg1
		break;
	case 3:
		Xil_Out32(this->adresseAXI  + AXI_SLV_REG2_OFFSET, 0); //reg2
		break;
	case 4:
		Xil_Out32(this->adresseAXI  + PMOD_AUDIO_S00_AXI_SLV_REG3_OFFSET, 0); //reg3
		break;
	}
}

void GereLed::bagoteLed(char num) {
	static bool eteind = true;

	if (eteind) {
		eteintLed(num);
		eteind = false;
	} else {
		allumeLed(num);
		eteind = true;
	}

}
void GereLed::regleAdresse(u32 a){
	this->adresseAXI = a;
}
