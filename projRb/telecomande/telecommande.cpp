using namespace std;

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include "Messagerie.h"

#include "mode_fonctionnement.h"
#include "log.h"

GestionLog calog;

Messager *messageConsigneMoteur2;
Messager *messageMesureDistanceCapteur;
Messager *messageConsigneMoteur1;
Messager *messageGyro;
Messager *telecommande_robot;

int main(int argc, char *argv[]) {
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

	//configuration messagerie ipc systemV
        messageConsigneMoteur2  = new Messager("/ConsigneMoteur", 1);
        messageMesureDistanceCapteur  =new Messager("/mesureDistance", 2);
        messageConsigneMoteur1  =new Messager("/consigneMoteur1", 3);
	messageGyro  =new Messager("/gyroscope1", 4);
        telecommande_robot = new Messager("/telecommande",5);


	while(1){
	  AMessage message;
	  snprintf( message.message,sizeof(message.message),"trand");
	  telecommande_robot->envoieMessage(&message);
          sleep(1);
	}


	
	
}


