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
#include "GereGyroscope.h"
#include "log.h"
#include <iostream>
#include <fstream>
using namespace std;

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
GereGyroscope gyroscope1;
GestionLog calog;

long RxtaskCntr = 0;

void* handlerGereAXI2(void *pvParameters);
void* handlerGereAXI3(void *pvParameters);
void* handlerGereMoteur1(void *pvParameters);
void* handlerGereMoteur2(void *pvParameters);
void* handlerGestionTraction(void *pvParameters);
void* handlerCapteurDistance(void *pvParameters);
void* handlerCapteurGyroscope1(void *pvParameters);

Messager *messageConsigneMoteur2;
Messager *messageMesureDistanceCapteur;
Messager *messageConsigneMoteur1;
Messager *messageGyro;
Messager *messageTelecommande;


//#define LANCE_FIR
int enregistreVariableEnvironnement(const char *, int cle);

int main(int argc, char *argv[]) {
	//configuation des messages
	//Messager messageConsigneMoteur;
	char nom[40];
	printf("compile %s %s", __DATE__, __TIME__);
	int mode_fonctionnement = MODE_ROBOT;
	int mod_log = LOG_RIEN;
	for (int i = 0; i < argc; ++i) {
		calog.log_info("argument %s", argv[i]);
		if (NULL != strstr(argv[i], "test")) {
			calog.log_info("on est en mode truc");
		}
		if (NULL != strstr(argv[i], "simuPC")) {
			mode_fonctionnement = MODE_PC_SIMULATION;
			calog.log_info("mode PC simulation");
		}
		if (NULL != strstr(argv[i], "simuCapteur")) {
			mode_fonctionnement = MODE_SIMU_CAPTEUR_DISTANCE;
		}
		if (NULL != strstr(argv[i], "LOG=")) {
			std::string param(argv[i]+strlen("LOG="));//on choppe la config du log
			int log_nb = std::stoi(param);
			//std::stoi(adresse);
			cout << "on a " + param;
			mod_log = LOG_CAPTEUR_DISTANCE;

			calog.log_info("on a %s(%d)",argv[i] ,log_nb);
			calog.setMode(log_nb);
		}
	}
	printf("lancement thread\n");
	calog.log_info("premier log");
	pthread_t GereAXI2, GereAXI3, GereMoteur1, GereMoteur2, GestionTraction,
	CapteurDistance,Gyroscope1;
	pthread_attr_t attr;
	calog.log_info("main");
	struct thread_info *tinfo;

	//configuration messagerie ipc systemV
        messageConsigneMoteur2  = new Messager("/ConsigneMoteur", 1);
        messageMesureDistanceCapteur  =new Messager("/mesureDistance", 2);
        messageConsigneMoteur1  =new Messager("/consigneMoteur1", 3);
        messageGyro  =new Messager("/gyroscope1", 4);
	messageTelecommande = new Messager("/telecommande",5);
        //on cree une variable d'environnement avec la clé de la télécommande
	//pour pouvoir l'utiliser avec les autres applis
	int identifiantTelecommande = messageTelecommande->getMsgId();
	enregistreVariableEnvironnement("ID_TELECOMMANDE_ROBOT",identifiantTelecommande);
	//configuration classe traction
	traction.SetMessage1(messageConsigneMoteur1);
	traction.SetMessage2(messageConsigneMoteur2);
	traction.SetMessage3(messageMesureDistanceCapteur);
	traction.SetMessage4(messageGyro);
	traction.SetMessage5(messageTelecommande);

	snprintf(nom, sizeof(nom), "moteur1");
	mot1.SetNomMoteur(nom, 0);
	snprintf(nom, sizeof(nom), "moteur2");
	mot2.SetNomMoteur(nom, 0);
	mot1.SetMessage1(messageConsigneMoteur1);
	mot2.SetMessage1(messageConsigneMoteur2);

	capteurDistance.SetMessage1(messageMesureDistanceCapteur);
	//capteurDistance.setGestionLog(&calog);
        gyroscope1.SetMessage1(messageGyro);

	GereLesLed.regleAdresse(0x43C00000);
	if (mode_fonctionnement == MODE_PC_SIMULATION) //le mode PC_SIMULATION sert à simuler le fonctionnement du robot sur un PC
	{
		calog.log_info("Mode SIMULATION");
		mot1.metEnmodeSimu();
		mot2.metEnmodeSimu();
		capteurDistance.metEnmodeSimu();
		gyroscope1.metEnmodeSimu();
	}
	if (mode_fonctionnement == MODE_CALIBRAGE_MOTEURS) //le mode PC_SIMULATION sert à simuler le fonctionnement du robot sur un PC
	{
		calog.log_info("Calibrage des moteurs");
		mot1.metEnmodeSimu();
		mot2.metEnmodeSimu();
		capteurDistance.metEnmodeSimu();
	}
	if (mode_fonctionnement == MODE_SIMU_CAPTEUR_DISTANCE) //le mode PC_SIMULATION sert à simuler le fonctionnement du robot sur un PC
	{
		calog.log_info("Mode SIMULATION du capteur distance");
		capteurDistance.metEnmodeSimu();
	}
#if TEST_LUART == 1
	//test_l_uart();
	Test_lib_uart tt;
	tt.test_l_uart();
#endif

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
#if 1
	pthread_create(&Gyroscope1, NULL, handlerCapteurGyroscope1,
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
}

void* handlerGereAXI2(void *pvParameters) {
	calog.log_info("handlerGereAXI2");
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
		calog.log_info("FIR handler");
		FIR1.handler();
		FIR2.handler();
		FIR3.handler();
		FIR4.handler();
	}
	return NULL;
}
void* handlerGereAXI3(void *pvParameters) {
	calog.log_info("handlerGereAXI3");
	Volume1.RegleAdresseAxi(XPAR_GAINNVOIES_0_S00_AXI_BASEADDR);
	Volume1.setPeriod(10000000);
	for (;;) {
		Volume1.handler();
	}
	return NULL;
}
void* handlerGereMoteur1(void *pvParameters) {
	calog.log_info("handlerGereMoteur");
	mot1.SetAdresseMoteur(XPAR_PMOD_AUDIO_0_S00_AXI_BASEADDR);
	//mot1.SetAdresseMoteur(XPAR_PMOD_AUDIO_0_S00_AXI_BASEADDR);
	mot1.setPeriod(100000);
	//mot1.Reglecalibre(0.6);
	mot1.SetfichierCalib("moteur1.calib");
	calog.log_info("	GereMoteur 1");
	for (;;) {
		mot1.handler();
	}
	return NULL;
}
void* handlerGereMoteur2(void *pvParameters) {
	calog.log_info("handlerGereMoteur");
	mot2.SetAdresseMoteur(XPAR_PMOD_AUDIO_1_S00_AXI_BASEADDR);
	mot2.setPeriod(200000);	//100ms
	//mot2.Reglecalibre(1);
	mot2.SetfichierCalib("moteur2.calib");
	calog.log_info("	GereMoteur 2");
	for (;;) {
		mot2.handler();
	}
	return NULL;
}
void* handlerGestionTraction(void *pvParameters) {
	//traction.SetAdresseMoteur(XPAR_PMOD_AUDIO_1_S00_AXI_BASEADDR);
	traction.setPeriod(100000);
	calog.log_info("	Gere traction");
	for (;;) {
		traction.handler();
	}
	return NULL;
}
void* handlerCapteurDistance(void *pvParameters) {
	calog.log_info("capteurDistance");
	//traction.SetAdresseMoteur(XPAR_PMOD_AUDIO_1_S00_AXI_BASEADDR);
	capteurDistance.setPeriod(200011);	//seconde
	capteurDistance.SetfichierCalib("capteur_distance.calib");
	capteurDistance.RegleAdresseAxi(
			XPAR_CAPTEURDISTANCEULTRA_0_S00_AXI_BASEADDR);
	for (;;) {
		capteurDistance.handler();
	}
	return NULL;

}
void* handlerCapteurGyroscope1(void *pvParameters) {
	calog.log_info("gyroscope1");
	gyroscope1.setPeriod(200001);	//0.1 seconde
	gyroscope1.SetfichierCalib("capteur_gyroscope1.calib");
	gyroscope1.RegleAdresseAxi(
			XPAR_GYROSCOPE0_S00_AXI_BASEADDR);
	for (;;) {
		gyroscope1.handler();
	}
	return NULL;

}

int enregistreVariableEnvironnement(const char * variable, int cle){
/*
On génère les différents scrips qui seront appelé par la télécommande
Android et qui pilotent le robot

 */

   char cle_teleco[100];
   snprintf(cle_teleco,sizeof(cle_teleco),"%d",cle);
   
   //on génère le script pour reculer
   std::ofstream myfile;
   myfile.open ("recule.sh");
   myfile << "#!/bin/sh\n\n\n";
   myfile << "telecomande/teleco LOG=65535 IPC_ID="<< cle_teleco <<"  COMMANDE=RECULE";
   myfile << "\n";
   myfile << "\n";
   myfile.close();


   //on génère le script pour avancer
   myfile.open ("avance.sh");
   myfile << "#!/bin/sh\n\n\n";
   myfile << "telecomande/teleco LOG=65535 IPC_ID="<< cle_teleco <<"  COMMANDE=AVANCE";
   myfile << "\n";
   myfile << "\n";
   myfile.close();


   
   //on génère le script pour arreter
   myfile.open ("arret.sh");
   myfile << "#!/bin/sh\n\n\n";
   myfile << "telecomande/teleco LOG=65535 IPC_ID="<< cle_teleco <<"  COMMANDE=arret";
   myfile << "\n";
   myfile << "\n";
   myfile.close();


   
   //on génère le script pour avancer en tournant gauche
   myfile.open ("avantgauche.sh");
   myfile << "#!/bin/sh\n\n\n";
   myfile << "telecomande/teleco LOG=65535 IPC_ID="<< cle_teleco <<"  COMMANDE=AVANCE_GAUCHE";
   myfile << "\n";
   myfile << "\n";
   myfile.close();


      
   //on génère le script pour avancer en tournant droite
   myfile.open ("avantdroite.sh");
   myfile << "#!/bin/sh\n\n\n";
   myfile << "telecomande/teleco LOG=65535 IPC_ID="<< cle_teleco <<"  COMMANDE=AVANCE_DROITE";
   myfile << "\n";
   myfile << "\n";
   myfile.close();


 //on génère le script pour recule en tournant gauche
   myfile.open ("arrieregauche.sh");
   myfile << "#!/bin/sh\n\n\n";
   myfile << "telecomande/teleco LOG=65535 IPC_ID="<< cle_teleco <<"  COMMANDE=RECULE_GAUCHE";
   myfile << "\n";
   myfile << "\n";
   myfile.close();


      
   //on génère le script pour recule en tournant droite
   myfile.open ("arrieredroite.sh");
   myfile << "#!/bin/sh\n\n\n";
   myfile << "telecomande/teleco LOG=65535 IPC_ID="<< cle_teleco <<"  COMMANDE=RECULE_DROITE";
   myfile << "\n";
   myfile << "\n";
   myfile.close();
    
}


