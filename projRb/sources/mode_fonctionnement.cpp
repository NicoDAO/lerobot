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
	calog.log_info("met fonction MODE ROBOT" );

}
int mode_foncionnel::estCequonestenmodeRobot(void)
{

	if( this->mode == MODE_ROBOT){
		calog.log_info("on est en mode ROBO" );
		return 1;
	}
	return 0;
}
void mode_foncionnel::metEnmodeSimu()
{
	this->mode = MODE_PC_SIMULATION;
	calog.log_info("met MODE_PC_SIMULATION" );

}
int mode_foncionnel::estCequonestenmodeSimu(void)
{
	if( this->mode == MODE_PC_SIMULATION) {
		calog.log_info("on est en mode SIMU" );
		return 1;
	}
	return 0;
}
