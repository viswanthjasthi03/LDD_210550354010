#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/uaccess.h>


#define NAME Device

int flag = 1;
char Buff[80];
struct stats
{
 int size;
 char buff[];
 int r_w;
 };


dev_t Mydev;  
struct cdev *my_cdev;

int my_open(struct inode *inode, struct file *filp);
int my_close(struct inode *indoe, struct file *filp);
ssize_t my_write(struct file *filp, const char __user *Ubuff, size_t count, loff_t *offp);
ssize_t my_read(struct file *filp, char __user *Ubuff, size_t count, loff_t *offp);



struct file_operations fops = {
	
    .owner = THIS_MODULE,
    .open = my_open,
    .read = my_read,
    .write = my_write,
    .release = my_close,
    .unlocked_ioctl = my_ioctl,

};


int NAME_open(struct inode *inode, struct file *filp)
{
    printk(KERN_ALERT "This is the Kernel Open call...Inside Open system call\n");
    return 0;
}

ssize_t MY_read(struct file *filp, char __user *Ubuff, size_t count, loff_t *offp)
{
	printk(KERN_ALERT "Read function is Allocated :");
	return 0;
}


ssize_t my_write(struct file *flip, const char __user *Ubuff, size_t count, loff_t *offp)
{
	
	printk(KERN_ALERT "Inside Write\n");
}
long my_ioctl_fn(struct file *file_ioctl, unsigned int cmd,unsigned long arg)
{
return 0;
}


int my_close(struct inode *indoe, struct file *filp)
{
    printk(KERN_ALERT "\nThis is the Close System Call! closing the opend file...Bye to All..\n");
    return 0;
}

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

module_init(CharDevice_init);
module_exit(CharDevice_exit);

MODULE_LICENSE("GPL");
