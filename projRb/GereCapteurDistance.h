/*
 * GereMoteur.h
 *
 *  Created on: 6 janv. 2020
 *      Author: nicolas
 */

#ifndef SRC_GERECAPTEURDISTANCE_H_
#define SRC_GERECAPTEURDISTANCE_H_
#include "TransfertAXI.h"
#include "config_du_system.h"
#include "Tache.h"

#include "Messagerie.h"
#include "LitMemoireLinux.h"
#include <cstring>
class GereCapteurDistance: public CagereAXI {
public:
	GereCapteurDistance();
	virtual ~GereCapteurDistance();

	void handler(void);
	void ajoute_mesure(int);
	int calculeMesureMoyenne(void);
private:
	int mesureMoyenne = 0;

	int tabMesure[10];
	u8 indexMesure = 0;
	u8 coef_moyenne = 10;

};

#endif /* SRC_GEREMOTEUR_H_ */
