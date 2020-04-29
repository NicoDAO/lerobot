/*
 * LitMemoireLinux.cpp
 *
 *  Created on: 3 avr. 2020
 *      Author: nicolas
 */

#include "LitMemoireLinux.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>

#define TEST_PC
LitMemoireLinux::LitMemoireLinux() {
}

LitMemoireLinux::~LitMemoireLinux() {
	// TODO Auto-generated destructor stub
}
u32 LitMemoireLinux::Xil_Out32(u32 adress, u32 donnee, u32 registre) {
	if (estCequonestenmodeRobot() == 1) {
		log_memoire(
				"ROBO 32 : ecrit memoire adresse : %08x, donne: %d,	registre :%d\r\n",
				adress, donnee, registre);
		int offset;
		int *data;
		struct stat sbuf;
		size_t pagesize = 20; // sysconf(_SC_PAGE_SIZE);
		off_t page_base = (adress / pagesize) * pagesize;
		off_t page_offset = adress - page_base;
		log_memoire("   ouvre /dev/mem\r\n");

		int fd = open("/dev/mem", O_RDWR);
		if (fd == -1)
			log_info("open");
		//data = mmap(adress,pagesize	,PROT_READ | PROT_WRITE, MAP_SHARED | MAP_PRIVATE | MAP_POPULATE,     fd, 0);
		data = static_cast<int*>(mmap(NULL, pagesize, PROT_READ | PROT_WRITE,
				MAP_SHARED, fd, (off_t) adress));
		if (data == MAP_FAILED) {
			perror("mmap error");
		}
#if 1
		data[registre] = donnee;
		log_info("                           OK\r\n");
		//munmap(data, pagesize);
		//close(fd);
		//log_info("fin nummap\r\n");
#endif
		return data[0];
	} else {
		if (estCequonestenmodeSimu() == 1) {
			//log_simumemoire("SIMULATION %d   r\n", trs++);
			return trs;
		}
	}
	return 0;
}

u32 LitMemoireLinux::Xil_In32(u32 adress) {
	if (estCequonestenmodeRobot() == 1) {
		int offset;
		int *data;
		struct stat sbuf;
		size_t pagesize = 20; // sysconf(_SC_PAGE_SIZE);
		off_t page_base = (adress / pagesize) * pagesize;
		off_t page_offset = adress - page_base;
		log_memoire("Xil_In32  : lit memoire adresse : %08x\r\n", adress);
		log_memoire("ouvre /dev/mem\r\n");
		int fd = open("/dev/mem", O_RDWR);
		if (fd == -1)
			log_info("open");
		//data = mmap(adress,pagesize	,PROT_READ | PROT_WRITE, MAP_SHARED | MAP_PRIVATE | MAP_POPULATE,     fd, 0);
		data = static_cast<int*>(mmap(NULL, pagesize, PROT_READ | PROT_WRITE,
				MAP_SHARED, fd, (off_t) adress));
		if (data == MAP_FAILED) {
			perror("mmap error");
		}
		log_memoire("Xil_In32 : %08x	%d\r\n", adress, data[0]);
		//munmap (data, pagesize);
		//log_memoire("fin nummap\r\n");
		return data[0];
	} else {
		int l = simu.litFichierSimu();
		log_simumemoire("Xil_In32 lit : %08d	\r\n", l);
		return l;
	}
}

