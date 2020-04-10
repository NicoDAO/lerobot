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
u32 LitMemoireLinux::Xil_Out32(u32 adress,u32 donnee)
{
	printf("	Xil_Out32 %08x    %08x\r\n",adress,donnee);
	return 0;
}


u32 LitMemoireLinux::Xil_In32(u32 adress){
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
	data = static_cast<int*>(mmap(NULL, pagesize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, (off_t)adress));
	if (data == MAP_FAILED)
	{
		perror("mmap error");
	}

	printf("Xil_In32 : %08x	%d\r\n",adress, data[0]);
	munmap (data, pagesize);
	return data[0];
}

