
## Addresses of the registers: (cf . Reference manual)

Onboard LEDs are connected to the STM32 I/O PD13, PD14, PD15, PD16.

•	Address of the Clock control register (AHB1ENR) 
Base Address: 0x4002 3800 
0x4002 3800 + 0x30 (Address offset: 0x30) --> **0x40023830**

•	GPIOD Control mode register:
GPIOD Base Address: 0x4002 0C00 
Address is 0x4002 0C00 + 0x00 (offset: 0x00) --> **0x40020400**

•	GPIOD output data register (used to write):
Address is 0x4002 0C00 + 0x14 (offset: 0x14) --> **0x40020C14**
