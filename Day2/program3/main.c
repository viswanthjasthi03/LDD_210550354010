#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/moduleparam.h>

static int var1 = 10;
static int var2 = 5;
static char* charvar = 'a';

module_param(var1, int, S_IRUGO);
module_param(var2, int, S_IRUGO);
module_param(charvar, charp, S_IRUGO);


static int param_init(void)
{

	printk("hello\n");
	
	if(*charvar=='a')
	{
		printk("Sum is %d\n",var1+var2);
	}
	else if(*charvar=='s')
	{
		printk("Difference is %d\n",var1-var2);
	}
	else if(*charvar=='m')
	{
		printk("product is %d\n",var1*var2);

	}
	else if(*charvar=='d')
	{
		printk("Division is %d\n",var1/var2);
	}
	return 0;

}
static void param_cleanup(void)
{
	printk("Goodbye\n");

}

module_init(param_init);
module_exit(param_cleanup);

MODULE_LICENSE("GPL");
