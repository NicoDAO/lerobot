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
	void SetxWakePeriod(uint32_t);
	//TickType_t GetxLastWakeTime(void);
	long RxtaskCntr;
	void init(void);
	void setPeriod(uint32_t);
	void SetGereLed(GereLed*);
	virtual void handler(void)=0;
	void SetMessage1(Messager*);
	void SetMessage2(Messager*);
	void SetMessage3(Messager*);
	void SetMessage4(Messager* lm);
	void SetMessage5(Messager* lm);

  u32 cpt_tache=0;
protected:
	uint32_t xWakePeriod;
	//TickType_t xLastWakeTime;
	void calc_handler(void);
	// GereLed* GestionLed;
	void lapause(u32);


	Messager *leMessage1;
	Messager *leMessage2;
	Messager *leMessage3;
	Messager *leMessage4;
  	Messager *leMessage5;
private :


};

#endif /* SRC_TACHE_H_ */
