#include <kernel.h> 
#include <scheduler.h>
#include <task.h>
#include <event.h>


int Task0Main(void *args);
int Task1Main(void *args);
int Task2Main(void *args);


struct TaskStruct task0, task1, task2;
unsigned char taskStack0[4096], taskStack1[4096], taskStack2[4096];
struct EventStruct event;


int InitTaskMain(void *args) {
	printf("init task start..........\n");

	TaskInit(&task0, Task0Main, 0, 10, 5, taskStack0, sizeof(taskStack0));
	TaskInit(&task1, Task1Main, 0, 10, 7, taskStack1, sizeof(taskStack1));
	TaskInit(&task2, Task2Main, 0, 10, 10, taskStack2, sizeof(taskStack2));

	return 0;
}


int Task0Main(void *args) {
	while (1) {
		unsigned int loop;
		for (loop=0x08ffffffu; loop>0; loop--);

		printf("Task : 0\n");
		//TaskYield();
	}

	return 0;
}


int Task1Main(void *args) {
	while (1) {
		unsigned int loop;
		for (loop=0x08ffffffu; loop>0; loop--);

		printf("Task : 1\n");
		//TaskYield();
	}

	return 0;
}


int Task2Main(void *args) {
	while (1) {
		unsigned int loop;
		for (loop=0x08ffffffu; loop>0; loop--);

		printf("Task : 2\n");
		//TaskYield();
	}

	return 0;
}

