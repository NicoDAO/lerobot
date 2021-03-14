
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
        LOG_INFOS,      //2048
    	LOG_TELECO,     //4096
    	LOG_TELEMETRIE  //8192

};

class selectionneLOg
{
public :
	selectionneLOg();
	~selectionneLOg();

};


static int mode_log =LOG_TRACTION;
class GestionLog: public selectionneLOg{
public:
	GestionLog();
	~GestionLog();

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
        void log_teleco(const char* message, ...);
        void log_telemetrie(const char* message, ...);

	void setMode(int m);

private :
	 static bool alreadyCreated;
};


#endif
