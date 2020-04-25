#ifndef MOD_FONC__
#define MOD_FONC__

enum
{

    MODE_ROBOT=0,
    MODE_PC_SIMULATION

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


private :

    int mode = MODE_ROBOT;


};




#endif
