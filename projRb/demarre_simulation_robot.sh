#!/bin/sh

#LOG_RIEN=0,
#LOG_CAPTEUR_DISTANCE,//2
#LOG_TRACTION,	//4
#LOG_GYROSCOPE,	//8
#LOG_CALIBRE,    //16
#LOG_FSIMU,      //32
#LOG_MEMSIMU,    //64
#LOG_MOTEUR,     //128
#LOG_PWM,        //256
#LOG_MEM,        //512
#LOG_MESSAGES,   //1024
#LOG_INFOS,       //2048
#LOG_TELECO       //4096
./execute_robot LOG=128 simuPC 
