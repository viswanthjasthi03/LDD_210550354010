#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int FileDesc;
	char Ubuff[] = "This is the User Buffer.....Sending Data to the Kernel ...";
	char Kbuff[100];
	FileDesc = open("/dev/MyCharDevice", O_RDWR, 0777);
	if(FileDesc < 0)
	{
		printf("\nError Opennning Device\n");
		exit(1);
	}
	
	close(FileDesc);
}

