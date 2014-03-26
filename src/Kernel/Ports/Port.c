#include "../../../include/Kernel/Ports/Port.h" 

uint8_t inportb(uint16_t port) { 
	uint8_t res; 
	__asm__ __volatile__ ("inb %1, %0" : "=a" (res) : "dN" (port)); 
	return res; 
}; 

void outportb(uint16_t port, uint8_t byte) { 
	__asm__ __volatile__ ("outb %1, %0" : : "dN" (port), "a" (byte)); 
}; 

void io_wait(void) { 
	asm volatile ("outb %%al, $0x80" : : "a"(0)); 
}; 