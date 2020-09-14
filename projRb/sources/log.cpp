
#include<stdarg.h>
#include<stdio.h>
#include <string.h>
#include <iostream>
#include <sys/time.h>
#include "log.h"


#define LOG_MESSAGE
#define LOG_INFO
//#define LOG_DEBUG

int numero_log = 0;
// Et on déclare alreadyCreated comme faux au début !
bool GestionLog::alreadyCreated = false;
selectionneLOg::selectionneLOg(){

}
selectionneLOg::~selectionneLOg(){

}
GestionLog::GestionLog(){
	// if (alreadyCreated)
	// cout <<("Vous ne pouvez pas créer une seconde instance de la classe Singleton.");
	// Sinon, on construit la classe et on déclare l'objet créé
	alreadyCreated = true;
}
GestionLog::~GestionLog(){
	// Si on veut pouvoir recréer la classe plus tard, on déclare l'objet non existant
	alreadyCreated = false;
}
void  /*GestionLog::*/log_format(const char *tag, const char *message, va_list args) {
	time_t now;
	time(&now);
	char *date = ctime(&now);
	struct timespec ts2;
	clock_gettime(CLOCK_MONOTONIC, &ts2);
	unsigned long mlseconde = ts2.tv_nsec / 1000;
	date[strlen(date) - 1] = '\0';
	printf("%04d;%s; %ld; [%s];", numero_log++, date, /*ts2.tv_nsec*/mlseconde,tag);
	vprintf(message, args);
	printf("\n");
}

void GestionLog::log_error(const char *message, ...) {
	va_list args;
	va_start(args, message);
	log_format("error", message, args);
	va_end(args);
}

void GestionLog::log_info(const char *message, ...) {
	if((mode_log >> LOG_INFOS) & 1){
		va_list args;
		va_start(args, message);
		log_format("Info", message, args);
		va_end(args);
	}
}

void GestionLog::log_debug(const char *message, ...) {

	va_list args;
	va_start(args, message);
	log_format("debug", message, args);
	va_end(args);

}

void GestionLog::log_message(const char *message, ...) {
	if((mode_log >> LOG_MESSAGES) & 1){
		va_list args;
		va_start(args, message);
		log_format("message", message, args);
		va_end(args);
	}

}
void GestionLog::log_capteur(const char *message, ...) {
	if((mode_log >> LOG_CAPTEUR_DISTANCE) & 1){
		va_list args;
		va_start(args, message);
		log_format("capteur", message, args);
		va_end(args);
	}
}

void GestionLog::log_traction(const char *message, ...) {
	if((mode_log >> LOG_TRACTION) & 1){
		va_list args;
		va_start(args, message);
		log_format("Traction", message, args);
		va_end(args);
	}
}
void GestionLog::log_moteur(const char *message, ...) {
	if((mode_log >> LOG_MOTEUR) & 1){
		va_list args;
		va_start(args, message);
		log_format("moteur", message, args);
		va_end(args);
	}
}
void GestionLog::log_pwm(const char *message, ...) {
	if((mode_log >> LOG_PWM) & 1){
		va_list args;
		va_start(args, message);
		log_format("pwm", message, args);
		va_end(args);
	}
}
void GestionLog::log_memoire(const char *message, ...) {
	if((mode_log >> LOG_MEM) & 1){

		va_list args;
		va_start(args, message);
		log_format("mem", message, args);
		va_end(args);
	}

}
void GestionLog::log_simumemoire(const char *message, ...) {
	if((mode_log >> LOG_MEMSIMU) & 1){
		va_list args;
		va_start(args, message);
		log_format("simu mem", message, args);
		va_end(args);
	}
}

void GestionLog::log_fichiersimu(const char *message, ...) {
	if((mode_log >> LOG_FSIMU) & 1){
		va_list args;
		va_start(args, message);
		log_format("fichierS", message, args);
		va_end(args);
	}
}
void GestionLog::log_calibre(const char *message, ...) {
	//if ( logS.LOG_CALIBRE == 1  ){
	if((mode_log >> LOG_CALIBRE) & 1){
		va_list args;

		va_start(args, message);
		log_format("calibre", message, args);
		va_end(args);
	}
}
void GestionLog::log_gyro(const char *message, ...) {
	if((mode_log >> LOG_GYROSCOPE) & 1){
		va_list args;
		va_start(args, message);
		log_format("Gyros", message, args);
		va_end(args);
	}
}

void GestionLog::setMode(int m){
	mode_log = m;
	//logS.LOG_CALIBRE =1;
	//LOG_INFOS =1;
	//if(mode_log &&
//	this->activeLOG_RIEN = 0;
}
/*void log_error(const char *message, ...) {
	va_list args;
	va_start(args, message);
	log_format("error", message, args);
	va_end(args);
}*/
//
//void log_info(const char *message, ...) {
//#if 0
//    va_list args;
//    va_start(args, message);
//    log_format("info", message, args);
//    va_end(args);
//    #endif
//}
//
//void log_debug(const char *message, ...) {
//#ifdef LOG_DEBUG
//    va_list args;
//    va_start(args, message);
//    log_format("debug", message, args);
//    va_end(args);
//    #endif
//}
//
//void log_message(const char *message, ...) {
//#if 0
//    va_list args;
//    va_start(args, message);
//    log_format("message", message, args);
//    va_end(args);
//    #endif
//}
//void log_capteur(const char *message, ...) {
//#if 0
//	va_list args;
//	va_start(args, message);
//	log_format("capteur", message, args);
//	va_end(args);
//#endif
//}
//
//void log_traction(const char *message, ...) {
//#if 0
//	va_list args;
//	va_start(args, message);
//	log_format("traction", message, args);
//	va_end(args);
//#endif
//
//}
//void log_moteurdd(const char *message, ...) {
//#if 0
//	va_list args;
//	va_start(args, message);
//	log_format("moteur", message, args);
//	va_end(args);
//#endif
//}
//void log_pwm(const char *message, ...) {
//#if 0
//	va_list args;
//	va_start(args, message);
//	log_format("pwm", message, args);
//	va_end(args);
//#endif
//}
//void log_memoire(const char *message, ...) {
//#if 0
//	va_list args;
//	va_start(args, message);
//	log_format("mem", message, args);
//	va_end(args);
//#endif
//}
//void log_simumemoire(const char *message, ...) {
//#if 0
//    va_list args;
//    va_start(args, message);
//    log_format("simu mem", message, args);
//    va_end(args);
//#endif
//}
//
//void log_fichiersimu(const char *message, ...) {
//#if 0
//    va_list args;
//    va_start(args, message);
//    log_format("fichierS", message, args);
//    va_end(args);
//#endif
//}
//void log_calibre(const char *message, ...) {
//#if 0
//    va_list args;
//    va_start(args, message);
//    log_format("calibre", message, args);
//    va_end(args);
//#endif
//}
//void log_gyro(const char *message, ...) {
//#if 0
//    va_list args;
//    va_start(args, message);
//    log_format("Gyro", message, args);
//    va_end(args);
//#endif
//}


