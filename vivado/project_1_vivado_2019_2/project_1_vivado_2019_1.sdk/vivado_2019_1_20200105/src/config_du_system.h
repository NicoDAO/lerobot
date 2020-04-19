/*
 * config_du_system.h
 *
 *  Created on: Jan 24, 2019
 *      Author: nicolas
 */

#ifndef SRC_CONFIG_DU_SYSTEM_H_
#define SRC_CONFIG_DU_SYSTEM_H_
//#define UART_PRESENT 0

//#define UTILISE_GPIO_AXI
#define UTILISE_GPIO_ZYNQ


#ifdef UTILISE_GPIO_AXI
#include "xgpio.h"
#else
#include "xgpiops.h"  //https://forums.xilinx.com/t5/Xcell-Daily-Blog-Archived/Driving-the-Zynq-SoC-s-GPIO-Adam-Taylor-s-MicroZed-Chronicles/ba-p/389611
#endif

#endif /* SRC_CONFIG_DU_SYSTEM_H_ */
