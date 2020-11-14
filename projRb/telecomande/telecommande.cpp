using namespace std;

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "Messagerie.h"
#include <iostream>

#include "mode_fonctionnement.h"
#include "log.h"

GestionLog calog;
Messager *telecommande_robot;

int main(int argc, char *argv[]) {
	char nom[40];
	printf("compile %s %s", __DATE__, __TIME__);
	int mode_fonctionnement = MODE_ROBOT;
	int mod_log = LOG_RIEN;
	int msg_id = 0;
	std::string commande ="";

	for (int i = 0; i < argc; ++i) {
		calog.log_info("argument =  %s", argv[i]);
		if (NULL != strstr(argv [i], "LOG=")) {
			std::string param(argv[i]+strlen("LOG="));//on choppe la config du log
			int log_nb = std::stoi(param);
			cout << "on a " + param;
			mod_log = LOG_CAPTEUR_DISTANCE;

			calog.log_info("on a %s(%d)",argv[i] ,log_nb);
			calog.setMode(log_nb);
		}
		if (NULL != strstr(argv[i], "IPC_ID=")) {
			std::string param(argv[i]+strlen("IPC_ID="));//on choppe la config du log
		         msg_id = std::stoi(param);
			//std::stoi(adresse);
			cout << "on a " + param;
			mod_log = LOG_CAPTEUR_DISTANCE;

			calog.log_info("on a : %s(%d)",argv[i] ,msg_id);
			//calog.setMode(log_nb);
		}
                if (NULL != strstr(argv[i], "COMMANDE=")) {
			std::string param(argv[i]+strlen("COMMANDE="));//on choppe la config du log
			//	cout << "on a " + param;
			mod_log = LOG_CAPTEUR_DISTANCE;
			commande = param; 
                   	calog.log_info("on a: %s(%d)",commande ,msg_id);
		}
	}
	char *  lit_var = getenv("ID_TELECOMMANDE_ROBOT");
  	calog.log_info("lit variable ID_TELECOMMANDE_ROBOT= %s",lit_var);

	//configuration messagerie ipc systemV
        telecommande_robot = new Messager("/telecommande",5);
        telecommande_robot->setID(msg_id);
	int num = 0;
	while(1){


	  AMessage message;
	  snprintf( message.message,sizeof(message.message)," %d %s",num++,commande.c_str());
	  telecommande_robot->envoieMessage(&message);
          //sleep(1);
	  exit(0);
	}


	
	
}


