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
class LitMemoireLinux {
public:
	LitMemoireLinux();
	virtual ~LitMemoireLinux();
	u32 litAxi4Memoire(u32 adresse);
};

#endif /* LITMEMOIRELINUX_H_ */
