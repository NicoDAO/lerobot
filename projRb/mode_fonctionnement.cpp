#include "mode_fonctionnement.h"
#include "log.h"


mode_foncionnel::mode_foncionnel()
{
}
mode_foncionnel::~mode_foncionnel()
{
}
void mode_foncionnel::metEnmodeRobot()
{
    this->mode = MODE_ROBOT;
    log_info("met fonction MODE ROBOT\r\n" );

}
int mode_foncionnel::estCequonestenmodeRobot(void)
{

    if( this->mode == MODE_ROBOT){
    log_info("on est en mode ROBO\r\n" );
     return 1;
    }
    return 0;
}
void mode_foncionnel::metEnmodeSimu()
{
    this->mode = MODE_PC_SIMULATION;
       log_info("met MODE_PC_SIMULATION\r\n" );

}
int mode_foncionnel::estCequonestenmodeSimu(void)
{
    if( this->mode == MODE_PC_SIMULATION) {
      log_info("on est en mode SIMU\r\n" );
    return 1;
    }
    return 0;
}
