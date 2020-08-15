/*
 * MonPWM.h
 *
 *  Created on: 10 janv. 2020
 *      Author: nicolas
 */

#ifndef SRC_MONPWM_H_
#define SRC_MONPWM_H_
#include "config_du_system.h"
#include "LitMemoireLinux.h"
#include "xparameters.h"
#include "log.h"

class CommandePWM :public LitMemoireLinux{
public:
	CommandePWM();
	virtual ~CommandePWM();
	void setBaseAddr(u32 );
	void RegleRapportCyclique( u32 clocks);
	void RegleMoteur( u32 vitesse, u32 sens);

private :

	void PWM_Set_Duty(u32 clocks, u32 pwmIndex);
	u32 PWM_Get_Period();
	u32 PWM_Get_Duty(u32 pwmIndex);
	void PWM_Enable();
	void PWM_Disable();
	GestionLog calog;
	u32 baseAddr = 0;
};

#endif /* SRC_MONPWM_H_ */
