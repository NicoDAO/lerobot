
#ifndef LOG_FIC___
#define LOG_FIC___

enum
{

    LOG_RIEN=0,
    LOG_CAPTEUR_DISTANCE,
	LOG_TRACTION,
	LOG_GYROSCOPE,
	LOG_CALIBRE,
	LOG_FSIMU,
	LOG_MEMSIMU,
	LOG_MOTEUR,
	LOG_PWM,
	LOG_MEM,
	LOG_MESSAGES,
	LOG_INFOS


};
static int mode_log =LOG_TRACTION;
class GestionLog{
public:
	GestionLog();
	~GestionLog();

	//void log_format(const char *tag, const char *message, va_list args);
	void log_error(const char* message, ...);
	void log_info(const char* message, ...);
	void log_debug(const char* message, ...);
	void log_message(const char* message, ...);
	void log_capteur(const char* message, ...);
	void log_traction(const char* message, ...);
	void log_moteur(const char* message, ...);
	void log_pwm(const char* message, ...);
	void log_memoire(const char* message, ...);

	void log_simucapteur(const char* message, ...);
	void log_simutraction(const char* message, ...);
	void log_simumoteur(const char* message, ...);
	void log_simupwm(const char* message, ...);
	void log_simumemoire(const char* message, ...);
	void log_fichiersimu(const char* message, ...);
	void log_calibre(const char* message, ...);
	void log_gyro(const char* message, ...);


	void setMode(int m);

private :
	 static bool alreadyCreated;
	// log_format(const char *tag, const char *message, va_list args);
	 //static mode = LOG_RIEN;

};
//
//
//void log_error(const char* message, ...);
//void log_info(const char* message, ...);
//void log_debug(const char* message, ...);
//void log_message(const char* message, ...);
//void log_capteur(const char* message, ...);
//void log_traction(const char* message, ...);
//void log_moteur(const char* message, ...);
//void log_pwm(const char* message, ...);
//void log_memoire(const char* message, ...);
//
//void log_simucapteur(const char* message, ...);
//void log_simutraction(const char* message, ...);
//void log_simumoteur(const char* message, ...);
//void log_simupwm(const char* message, ...);
//void log_simumemoire(const char* message, ...);
//void log_fichiersimu(const char* message, ...);
//void log_calibre(const char* message, ...);
//void log_gyro(const char* message, ...);




#endif