/*
 * MonPWM.cpp
 *
 *  Created on: 10 janv. 2020
 *      Author: nicolas
 */

#include "GestionTraction.h"
#include <stdio.h>
#include <iostream>
GestionTraction::GestionTraction()
{
    // TODO Auto-generated constructor stub
}

GestionTraction::~GestionTraction()
{
    // TODO Auto-generated destructor stub
}

void GestionTraction::setBaseAddr(u32 aa)
{
    this->baseAddr = aa;
}
void GestionTraction::handler()
{
    static u8 automate = 0;
    AMessage mot1mess, mot2mess;
    int mesureDistance = 0;
    u32 vitesse_g = 0;
    char bargraf[256];
//test
//fin test
#if 1
    if (leMessage3->recoitMessage() == 1)
    {
        log_info("GestionTraction : recoitt mesure distance");
        //int taille = leMessage3->vecteurMessages.size();
        //test logique
        if((mesureDistance <(mesureDistance_avant-2000)) || (mesureDistance >(mesureDistance_avant+2000)))
        {
            mesureDistance_avant = mesureDistance;
            if ((mesureDistance >= 2000) && (mesureDistance <= 55000))
            {
                automate = Robot_avant_lent;
            }
            if (mesureDistance < 2000)
            {
                automate = Robot_arret;
            }
        }
        else
        {
            automate = Robot_arret;
        }
        if ((mesureDistance > 1000) && (mesureDistance <= 15000))
        {
            //	automate = 2;
        }
        if ((mesureDistance > 15000) && (mesureDistance <= 20000))
        {
            //	automate = 3;
        }
        if ((mesureDistance > 20000))
        {
            //	automate = 0;
        }
        switch (automate)
        {
        case Robot_arret:
            log_info(mot1mess.message,sizeof(mot1mess.message),"Robot_arret");
            log_info(mot2mess.message,sizeof(mot1mess.message),"Robot_arret");
            log_info("Traction : arret\r\n");
            break;
        case Robot_avant_lent:
            vitesse_g = mesureDistance / 1000;
#ifdef LOG_BARGRAF
            //memset(bargraf, 0, sizeof bargraf);
            slog_info(bargraf,"\0");
            if (vitesse_g >= sizeof(bargraf))
                vitesse_g = sizeof(bargraf) - 1;
            for (u8 u = 0; u < vitesse_g; u++)
            {
                bargraf[u] = 'O';
            }
            log_info("  %s\r\n", bargraf);
#endif
            log_info(mot1mess.message,sizeof(mot1mess.message),"vitesse %d",vitesse_g + 500);
            log_info(mot2mess.message,sizeof(mot2mess.message),"vitesse %d",vitesse_g + 500);
#ifdef LOG_MOTEUR
            log_info("[%04d]Traction : marche avant\r\n");
#endif
            //mot1mess.sens_moteur = 0;
            //	automate++;
            break;
        case Robot_arriere_lent:
            log_info(mot1mess.message,sizeof(mot1mess.message),"recule vitesse %d",100);
            log_info(mot2mess.message,sizeof(mot2mess.message),"recule vitesse %d",200);
            break;
        case Robot_tourne_droite_arriere:
            log_info(mot1mess.message,sizeof(mot1mess.message),"avance vitesse %d",10);
            log_info(mot2mess.message,sizeof(mot2mess.message),"recule vitesse %d",10);
            //	automate++;
            break;
        default:
            automate = 0;
            break;
        }
    }
#endif
    log_info(mot1mess.message,sizeof(mot1mess.message),":puissanc  =%d",num++);
    leMessage1->envoieMessage(&mot1mess);
    leMessage2->envoieMessage(&mot2mess);
    //TODO faire pareil pour le moteur 2
    log_info("GestionTraction 1 : envoie %s\r\n",mot1mess.message);
    log_info("GestionTraction 2 : envoie %s\r\n",mot2mess.message);
    //lapause(0);
    sleep(this->xWakePeriod);
}
void GestionTraction::RegleSens(u32 rc)
{

}
