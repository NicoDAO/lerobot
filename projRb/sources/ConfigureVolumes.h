/*
 * ConfigureVolumes.h
 *
 *  Created on: 6 juin 2019
 *      Author: nicolas
 */

#ifndef SRC_CONFIGUREVOLUMES_H_
#define SRC_CONFIGUREVOLUMES_H_
#include "TransfertAXI.h"
#include "log.h"
enum {
	etat_pas_encore_init = 0,
	etat_reglageVol1,
	etat_reglageVol2,
	etat_reglageVol3,
	etat_reglageVol4,
	etat_fini
};

class ConfigureVolumes: public CagereAXI{
public:
	ConfigureVolumes();
	virtual ~ConfigureVolumes();
	void handler(void);
private:
	int etat;
	unsigned int levol1;
	unsigned int levol2;
	unsigned int levol3;
	unsigned int levol4;

	char GpioLu1;
	char GpioLu2;
	char GpioLu3;
	char GpioLu4;

	char GpioLu1_avant;
	char GpioLu2_avant;
	char GpioLu3_avant;
	char GpioLu4_avant;

	void calcul_volumes(void);
	GestionLog calog;
};

#endif /* SRC_CONFIGUREVOLUMES_H_ */
