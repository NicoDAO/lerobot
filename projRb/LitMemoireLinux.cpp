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
LitMemoireLinux::LitMemoireLinux() {

}

LitMemoireLinux::~LitMemoireLinux() {
	// TODO Auto-generated destructor stub
}
u32 LitMemoireLinux::litAxi4Memoire(u32 adress){
	int offset;
	int *data;
	struct stat sbuf;
	size_t pagesize = 20;// sysconf(_SC_PAGE_SIZE);
	off_t page_base = (adress / pagesize) * pagesize;
	off_t page_offset = adress - page_base;

	int fd = open("/dev/mem", O_RDWR);
	if (fd  == -1)
		printf( "open");
	// data = mmap(adress,pagesize	,PROT_READ | PROT_WRITE, MAP_SHARED | MAP_PRIVATE | MAP_POPULATE,     fd, 0);
	data = mmap(NULL, pagesize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, (off_t)adress);
	if (data == MAP_FAILED)
	{
		perror("mmap error");
	}

	printf("distance capteur : %d\r\n", data[0]);
	munmap (data, pagesize);
	return data[0];
}

