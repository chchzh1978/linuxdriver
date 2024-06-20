#include <linux/module.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/slab.h>
 
#define DEVICE_NAME "hello_world"
#define BUF_LEN 80
 
static char *data = NULL;
 

static ssize_t hello_read(struct file *filp, char __user *buf, size_t size, loff_t *ppos) {
    return simple_read_from_buffer(buf, size, ppos, data, strlen(data));
}

static ssize_t hello_write(struct file *filp, const char __user *buf, size_t size, loff_t *ppos) {
    return -EINVAL;
}

static const struct file_operations fops = {
    .owner = THIS_MODULE,
    .read = hello_read,
    .write = hello_write,
};

static int __init hello_init(void) {
    int ret = 0;
    data = kmalloc(BUF_LEN, GFP_KERNEL);
    if (!data) {
        ret = -ENOMEM;
        goto out;
    }
    snprintf(data, BUF_LEN, "Hello, world!\n");
 
    ret = register_chrdev(0, DEVICE_NAME, &fops);
    if (ret < 0) {
        pr_alert("Registering the device failed with %d\n", ret);
        goto out_free;
    }
 
    pr_info("Registered device %s, major number %d\n", DEVICE_NAME, ret);
    return 0;
 
out_free:
    kfree(data);
out:
    return ret;
}
 
static void __exit hello_exit(void) {
    unregister_chrdev(0, DEVICE_NAME);
    kfree(data);
    pr_info("Goodbye, world!\n");
}
  
module_init(hello_init);
module_exit(hello_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple Hello World kernel module");
