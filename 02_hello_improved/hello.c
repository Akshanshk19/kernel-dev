#include <linux/module.h>
#include <linux/init.h>

static int __init my_init(void){
	printk("load\n");
	return 0;
}

static void __exit my_exit(void){
	printk("unload\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("AK");
MODULE_DESCRIPTION("SIMPLE KERNEL MODULE");
