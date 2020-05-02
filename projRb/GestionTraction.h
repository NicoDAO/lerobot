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

enum{
	Robot_arret = 0,
	Robot_avant_lent,
	Robot_avant_tranquilou,
	Robot_avant_rapide,
	Robot_arriere_lent,
	Robot_tourne_gauche_avant,
	Robot_tourne_droite_avant,
	Robot_tourne_droite_arriere,
	Robot_toourne_gauche_arriere

};

class GestionTraction : public Tache{
public:
	GestionTraction();
	virtual ~GestionTraction();
	void setBaseAddr(u32 );
	void RegleSens( u32 clocks);
	void handler(void);

private :

	s32 rapport_entre_2_consignes = 0;
	u32 baseAddr = 0;
	int mesureDistance_avant = 0;
    int num = 0;
};

#endif /* SRC_MONPWM_H_ */
