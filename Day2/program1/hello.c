#include<linux/module.h>
#include<linux/init.h>

static int hello_init(void)
{
	printk("Hello World\n");
	return 0;

}

static void hello_cleanup(void)
{
	printk("Good Bye\n");
}

module_init(hello_init);
module_exit(hello_cleanup);

MODULE_LICENSE("GPL");
