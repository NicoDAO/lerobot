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
int main(int argc, char *argv[])
{
    int offset;
    int *data;
    struct stat sbuf;
    int adress = 0;
    //sscanf(argv[1],"%d",&adress);
    adress = strtoul(argv[1], NULL, 0);
    // Truncate offset to a multiple of the page size, or mmap will fail.
    size_t pagesize = 20;// sysconf(_SC_PAGE_SIZE);
    off_t page_base = (adress / pagesize) * pagesize;
    off_t page_offset = adress - page_base;
    printf("$$lecture memoire a l'adresse %x, taille = %d \n",adress,pagesize);
    if (argc != 2)
    {
        printf( "usage: mmapdemo offset\n");
        exit(1);
    }
    int fd = open("/dev/mem", O_RDWR);
  printf("ouverture  /dev/mem");
 
    if (fd  == -1)
        printf(1, "open");
    // data = mmap(adress,pagesize	,PROT_READ | PROT_WRITE, MAP_SHARED | MAP_PRIVATE | MAP_POPULATE,     fd, 0);
    while(1)
    {
        data = mmap(NULL, pagesize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, (off_t)adress);
        if (data == MAP_FAILED)
        {
            perror("mmap error");
        }
        /*  for(int i = 0; i < 10; i++)
         {
           printf("[%lu]=%X ", i, data[i]);
         }*/
        printf("distance capteur : %d\r\n", data[0]);
        munmap (data, pagesize);
        sleep(1);
    }
    return 0;
}
