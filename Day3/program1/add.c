#include<linux/init.h>
#include<linux/module.h>


static int add_init(void)
{
	printk("Hii\n");
	return 0;
}

static int my_add(int a, int b)
{
	return (a+b)/2;
}
EXPORT_SYMBOL(my_add);

static void add_cleanup(void)
{
	printk("Good Bye\n");
}

module_init(add_init);
module_exit(add_cleanup);

MODULE_LICENSE("GPL");
