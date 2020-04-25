#include "mode_fonctionnement.h"



mode_foncionnel::mode_foncionnel()
{
}
mode_foncionnel::~mode_foncionnel()
{
}
void mode_foncionnel::metEnmodeRobot()
{
    this->mode = MODE_ROBOT;
}
int mode_foncionnel::estCequonestenmodeRobot(void)
{
    if( this->mode == MODE_ROBOT) return 1;
    return 0;
}
void mode_foncionnel::metEnmodeSimu()
{
    this->mode = MODE_PC_SIMULATION;
}
int mode_foncionnel::estCequonestenmodeSimu(void)
{
    if( this->mode == MODE_PC_SIMULATION) return 1;
    return 0;
}
