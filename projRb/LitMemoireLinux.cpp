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
		int offset;

		struct stat sbuf;
		size_t pagesize = 100; // sysconf(_SC_PAGE_SIZE);
		if (fd_ecriture == -1) {
			log_memoire("ouvre /dev/mem");
			fd_ecriture = open("/dev/mem", O_RDWR);
			data_ecriture = static_cast<int*>(mmap(NULL, pagesize,
			PROT_READ | PROT_WRITE, MAP_SHARED, fd_ecriture, (off_t) adress));
		}
		if (fd_ecriture == -1)
			log_memoire("open");
		if (data_ecriture == MAP_FAILED) {
			perror("mmap error");
			return 1;
		}

		if (data_ecriture != NULL) {
			log_memoire(
					"ROBO 32 : ecrit memoire adresse : %08x, registre %x,	donnee:%08X",
					adress, registre, donnee);

			data_ecriture[registre] = donnee;



		}
	} else {
		if (estCequonestenmodeSimu() == 1) {
			//log_simumemoire("SIMULATION %d   r\n", trs++);
			return trs;
		}



	}
	return 0;
}
u32 LitMemoireLinux::Xil_Out32_tab(u32 adress, u32 *donnee, u32 taille) {
	if (estCequonestenmodeRobot() == 1) {
		int offset;

		struct stat sbuf;
		size_t pagesize = 100; // sysconf(_SC_PAGE_SIZE);
		if (fd_ecriture == -1) {
			log_memoire("tab ouvre /dev/mem");
			fd_ecriture = open("/dev/mem", O_RDWR);
			data_ecriture = static_cast<int*>(mmap(NULL, pagesize,
			PROT_READ | PROT_WRITE, MAP_SHARED, fd_ecriture, (off_t) adress));
		}
		if (fd_ecriture == -1)
			log_memoire("open");
		if (data_ecriture == MAP_FAILED) {
			perror("mmap error");
			return 1;
		}

		if (data_ecriture != NULL) {
			log_memoire(
					"tab ecrit memoire adresse : %08x, donnee %x,	taille:%08X",
					adress, donnee[0], taille);
			memcpy(data_ecriture,donnee,taille);
			//ssize_t s = write(STDOUT_FILENO, donnee, taille);
			//if (s != 1) {
			//	if (s == -1)
			//		perror("probleme d ecriture ");
			//}
		}
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

		struct stat sbuf;
		size_t pagesize = 20; // sysconf(_SC_PAGE_SIZE);
		off_t page_base = (adress / pagesize) * pagesize;
		off_t page_offset = adress - page_base;
		if (fd_lecture == -1) {
			log_memoire("ouvre /dev/mem en lecture");

			fd_lecture = open("/dev/mem", O_RDWR);
			data_lecture = static_cast<int*>(mmap(NULL, pagesize,
							PROT_READ | PROT_WRITE, MAP_SHARED, fd_lecture, (off_t) adress));
		}
		if (data_lecture == MAP_FAILED) {
			log_memoire("mmap error");
			return 1;
		}
		log_memoire("Xil_In32 : %08x	%d", adress, data_lecture[0]);
//	munmap (data, pagesize);
//log_memoire("fin nummap\r\n");
		return data_lecture[0];
	} else {
		int l = simu.litFichierSimu();
		log_simumemoire("Xil_In32 lit : %08d", l);
		return l;
	}
}

