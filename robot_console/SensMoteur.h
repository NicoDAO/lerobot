/*
 * MonPWM.h
 *
 *  Created on: 10 janv. 2020
 *      Author: nicolas
 */

#ifndef SRC_SensMoteur_H_
#define SRC_SensMoteur_H_
#include "config_du_system.h"


class SensMoteur {
public:
	SensMoteur();
	virtual ~SensMoteur();
	void setBaseAddr(u32 );
	void RegleSens( u32 clocks);

private :


	u32 baseAddr = 0;
};

#endif /* SRC_MONPWM_H_ */
