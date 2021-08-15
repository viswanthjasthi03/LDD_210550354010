#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/uaccess.h>

#define NAME MYCharDevice


dev_t Mydev;  
int NAME_open(struct inode *inode, struct file *filp);
int NAME_release(struct inode *indoe, struct file *filp);


struct file_operations fops = 
{
    .owner = THIS_MODULE,
    .open = NAME_open,
    .release = NAME_release,  
};

struct cdev *my_cdev;
static int __init CharDevice_init(void)
{
    int result;
    int MAJOR, MINOR;
    Mydev = MKDEV(255,0); 
    MAJOR = MAJOR(Mydev);
    MINOR = MINOR(Mydev);
    printk(KERN_ALERT "Inside the CharDevice init Section\n");
    printk("The Major number is %d...The Minor number is %d\n", MAJOR,MINOR);
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
    printk(KERN_ALERT "Inside the CharDevice exit section\n");
    unregister_chrdev_region(Mydev,1); 
    cdev_del(my_cdev);
    printk("\nReleasing the resources that was allocated....\n");
    return;
}

int NAME_open(struct inode *inode, struct file *filp)
{
    printk(KERN_ALERT "This is the Kernel Open call...Inside Open system call\n");
    return 0;
}

int NAME_release(struct inode *indoe, struct file *filp)
{
    printk(KERN_ALERT "\nThis is the Kernel Close Call...Closing the Open File...Bye to All \n");
    return 0;
}
module_init(CharDevice_init);
module_exit(CharDevice_exit);

MODULE_LICENSE("GPL");

