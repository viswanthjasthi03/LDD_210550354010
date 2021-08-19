#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include "ioctl.h"



int main()
{
	int fd;

	fd = open("/dev/MyIoctlCalDevice",O_RDWR,0777); 
	if(fd<0)
	{
		printf("not able to open the device\n");
		return -1;
	}
	close(fd); //close the file descriptor
	return 0;
}

