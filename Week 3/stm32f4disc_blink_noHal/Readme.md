
### Addresses of the required registers: (cf . Reference manual)

Onboard LEDs are connected to the STM32 I/O PD12, PD13, PD14, PD15.

•	Address of the *Clock control register* (AHB1ENR) 
Base Address: 0x4002 3800  
Adress is 0x4002 3800 + 0x30 (Address offset: 0x30) --> **0x40023830**

•	GPIOD *control mode register* (to specify general purpose output mode):
GPIOD Base Address: 0x4002 0C00   
Address is 0x4002 0C00 + 0x00 (offset: 0x00) --> **0x40020C00**

•	GPIOD *output data register* (to write):  
Address is 0x4002 0C00 + 0x14 (offset: 0x14) --> **0x40020C14**


To prevent compilation errors:
In startup file, add at the end: **.weak SystemInit**

In Makefile:
- comment out USE_HAL_DRIVER
- source files: keep only startup .s file, and Src/main.c (or Core/Src/main.c)
- comment out and erase all other includes, header and source files
