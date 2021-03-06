/*
 * MonPWM.h
 *
 *  Created on: 10 janv. 2020
 *      Author: nicolas
 */

#ifndef SRC_SensMoteur_H_
#define SRC_SensMoteur_H_
#include "config_du_system.h"
#include "LitMemoireLinux.h"
#include "log.h"
class SensMoteur : public LitMemoireLinux{
public:
	SensMoteur();
	virtual ~SensMoteur();
	void setBaseAddr(u32 );
	void RegleSens( u32 clocks);

private :
	LitMemoireLinux mem;

	u32 baseAddr = 0;
	GestionLog calog;
};

#endif /* SRC_MONPWM_H_ */
