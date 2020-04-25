
#ifndef LOG_FIC___
#define LOG_FIC___

void log_error(const char* message, ...);
void log_info(const char* message, ...);
void log_debug(const char* message, ...);
void log_message(const char* message, ...);
void log_capteur(const char* message, ...);
void log_traction(const char* message, ...);
void log_moteur(const char* message, ...);
void log_pwm(const char* message, ...);
void log_memoire(const char* message, ...);
  #endif
