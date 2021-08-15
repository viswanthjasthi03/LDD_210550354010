#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/uaccess.h>

#define NAME MyCharDevice

int flag = 1;
char Buff[80];
char Kbuff[80];
char Ubuff[80];

dev_t Mydev;  
int NAME_open(struct inode *inode, struct file *filp);
int NAME_release(struct inode *indoe, struct file *filp);
ssize_t NAME_write(struct file *filp, const char __user *Ubuff, size_t count, loff_t *offp);
ssize_t NAME_read(struct file *filp, char __user *Ubuff, size_t count, loff_t *offp);

struct file_operations fops = {
	
    .owner = THIS_MODULE,
    .open = NAME_open,
    .read = NAME_read,
    .write = NAME_write,
    .release = NAME_release,

};

struct cdev *my_cdev;

static int __init CharDevice_init(void)
{
    int result;  
    Mydev = MKDEV(255,0); 
    printk(KERN_ALERT "Inside the CharDevice init region\n");
    result = register_chrdev_region(Mydev,1,"MyCharDevice"); 
    if(result<0)
    {
        printk(KERN_ALERT "\nThe region requested for is not obtainable\n");
        return (-1);
    }

    my_cdev = cdev_alloc(); 
    my_cdev->ops = &fops; 
    result = cdev_add(my_cdev,Mydev,1); 
    if(result<0)
    {
        printk(KERN_ALERT "\nThe char device has not been created....\n");
        unregister_chrdev_region(Mydev,1);
        return(-1);
    }
    return 0;
}

void __exit CharDevice_exit(void)
{
    
    printk(KERN_ALERT "Inside the CharDevice exit region\n");
    unregister_chrdev_region(Mydev,1); 
    cdev_del(my_cdev);
    printk(KERN_ALERT "\nI have unregistered the stuff that was allocated...Goodbye forever..\n");
    return;
}

int NAME_open(struct inode *inode, struct file *filp)
{
    printk(KERN_ALERT "This is the Kernel Open call...Inside Open system call\n");
    return 0;
}

ssize_t NAME_read(struct file *filp, char __user *Ubuff, size_t count, loff_t *offp)
{
	unsigned long int result;
	ssize_t retval;

	
	printk(KERN_ALERT "Inside Read\n");
	result = copy_to_user((char*)Ubuff,(char*)Buff,count);
	if(result!=0)
	{
		printk(KERN_ALERT "Data not copied\n");
		retval = -EFAULT;
		return retval;
	}
	else
	{
		flag = 1;
		printk(KERN_ALERT "Reading data\n");
		retval = count;
		return retval;
	}
	
	return 0;
}

ssize_t NAME_write(struct file *flip, const char __user *Ubuff, size_t count, loff_t *offp)
{
	unsigned long result;
	ssize_t retval;
	printk("In write...shortly to write data\n");
	result = copy_from_user((char*)Buff,(char*)Ubuff, count);
	if(result!=0)
	{
		printk(KERN_ALERT "Message from User is >>>>>%s<<<<<<\n",Buff);
		retval = count;
		flag=0;
		return retval;
	}
	else
	{
		printk(KERN_ALERT "Some Problem in Write\n");
		retval = -EFAULT;
		return retval;
	}
	printk(KERN_ALERT "Inside Write\n");
}

int NAME_release(struct inode *indoe, struct file *filp)
{
    printk(KERN_ALERT "\nThis is the Close System Call! closing the opend file...Bye to All..\n");
    return 0;
}

module_init(CharDevice_init);
module_exit(CharDevice_exit);

MODULE_LICENSE("GPL");

