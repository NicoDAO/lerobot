/*
 * ConfigureVolumes.cpp
 *
 *  Created on: 6 juin 2019
 *      Author: nicolas
 */

#include "ConfigureVolumes.h"
#include "config_du_system.h"
#include <pthread.h>
#include "log.h"
#define VOLUME1 1
#define VOLUME2 2
#define VOLUME3 3
#define VOLUME4 4

ConfigureVolumes::ConfigureVolumes() {
	// TODO Auto-generated constructor stub
	etat = etat_pas_encore_init;

	xWakePeriod = 1110;
	levol1 = 0;
	levol2 = 0;
	levol3 = 0;
	levol4 = 0;
}

ConfigureVolumes::~ConfigureVolumes() {
	// TODO Auto-generated destructor stub
}

void ConfigureVolumes::handler() {
	char truc[200];

	switch (etat) {

	case etat_pas_encore_init:
		etat = etat_fini;
#ifdef UTILISE_GPIO_AXI
		status = XGpio_Initialize(&GpioInput, XPAR_AXI_GPIO_0_DEVICE_ID);
		// Set the direction for all signals to be inputs
		XGpio_SetDataDirection(&GpioInput, 1, 0xFFFFFFFF);
#else

#if 0  //voir comment on accede aux gpio
		XGpioPs_Config *GPIOConfigPtr;
		GPIOConfigPtr = XGpioPs_LookupConfig(XPAR_PS7_GPIO_0_DEVICE_ID);

		status = XGpioPs_CfgInitialize(&GpioInput, GPIOConfigPtr, GPIOConfigPtr ->BaseAddr);
#endif
#endif
#if 0
		if (status == XST_SUCCESS)etat = etat_fini;
#else
		etat = etat_fini;
#endif
		break;
	case etat_reglageVol1:
		Xil_Out32(this->adresseAXI + PMOD_AUDIO_S00_AXI_SLV_REG1_OFFSET,
				levol1/*0x8000*/); 	//Volume à 1

		Xil_Out32(this->adresseAXI + AXI_SLV_REG0_OFFSET,
				VOLUME1); 	//

		etat = etat_fini;
		log_info(truc, sizeof(truc), "1etat_reglageVol1 = %d", levol1);

		log_info(truc);
		break;
	case etat_reglageVol2:
		Xil_Out32(this->adresseAXI + PMOD_AUDIO_S00_AXI_SLV_REG1_OFFSET,
				levol2/*0x8000*/); 	//Volume à 1

		Xil_Out32(this->adresseAXI + AXI_SLV_REG0_OFFSET,
				VOLUME2); 	//

		etat = etat_fini;
		log_info(truc, sizeof(truc), "etat_reglageVol2 = %d", levol2);
		log_info(truc);
		break;
	case etat_reglageVol3:
		Xil_Out32(this->adresseAXI + PMOD_AUDIO_S00_AXI_SLV_REG1_OFFSET,
				levol3/*0x8000*/); 	//Volume à 1

		Xil_Out32(this->adresseAXI + AXI_SLV_REG0_OFFSET,
				VOLUME3); 	//

		etat = etat_fini;
		log_info(truc, sizeof(truc), "etat_reglageVol3 = %d", levol3);
		log_info(truc);
		break;
	case etat_reglageVol4:
		Xil_Out32(this->adresseAXI + PMOD_AUDIO_S00_AXI_SLV_REG1_OFFSET,
				levol4/*0x8000*/); 	//Volume à 1

		Xil_Out32(this->adresseAXI + AXI_SLV_REG0_OFFSET,
				VOLUME4); 	//

		etat = etat_fini;
		log_info(truc, sizeof(truc), "etat_reglageVol4 = %d", levol4);
		log_info(truc);

		break;
	case etat_fini:

		calcul_volumes();

		break;
	}

	//vTaskDelayUntil(&xLastWakeTime, xWakePeriod);
	log_info("volume");
	usleep(/*xWakePeriod*/1);
}
void ConfigureVolumes::calcul_volumes() {
	char truc[400];
#if UTILISE_GPIO_AXI == 1
	GpioLu = XGpio_DiscreteRead(&GpioInput, 1);
#else
#if 0
	GpioLu = XGpioPs_Read(&GpioInput, 2);//a tester
#endif
#endif
	if (GpioLu != VieuGpioLut) {
		VieuGpioLut = GpioLu;
		GpioLu1 = (char) (GpioLu & 0x1);
		GpioLu2 = (char) ((GpioLu & 0x2) >> 1);
		GpioLu3 = (char) ((GpioLu & 0x4) >> 2);
		GpioLu4 = (char) ((GpioLu & 0x8) >> 3);
		log_info(truc, sizeof(truc), "1etat_reglageVol1 = %08x", GpioLu);
		log_info(truc);
		if (GpioLu1 != GpioLu1_avant) {
			GpioLu1_avant = GpioLu1;
			levol1 += 1000;
			if (levol1 > 10000)
				levol1 = 0;
			etat = etat_reglageVol1;
		}

		if (GpioLu2 != GpioLu2_avant) {
			GpioLu2_avant = GpioLu2;
			levol2 += 1000;
			if (levol2 > 10000)
				levol2 = 0;
			etat = etat_reglageVol2;
		}

		if (GpioLu3 != GpioLu3_avant) {
			GpioLu3_avant = GpioLu3;
			levol3 += 1000;
			if (levol3 > 10000)
				levol3 = 0;
			etat = etat_reglageVol3;
		}

		if (GpioLu4 != GpioLu4_avant) {
			GpioLu4_avant = GpioLu4;
			levol4 += 1000;
			if (levol4 > 10000)
				levol4 = 0;
			etat = etat_reglageVol4;
		}

	}

}
