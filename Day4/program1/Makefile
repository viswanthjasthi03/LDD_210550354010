obj-m +=chardevice.o
KDIR=/lib/modules/$(shell uname -r)/build/
PWD=$(shell pwd)

all:
	make -C $(KDIR) M=$(PWD) modules
	gcc -o application application.c
clean:
	make -C $(KDIR) M=$(PWD) clean
	rm application

install:
	$(MAKE) -c $(KDIR) M=$(PWD)
