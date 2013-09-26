target remote localhost:1234
file rtos.elf

b KernelMain
b TaskExit

display currentTask

watch currentTask
