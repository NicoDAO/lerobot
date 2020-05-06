#ifndef MOD_FONC__
#define MOD_FONC__

enum
{

    MODE_ROBOT=0,
    MODE_PC_SIMULATION,
	MODE_SIMU_CAPTEUR_DISTANCE,
	MODE_CALIBRAGE_MOTEURS

};



class mode_foncionnel
{


public :
    mode_foncionnel();
    ~mode_foncionnel();
    void metEnmodeRobot(void);
    void metEnmodeSimu(void);
    int estCequonestenmodeRobot(void);
    int estCequonestenmodeSimu(void);


protected :

    int mode = MODE_ROBOT;


};




#endif
