/*
 * MonPWM.h
 *
 *  Created on: 10 janv. 2020
 *      Author: nicolas
 */

#ifndef SRC_MONPWM_H_
#define SRC_MONPWM_H_
#include "config_du_system.h"


class MonPWM {
public:
	MonPWM();
	virtual ~MonPWM();
	void setBaseAddr(u32 );
	void RegleRapportCyclique( u32 clocks);
private :

	void PWM_Set_Duty(u32 clocks, u32 pwmIndex);
	u32 PWM_Get_Period();
	u32 PWM_Get_Duty(u32 pwmIndex);
	void PWM_Enable();
	void PWM_Disable();

	u32 baseAddr = 0;
};

#endif /* SRC_MONPWM_H_ */
