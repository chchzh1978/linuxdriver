Jobs before this project:
1、prepare linux source code, you can download from official web site, and you shuold make sure the linux version shuold be same as the target;
2、copy the .config from target(the location is different for specified linux version, for example: /boot/config-XXX) to root directory of downloaded source code;
3、check Makefile in root directoy for the source code, make sure the linux version is same as other modules loaded in the target(you can use lsmod and modinfo to get the information);
4、use the make menuconfig to load the .config which is from 2 step;
5、compile the linux kernel, then change the KERNEL_DIR in Makefile of this project;
