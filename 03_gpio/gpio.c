#include <linux/module.h>
#include <linux/init.h>
#include <linux/gpio/consumer.h>

static struct gpio_desc *led, *button;

#define io_led 21
#define io_button 20
#define io_offset 569

static int __init my_init(void){
	int status;
	led=gpio_to_desc(io_led + io_offset);
	if(!led){
			printk("gpioctrl - error getting pin 21\n");
			return -ENODEV;
	}

	button=gpio_to_desc(io_button + io_offset);
	if(!button){
			printk("gpioctrl - error getting pin 20\n");
			return -ENODEV;
	}

	status =  gpiod_direction_output(led, 0);
	if(status){
		printk("gpioctrl - error setting pin 20 to output\n");
		return status;
	}

	status =  gpiod_direction_output(button, 0);
	if(status){
		printk("gpioctrl - error setting pin 21 to input\n");
		return status;
	}

	gpiod_set_value(led, 1);
	printk("gpioctrl - Button is %spreesed\n",gpiod_get_value(button)?"":"not ");
	return 0;
}

static void __exit my_exit(void){
	gpiod_set_value(led,0);
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("AK");
MODULE_DESCRIPTION("GPIO without device tree");
