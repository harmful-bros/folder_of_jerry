#include <linux/module.h>

static int __init _hello_world_init(void)
{
	pr_info("Hellow World\n");
	return 0;
}

static void __exit _hello_world_cleanup(void)
{
	pr_info("Goodbye World\n");
}

module_init(_hello_world_init);
module_exit(_hello_world_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Lee, Jerry J");
MODULE_DESCRIPTION("A simple hello world kernel module");
MODULE_INFO(board, "Beaglebone black REV A5");
