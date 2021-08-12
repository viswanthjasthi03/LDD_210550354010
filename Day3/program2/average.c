#include<linux/init.h>
#include<linux/module.h>
#include "header.h"

static int a=10;
static int b=20;

module_param(a,int,S_IRUGO);
module_param(b,int,S_IRUGO);

static int average_init(void)
{
	printk("The average of two numbers is %d\n",my_add(a,b));
	return 0;
}

static void average_cleanup(void)
{
	printk("Good Bye\n");
}

module_init(average_init);
module_exit(average_cleanup);

MODULE_LICENSE("GPL");
