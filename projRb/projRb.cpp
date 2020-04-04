#include <iostream>
using namespace std;

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>



#include "TransfertAXI.h"
#include "ConfigureFIRFPGA.h"
#include "ConfigureVolumes.h"
#include "config_du_system.h"
#include "GereLed.h"
#include "donnees_FIR.h"
#include "GereMoteur.h"
#include "GestionTraction.h"
#include "Messagerie.h"
#include "GereCapteurDistance.h"
#include "xparameters.h"

ConfigureFIR_FPGA FIR1;
ConfigureFIR_FPGA FIR2;
ConfigureFIR_FPGA FIR3;
ConfigureFIR_FPGA FIR4;

ConfigureVolumes Volume1;

GereMoteur mot1;
GereMoteur mot2;
GestionTraction traction;

GereCapteurDistance capteurDistance;
//laxi2.
//CagereAXI laxi3;

char HWstring[15] = "Hello World";
long RxtaskCntr = 0;

void *handlerGereAXI2(void *pvParameters);
static void handlerGereAXI3(void *pvParameters);
static void handlerGereMoteur1(void *pvParameters);
static void handlerGereMoteur2(void *pvParameters);
static void handlerGestionTraction(void *pvParameters);
static void handlerCapteurDistance(void *pvParameters);

Messager messageConsigneMoteur1;
Messager messageConsigneMoteur2;
Messager messageMesureDistanceCapteur;


int main() {
	//configuation des messages
	//Messager messageConsigneMoteur;
	pthread_t GereAXI2, GereAXI3,GereMoteur1,GereMoteur2,GestionTraction,CapteurDistance;
	pthread_attr_t attr;
	struct thread_info *tinfo;
	traction.SetMessage1(&messageConsigneMoteur1);
	traction.SetMessage2(&messageConsigneMoteur2);
	traction.SetMessage3(&messageMesureDistanceCapteur);
	char nom[40];
	snprintf(nom, sizeof(nom), "moteur1");
	mot1.SetNomMoteur(nom, 0);
	snprintf(nom, sizeof(nom), "moteur2");
	mot2.SetNomMoteur(nom, 0);

	mot1.SetMessage1(&messageConsigneMoteur1);
	mot2.SetMessage1(&messageConsigneMoteur2);
	capteurDistance.SetMessage1(&messageMesureDistanceCapteur);

#if TEST_LUART == 1
	//test_l_uart();
	Test_lib_uart tt;
	tt.test_l_uart();
#endif
	//Test_lib_uart tt;
	//tt.test_l_uart();
	//conf_uart();

	//	lien1.setXUartPs(&Uart_Ps);
#if 1
	//unsigned long int *, const pthread_attr_t *, void * (*)(void *), void *
	pthread_create(&GereAXI2,&attr,handlerGereAXI2,   (void*)tinfo);

#endif
#if 0
	pthread_create(&GereAXI3, NULL,handlerGereAXI3, NULL);
#endif
#if 0
	pthread_create(&GereMoteur1, NULL,ndlerhaGereMoteur1,NULL);
#endif
#if 0
	pthread_create(&GereMoteur2, NULL,handlerGereMoteur2,NULL);
#endif
#if 0
	pthread_create(&GestionTraction,NULL, handlerGestionTraction,NULL);
#endif
#if 0
	pthread_create(&CapteurDistance, NULL,handlerCapteurDistance ,NULL);
#endif
	while (1)
		;

	return 0;
	//#endif
}

void * handlerGereAXI2(void *pvParameters) {
	printf("handlerGereAXI2 \r\n");
	GereLed GereLesLed;
	GereLesLed.regleAdresse(0x43C00000);
	FIR1.RegleAdresseAxi(XPAR_FIR_0_S00_AXI_BASEADDR);
	FIR1.SetGereLed(&GereLesLed);
	FIR1.setPeriod(1);
	//FIR1.configure(&lien1);
	FIR1.RegleNumeroBouton(0X00000001);
	FIR1.RegleCoefFIR(coef_FIR_0, PROFONDEUR_FIR);

	FIR2.RegleAdresseAxi(XPAR_FIR_1_S00_AXI_BASEADDR);
	FIR2.SetGereLed(&GereLesLed);
	FIR2.setPeriod(1);
	//FIR2.configure(&lien1);
	FIR2.RegleNumeroBouton(0x00000002);
	FIR2.RegleCoefFIR(coef_FIR_1, PROFONDEUR_FIR);

	FIR3.RegleAdresseAxi(XPAR_FIR_2_S00_AXI_BASEADDR);
	FIR3.SetGereLed(&GereLesLed);
	FIR3.setPeriod(1);
	//FIR3.configure(&lien1);
	FIR3.RegleNumeroBouton(0x00000003);
	FIR3.RegleCoefFIR(coef_FIR_1, PROFONDEUR_FIR);

	FIR4.RegleAdresseAxi(XPAR_FIR_3_S00_AXI_BASEADDR);
	FIR4.SetGereLed(&GereLesLed);
	FIR4.setPeriod(1);
	//FIR4.configure(&lien1);
	FIR4.RegleNumeroBouton(0x00000004);
	FIR4.RegleCoefFIR(coef_FIR_1, PROFONDEUR_FIR);

	Volume1.setPeriod(100);
	Volume1.RegleAdresseAxi(XPAR_GAINNVOIES_0_S00_AXI_BASEADDR);
	Volume1.setPeriod(5);
	Volume1.RegleNumeroBouton(1);

	for (;;) {
		FIR1.handler();
		FIR2.handler();
		FIR3.handler();
		FIR4.handler();

	}
	return NULL;
}
static void handlerGereAXI3(void *pvParameters) {
	printf("handlerGereAXI3 \r\n");

	Volume1.RegleAdresseAxi(XPAR_GAINNVOIES_0_S00_AXI_BASEADDR);
	Volume1.setPeriod(10);

	for (;;) {
		Volume1.handler();
	}
}
void handlerGereMoteur1(void *pvParameters) {
	printf("handlerGereMoteur \r\n");
	mot1.SetAdresseMoteur(XPAR_PMOD_AUDIO_0_S00_AXI_BASEADDR);
	//mot1.SetAdresseMoteur(XPAR_PMOD_AUDIO_0_S00_AXI_BASEADDR);
	mot1.setPeriod(109);
	printf("	GereMoteur 1 \r\n");

	for (;;) {
		mot1.handler();
	}
}
void handlerGereMoteur2(void *pvParameters) {
	printf("handlerGereMoteur \r\n");
	mot2.SetAdresseMoteur(XPAR_PMOD_AUDIO_1_S00_AXI_BASEADDR);
	mot2.setPeriod(113);

	printf("	GereMoteur 2\r\n");

	for (;;) {
		mot2.handler();
	}
}
static void handlerGestionTraction(void *pvParameters) {
	printf("traction \r\n");
	//traction.SetAdresseMoteur(XPAR_PMOD_AUDIO_1_S00_AXI_BASEADDR);
	traction.setPeriod(29);

	printf("	Gere traction \r\n");

	for (;;) {
		traction.handler();
	}
}
static void handlerCapteurDistance(void *pvParameters) {
	printf("capteurDistance \r\n");
	//traction.SetAdresseMoteur(XPAR_PMOD_AUDIO_1_S00_AXI_BASEADDR);
	capteurDistance.setPeriod(53);
	capteurDistance.RegleAdresseAxi(
			XPAR_CAPTEURDISTANCEULTRA_0_S00_AXI_BASEADDR);
	for (;;) {
		capteurDistance.handler();
	}
}



