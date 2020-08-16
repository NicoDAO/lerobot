
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
class selectionneLOg
{
public :
	selectionneLOg();
	~selectionneLOg();
    int activeLOG_RIEN;
    int LOG_CAPTEUR_DISTANCE;
	int LOG_TRACTION;
	int LOG_GYROSCOPE;
	int LOG_CALIBRE;
	int LOG_FSIMU;
	int LOG_MEMSIMU;
	int LOG_MOTEUR;
	int LOG_PWM;
	int LOG_MEM;
	int LOG_MESSAGES;
	int LOG_INFOS;

};




static int mode_log =LOG_TRACTION;
class GestionLog: public selectionneLOg{
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
	 int mode_log = 0;
	// log_format(const char *tag, const char *message, va_list args);
	 //static mode = LOG_RIEN;
	// selectionneLOg logS;
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
