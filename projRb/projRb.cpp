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
#include "mode_fonctionnement.h"

ConfigureFIR_FPGA FIR1;
ConfigureFIR_FPGA FIR2;
ConfigureFIR_FPGA FIR3;
ConfigureFIR_FPGA FIR4;

ConfigureVolumes Volume1;

GereMoteur mot1;
GereMoteur mot2;
GestionTraction traction;

GereLed GereLesLed;

GereCapteurDistance capteurDistance;
//laxi2.
//CagereAXI laxi3;

char HWstring[15] = "Hello World";
long RxtaskCntr = 0;

void* handlerGereAXI2(void *pvParameters);
void* handlerGereAXI3(void *pvParameters);
void* handlerGereMoteur1(void *pvParameters);
void* handlerGereMoteur2(void *pvParameters);
void* handlerGestionTraction(void *pvParameters);
void* handlerCapteurDistance(void *pvParameters);

Messager messageConsigneMoteur2("/ConsigneMoteur", 1);
Messager messageMesureDistanceCapteur("/mesureDistance", 2);
Messager messageConsigneMoteur1("/consigneMoteur1", 3);

//#define LANCE_FIR

int main(int argc, char *argv[]) {
	//configuation des messages
	//Messager messageConsigneMoteur;
	char nom[40];

	printf("compile %s %s", __DATE__, __TIME__);
	int mode_fonctionnement = MODE_ROBOT;
	;
	for (int i = 0; i < argc; ++i) {
		log_info("argument %s", argv[i]);
		if (NULL != strstr(argv[i], "test")) {
			log_info("on est en mode truc");
		}
		if (NULL != strstr(argv[i], "simuPC")) {
			mode_fonctionnement = MODE_PC_SIMULATION;
		}
		if (NULL != strstr(argv[i], "simuCapteur")) {
			mode_fonctionnement = MODE_SIMU_CAPTEUR_DISTANCE;
		}
	}
	pthread_t GereAXI2, GereAXI3, GereMoteur1, GereMoteur2, GestionTraction,
			CapteurDistance;
	pthread_attr_t attr;
	log_info("main");
	struct thread_info *tinfo;
	traction.SetMessage1(&messageConsigneMoteur1);
	traction.SetMessage2(&messageConsigneMoteur2);
	traction.SetMessage3(&messageMesureDistanceCapteur);
	snprintf(nom, sizeof(nom), "moteur1");
	mot1.SetNomMoteur(nom, 0);
	snprintf(nom, sizeof(nom), "moteur2");
	mot2.SetNomMoteur(nom, 0);
	mot1.SetMessage1(&messageConsigneMoteur1);
	mot2.SetMessage1(&messageConsigneMoteur2);
	capteurDistance.SetMessage1(&messageMesureDistanceCapteur);
	GereLesLed.regleAdresse(0x43C00000);
	if (mode_fonctionnement == MODE_PC_SIMULATION) //le mode PC_SIMULATION sert à simuler le fonctionnement du robot sur un PC
			{
		log_info("Mode SIMULATION");
		mot1.metEnmodeSimu();
		mot2.metEnmodeSimu();
		capteurDistance.metEnmodeSimu();
	}
	if (mode_fonctionnement == MODE_CALIBRAGE_MOTEURS) //le mode PC_SIMULATION sert à simuler le fonctionnement du robot sur un PC
				{
			log_info("Calibrage des moteurs");
			mot1.metEnmodeSimu();
			mot2.metEnmodeSimu();
			capteurDistance.metEnmodeSimu();
		}
	if (mode_fonctionnement == MODE_SIMU_CAPTEUR_DISTANCE) //le mode PC_SIMULATION sert à simuler le fonctionnement du robot sur un PC
			{
		// mode servant à tester le robot sur cible en envoyant des valeurs
		// du capteur lues dans le fichier de simulation, met les moteurs sont
		// réelements utilisés

		log_info("Mode SIMULATION du capteur distance");
		capteurDistance.metEnmodeSimu();

	}
#if TEST_LUART == 1
    //test_l_uart();
    Test_lib_uart tt;
    tt.test_l_uart();
#endif
	//Test_lib_uart tt;
	//tt.test_l_uart();
	//conf_uart();
	//	lien1.setXUartPs(&Uart_Ps);
#ifdef LANCE_FIR
    //unsigned long int *, const pthread_attr_t *, void * (*)(void *), void *
    log_info("pthread_create");
    pthread_create(&GereAXI2,NULL,handlerGereAXI2,   (void*)tinfo);
    log_info("sortie");
#endif
#if 0
    pthread_create(&GereAXI3,NULL,handlerGereAXI3,   (void*)tinfo);
#endif
#if 1
	pthread_create(&GereMoteur1, NULL, handlerGereMoteur1, (void*) tinfo);
#endif
#if 1
	pthread_create(&GereMoteur2, NULL, handlerGereMoteur2, (void*) tinfo);
#endif
#if 1
	pthread_create(&GestionTraction, NULL, handlerGestionTraction,
			(void*) tinfo);
#endif
#if 1
	pthread_create(&CapteurDistance, NULL, handlerCapteurDistance,
			(void*) tinfo);
#endif
	void *ret;
	//https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.bpxbd00/ptjoin.htm
#ifdef LANCE_FIR
    if(pthread_join(GereAXI2,&ret) != 0)
    {
        perror("pthread_create() error");
        exit(3);
    }
#endif // LANCE_FIR
	if (pthread_join(GereMoteur1, &ret) != 0) {
		perror("pthread_create() error");
		exit(3);
	}
	return 0;
	//#endif
}

void* handlerGereAXI2(void *pvParameters) {
	log_info("handlerGereAXI2");
	GereLesLed.regleAdresse(0x43C00000);
	FIR1.RegleAdresseAxi(XPAR_FIR_0_S00_AXI_BASEADDR);
	FIR1.SetGereLed(&GereLesLed);
	FIR1.setPeriod(1000000);
	//FIR1.configure(&lien1);
	FIR1.RegleNumeroBouton(0X00000001);
	FIR1.RegleCoefFIR(coef_FIR_0, PROFONDEUR_FIR);
	FIR2.RegleAdresseAxi(XPAR_FIR_1_S00_AXI_BASEADDR);
	FIR2.SetGereLed(&GereLesLed);
	FIR2.setPeriod(1000000);
	//FIR2.configure(&lien1);
	FIR2.RegleNumeroBouton(0x00000002);
	FIR2.RegleCoefFIR(coef_FIR_1, PROFONDEUR_FIR);
	FIR3.RegleAdresseAxi(XPAR_FIR_2_S00_AXI_BASEADDR);
	FIR3.SetGereLed(&GereLesLed);
	FIR3.setPeriod(1000000);
	//FIR3.configure(&lien1);
	FIR3.RegleNumeroBouton(0x00000003);
	FIR3.RegleCoefFIR(coef_FIR_1, PROFONDEUR_FIR);
	FIR4.RegleAdresseAxi(XPAR_FIR_3_S00_AXI_BASEADDR);
	FIR4.SetGereLed(&GereLesLed);
	FIR4.setPeriod(1000000);
	//FIR4.configure(&lien1);
	FIR4.RegleNumeroBouton(0x00000004);
	FIR4.RegleCoefFIR(coef_FIR_1, PROFONDEUR_FIR);
	Volume1.setPeriod(1000000);
	Volume1.RegleAdresseAxi(XPAR_GAINNVOIES_0_S00_AXI_BASEADDR);
	Volume1.setPeriod(5000000);
	Volume1.RegleNumeroBouton(1);
	for (;;) {
		log_info("FIR handler");
		FIR1.handler();
		FIR2.handler();
		FIR3.handler();
		FIR4.handler();
	}
	return NULL;
}
void* handlerGereAXI3(void *pvParameters) {
	log_info("handlerGereAXI3");
	Volume1.RegleAdresseAxi(XPAR_GAINNVOIES_0_S00_AXI_BASEADDR);
	Volume1.setPeriod(10000000);
	for (;;) {
		Volume1.handler();
	}
	return NULL;
}
void* handlerGereMoteur1(void *pvParameters) {
	log_info("handlerGereMoteur");
	mot1.SetAdresseMoteur(XPAR_PMOD_AUDIO_0_S00_AXI_BASEADDR);
	//mot1.SetAdresseMoteur(XPAR_PMOD_AUDIO_0_S00_AXI_BASEADDR);
	mot1.setPeriod(100000);
	//mot1.Reglecalibre(0.6);
	mot1.SetfichierCalib("moteur1.calib");
	log_info("	GereMoteur 1");
	for (;;) {
		mot1.handler();
	}
	return NULL;
}
void* handlerGereMoteur2(void *pvParameters) {
	log_info("handlerGereMoteur");
	mot2.SetAdresseMoteur(XPAR_PMOD_AUDIO_1_S00_AXI_BASEADDR);
	mot2.setPeriod(100000);	//100ms
	//mot2.Reglecalibre(1);
	mot2.SetfichierCalib("moteur2.calib");
	log_info("	GereMoteur 2");
	for (;;) {
		mot2.handler();
	}
	return NULL;
}
void* handlerGestionTraction(void *pvParameters) {
	//traction.SetAdresseMoteur(XPAR_PMOD_AUDIO_1_S00_AXI_BASEADDR);
	traction.setPeriod(100000);
	log_info("	Gere traction");
	for (;;) {
		traction.handler();
	}
	return NULL;
}
void* handlerCapteurDistance(void *pvParameters) {
	log_info("capteurDistance");
	//traction.SetAdresseMoteur(XPAR_PMOD_AUDIO_1_S00_AXI_BASEADDR);
	capteurDistance.setPeriod(1000001);	//seconde
	capteurDistance.SetfichierCalib("capteur_distance.calib");
	capteurDistance.RegleAdresseAxi(
	XPAR_CAPTEURDISTANCEULTRA_0_S00_AXI_BASEADDR);
	for (;;) {
		capteurDistance.handler();
	}
	return NULL;

}

