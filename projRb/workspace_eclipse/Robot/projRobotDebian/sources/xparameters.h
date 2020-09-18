/*
 * xparameters.h
 *
 *  Created on: 3 avr. 2020
 *      Author: nicolas
 */

#ifndef XPARAMETERS_H_
#define XPARAMETERS_H_
//réglages des adresses memoires pour les transfers sur le bux AXI4
#define XPAR_FIR_0_S00_AXI_BASEADDR 0x43C10000
#define XPAR_FIR_1_S00_AXI_BASEADDR 0x43C20000
#define XPAR_FIR_2_S00_AXI_BASEADDR 0x43C30000
#define XPAR_FIR_3_S00_AXI_BASEADDR 0x43C40000
#define XPAR_GAINNVOIES_0_S00_AXI_BASEADDR 0x43C50000
#define XPAR_PMOD_AUDIO_0_S00_AXI_BASEADDR 0x43C00000
#define XPAR_PMOD_AUDIO_1_S00_AXI_BASEADDR 0x43C60000
#define XPAR_CAPTEURDISTANCEULTRA_0_S00_AXI_BASEADDR 0x43C70000
#define XPAR_GYROSCOPE0_S00_AXI_BASEADDR 0x43C80000

#define REGISTRE_REGLAGE_VITESSE 0
#define REGISTRE_SENS_ROTATION 4

#endif /* XPARAMETERS_H_ */