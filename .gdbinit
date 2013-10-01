target remote localhost:1234
file rtos.elf

b DoScheduling
b InitTaskMain
b ContextSwitch

display/x $cpsr
display   currentTask
