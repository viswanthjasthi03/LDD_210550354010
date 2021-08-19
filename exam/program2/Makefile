obj-m +=ioctl_driver.o
KDIR=/lib/modules/$(shell uname -r)/build/
PWD=$(shell pwd)

all:
	make -C $(KDIR) M=$(PWD) modules
	gcc -o ioctl ioctl.c
	gcc -o readapplication readapplication.c
	gcc -o writeapplication writeapplication.c

clean:
	make -C $(KDIR) M=$(PWD) clean
	rm -rf readapplication writeapplication ioctl
