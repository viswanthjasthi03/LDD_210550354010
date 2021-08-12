#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

static char *charvar = "viswanth";
static int intvar = 20;
module_param(charvar,charp,S_IRUGO);
module_param(intvar,int,S_IRUGO);

static int param_init(void)
{
	printk(KERN_ALERT "\n The value of the charvar is %s\n",charvar);
	printk(KERN_ALERT "\n The value of integer is %d\n",intvar);
	return 0;
}

static void param_cleanup(void)
{
	printk(KERN_ALERT "\n Good Bye\n");
}

module_init(param_init);
module_exit(param_cleanup);

MODULE_LICENSE("GPL");
