/* To print kernel version, CPU type and model, information on configured memory ,amount of free and used memory*/

#include<stdio.h>
#include<stdlib.h>
main() {
	system("clear");

	printf("kernel version \n");
	system("cat /proc/sys/kernel/osrelease"); //os release = file

	printf("First version\ncpu mode1 \n");
	system("cat /proc/cpuinfo |awk 'NR==5{print}' ");

	printf("third version \n the amount of memory configured in system\n");
//print the 4th row of the meminfo file from the proc directory
//awk= filter nth row
	system("cat /proc/meminfo|awk 'NR==4{print} ' ");

	printf(" \n amt of mem currently available \n");
	system("cat /proc/meminfo|awk 'NR==5{print} ' ");

	printf("\nAmount of time lastn booted \n");
	system("cat /proc/uptime");

	printf("\nthe amount of time cpu spent in user mode, system mode, idle time\n");
	system("cat /proc/stat|awk 'NR==1{print}'\n ");

	printf("\nNumber of disk request made on system\n");
	system("cat /proc/stat|awk 'NR==2{print}'\n ");

	printf("\nNumber of context switches kernel performed\n");
	system("cat /proc/stat|awk 'NR==4{print}'\n ");

	printf("\n time at which system was last booted\n");
	system("cat /proc/stat|awk 'NR==5{print}'\n ");

	exit(0);
}
