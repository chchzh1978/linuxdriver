# 要编译这个模块，你需要有一个Linux内核源代码树，
# 并且在Makefile中指定内核源代码树的路径。然后，
# 你可以使用以下命令来编译模块：

#KERNEL_DIR ?= /opt/switch/sdk-esc_10.1.1_20230731/build/esc928/linux
KERNEL_DIR ?= /opt/linux/linux-4.15.10
obj-m := chardeviceexample.o
CROSS_COMPILE := /opt/switch/sdk-esc_10.1.1_20230731/build/esc928/compiletools/gcc-arm-8.3-2019.03-x86_64-aarch64-linux-gnu/bin/aarch64-linux-gnu-
ARCH := arm64


vpath %.c /home/yiyang/study/linuxdriver

.PHONE:all clean
all:	
#编译成功后，你可以使用insmod来安装模块，
#使用rmmod来卸载模块。你也可以通过mknod创建设备文件，
#然后使用cat或echo命令来读取设备内容或尝试写入。
	#make ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KERNEL_DIR) M=/home/yiyang/study/linuxdriver modules
	make -C $(KERNEL_DIR) M=/home/yiyang/study/linuxdriver modules
# 清理生成的文件
clean:
	make -C $(KERNEL_DIR) M=/home/yiyang/study/linuxdriver clean

