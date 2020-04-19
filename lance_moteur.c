#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>
//https://www.poftut.com/mmap-tutorial-with-examples-in-c-and-cpp-programming-languages/
//adresse capteur 43C70000h = 1137115136
//adresse moteur 0X43C60000 = 1137049600
int main(int argc, char *argv[])
{
    int offset;
    int *data;
    struct stat sbuf;
    int adress = 0;
    int reg = 0;
    int donnee = 0;
    
    //sscanf(argv[1],"%d",&adress);
    adress = strtoul(argv[1], NULL, 0);
    donnee = strtoul(argv[2], NULL, 0);
    reg = strtoul(argv[3], NULL, 0);
    printf("$$ecriture memoire a l'adresse %x, donnee = %x \n",adress,donnee);
    donnee = donnee | 0x80000000;  //on force le bit de poid fort pour activer l'ampli
    donnee = donnee | 0x20000000;  //on force le bit de poid fort pour activer l'ampli


    // Truncate offset to a multiple of the page size, or mmap will fail.
    size_t pagesize = 20;// sysconf(_SC_PAGE_SIZE);
    off_t page_base = (adress / pagesize) * pagesize;
    off_t page_offset = adress - page_base;
    printf("$$ecriture memoire a l'adresse %x, donnee = %x registre axi : %d\n",adress,donnee,reg);
    if (argc != 4	)
    {
        printf( "usage: mmapdemo offset\n");
        exit(1);
    }
    int fd = open("/dev/mem", O_RDWR);
  printf("ouverture  /dev/mem");
 
    if (fd  == -1)
        printf(1, "open");
    // data = mmap(adress,pagesize	,PROT_READ | PROT_WRITE, MAP_SHARED | MAP_PRIVATE | MAP_POPULATE,     fd, 0);
        data = mmap(NULL, pagesize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, (off_t)adress);
        if (data == MAP_FAILED)
        {
            perror("mmap error");
        }
        /*  for(int i = 0; i < 10; i++)
         {
           printf("[%lu]=%X ", i, data[i]);
         }*/
	data[reg] = donnee;
        printf("distance capteur : %d\r\n", data[0]);
        munmap (data, pagesize);


    return 0;
}
