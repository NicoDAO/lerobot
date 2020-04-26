#include "log.h"
#include<stdarg.h>
#include<stdio.h>
#include <string.h>
#include <iostream>

#define LOG_MESSAGE
#define LOG_INFO
//#define LOG_DEBUG

int numero_log = 0;

void log_format(const char* tag, const char* message, va_list args)
 {   time_t now;     time(&now);     char * date =ctime(&now);   date[strlen(date) - 1] = '\0';  printf("%04d;%s; [%s]; ",numero_log++, date, tag);  vprintf(message, args);     printf("\n"); }

void log_error(const char* message, ...)
{
    va_list args;
     va_start(args, message);
    log_format("error", message, args);
    va_end(args);
 }

void log_info(const char* message, ...)
{
    #ifdef LOG_INFO
    va_list args;
    va_start(args, message);
    log_format("info", message, args);
    va_end(args);
    #endif
}

void log_debug(const char* message, ...)
 {
    #ifdef LOG_DEBUG
    va_list args;
    va_start(args, message);
    log_format("debug", message, args);
    va_end(args);
    #endif
}

void log_message(const char* message, ...)
 {
   #ifdef LOG_MESSAGE
    va_list args;
    va_start(args, message);
    log_format("message", message, args);
    va_end(args);
    #endif
}
void log_capteur(const char* message, ...)
 {
   #ifdef LOG_MESSAGE
    va_list args;
    va_start(args, message);
    log_format("capteur", message, args);
    va_end(args);
    #endif
}

void log_traction(const char* message, ...)
 {

    va_list args;
    va_start(args, message);
    log_format("traction", message, args);
    va_end(args);

}
void log_moteur(const char* message, ...)
 {

    va_list args;
    va_start(args, message);
    log_format("moteur", message, args);
    va_end(args);

}
void log_pwm(const char* message, ...)
 {

    va_list args;
    va_start(args, message);
    log_format("pwm", message, args);
    va_end(args);

}
void log_memoire(const char* message, ...)
 {

    va_list args;
    va_start(args, message);
    log_format("mem", message, args);
    va_end(args);

}
void log_simumemoire(const char* message, ...)
 {

    va_list args;
    va_start(args, message);
    log_format("simu mem", message, args);
    va_end(args);

}
