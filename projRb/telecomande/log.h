
#ifndef LOG_FIC___
#define LOG_FIC___

enum
{

    LOG_RIEN=0,
    LOG_CAPTEUR_DISTANCE,//2
	LOG_TRACTION,	//4
	LOG_GYROSCOPE,	//8
	LOG_CALIBRE,    //16
	LOG_FSIMU,      //32
	LOG_MEMSIMU,    //64
	LOG_MOTEUR,     //128
	LOG_PWM,        //256
	LOG_MEM,        //512
	LOG_MESSAGES,   //1024
	LOG_INFOS       //2048

};

class selectionneLOg
{
public :
	selectionneLOg();
	~selectionneLOg();
   /* int activeLOG_RIEN;
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
	int LOG_INFOS;*/

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
	 //int mode_log = 0;

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
