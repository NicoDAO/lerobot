/*
 * GereLed.h
 *
 *  Created on: Feb 1, 2019
 *      Author: nicolas
 */

#ifndef SRC_GERELED_H_
#define SRC_GERELED_H_

#include <iostream>
using namespace std;

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include "LitMemoireLinux.h"
#include "config_du_system.h"
#include "log.h"
#define AXI_SLV_REG0_OFFSET 0
#define PMOD_AUDIO_S00_AXI_SLV_REG1_OFFSET 4
#define AXI_SLV_REG2_OFFSET 8
#define PMOD_AUDIO_S00_AXI_SLV_REG3_OFFSET 12



class GereLed : public LitMemoireLinux{
public:
	GereLed();
	virtual ~GereLed();
	void allumeLed(char n);
	void eteintLed(char n);
	void bagoteLed(char n);
	void regleAdresse(u32);
private:
//	LitMemoireLinux mem;
	u32 adresseAXI=0;
	GestionLog calog;
};

#endif /* SRC_GERELED_H_ */
