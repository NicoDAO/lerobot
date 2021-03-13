/*
 * MonPWM.h
 *
 *  Created on: 10 janv. 2020
 *      Author: nicolas
 */

#ifndef SRC_GestionTraction_H_
#define SRC_GestionTraction_H_

#include "config_du_system.h"
#include "Tache.h"
#include "log.h"
enum{
	Robot_arret = 0,
	Robot_avant_lent,
	Robot_avant_tranquilou,
	Robot_arriere_tranquilou,
	Robot_avant_rapide,
	Robot_arriere_lent,
	Robot_tourne_gauche_avant,
	Robot_tourne_droite_avant,
	Robot_tourne_droite_arriere,
	Robot_tourne_gauche_arriere

};

class GestionTraction : public Tache,  public GestionLog{
public:
	GestionTraction();
	virtual ~GestionTraction();
	void setBaseAddr(u32 );
	void RegleSens( u32 clocks);
	void handler(void);

private :

        void dirige(void);
	s32 rapport_entre_2_consignes = 0;
	u32 baseAddr = 0;
	int mesureDistance_avant = 0;
        int num = 0;
        int mesureDistance =0;
      	u8 automate = 0;
	AMessage mot1mess, mot2mess;
	u32 vitesse_g = 0;
	char bargraf[256];
	int puissance_moteur1 = 0;
	int puissance_moteur2 = 0;
        string mesures_gyro ="";
        string mesures_distance ="";
	string etat_traction = "";
        string commande_telecommande ="";
        GestionLog calog;

};

#endif /* SRC_MONPWM_H_ */
