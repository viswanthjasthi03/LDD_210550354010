#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xa11440c8, "module_layout" },
	{ 0x7a39daf9, "cdev_del" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x2686255, "cdev_add" },
	{ 0xe2a5af47, "cdev_alloc" },
	{ 0x3fd78f3b, "register_chrdev_region" },
	{ 0x51a910c0, "arm_copy_to_user" },
	{ 0x5f754e5a, "memset" },
	{ 0xae353d77, "arm_copy_from_user" },
	{ 0x2cfde9a2, "warn_slowpath_fmt" },
	{ 0xc5850110, "printk" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C1BB2142553B953E095F31D");
