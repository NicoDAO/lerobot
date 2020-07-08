#include "log.h"
#include<stdarg.h>
#include<stdio.h>
#include <string.h>
#include <iostream>
#include <sys/time.h>
#define LOG_MESSAGE
#define LOG_INFO
//#define LOG_DEBUG

int numero_log = 0;

void log_format(const char *tag, const char *message, va_list args) {
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

void log_error(const char *message, ...) {
	va_list args;
	va_start(args, message);
	log_format("error", message, args);
	va_end(args);
}

void log_info(const char *message, ...) {
#if 0
    va_list args;
    va_start(args, message);
    log_format("info", message, args);
    va_end(args);
    #endif
}

void log_debug(const char *message, ...) {
#ifdef LOG_DEBUG
    va_list args;
    va_start(args, message);
    log_format("debug", message, args);
    va_end(args);
    #endif
}

void log_message(const char *message, ...) {
#if 0
    va_list args;
    va_start(args, message);
    log_format("message", message, args);
    va_end(args);
    #endif
}
void log_capteur(const char *message, ...) {
#if 0
	va_list args;
	va_start(args, message);
	log_format("capteur", message, args);
	va_end(args);
#endif
}

void log_traction(const char *message, ...) {
#if 0
	va_list args;
	va_start(args, message);
	log_format("traction", message, args);
	va_end(args);
#endif

}
void log_moteur(const char *message, ...) {
#if 0
	va_list args;
	va_start(args, message);
	log_format("moteur", message, args);
	va_end(args);
#endif
}
void log_pwm(const char *message, ...) {
#if 0
	va_list args;
	va_start(args, message);
	log_format("pwm", message, args);
	va_end(args);
#endif
}
void log_memoire(const char *message, ...) {
#if 0
	va_list args;
	va_start(args, message);
	log_format("mem", message, args);
	va_end(args);
#endif
}
void log_simumemoire(const char *message, ...) {
#if 0
    va_list args;
    va_start(args, message);
    log_format("simu mem", message, args);
    va_end(args);
#endif
}

void log_fichiersimu(const char *message, ...) {
#if 1
    va_list args;
    va_start(args, message);
    log_format("fichier", message, args);
    va_end(args);
#endif
}
void log_calibre(const char *message, ...) {
#if 0
    va_list args;
    va_start(args, message);
    log_format("calibre", message, args);
    va_end(args);
#endif
}
void log_gyro(const char *message, ...) {
#if 1
    va_list args;
    va_start(args, message);
    log_format("gyro", message, args);
    va_end(args);
#endif
}
