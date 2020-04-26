/*
 * Tache.h
 *
 *  Created on: 26 août 2018
 *      Author: nicolas
 */

#ifndef SRC_TACHE_H_
#define SRC_TACHE_H_
#include <stdio.h>
#include "GereLed.h"
#include "Messagerie.h"
#include "config_du_system.h"
#include "LitMemoireLinux.h"


class Tache  {
public:
	Tache();
	virtual ~Tache();
	void SetxWakePeriod(uint16_t);
	//TickType_t GetxLastWakeTime(void);
	long RxtaskCntr;
	void init(void);
	void setPeriod(uint16_t);
	void SetGereLed(GereLed*);
	virtual void handler(void)=0;
	void SetMessage1(Messager*);
	void SetMessage2(Messager*);
	void SetMessage3(Messager*);
	u32 cpt_tache=0;
protected:
	uint16_t xWakePeriod;
	//TickType_t xLastWakeTime;
	void calc_handler(void);
	// GereLed* GestionLed;
	void lapause(u32);


	Messager *leMessage1;
	Messager *leMessage2;
	Messager *leMessage3;
private :


};

#endif /* SRC_TACHE_H_ */
