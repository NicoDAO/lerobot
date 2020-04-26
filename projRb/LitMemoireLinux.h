/*
 * LitMemoireLinux.h
 *
 *  Created on: 3 avr. 2020
 *      Author: nicolas
 */

#ifndef LITMEMOIRELINUX_H_
#define LITMEMOIRELINUX_H_
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>
#include "config_du_system.h"
#include "mode_fonctionnement.h"
class LitMemoireLinux : public mode_foncionnel  {
public:
	LitMemoireLinux();
	virtual ~LitMemoireLinux();

protected:
	u32 Xil_In32(u32 adresse);
	u32 Xil_Out32(u32 adresse, u32 valeur, u32 registre=0);
	int fd ;
	unsigned int trs = 0;
};

#endif /* LITMEMOIRELINUX_H_ */
