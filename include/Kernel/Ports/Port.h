#ifndef PORT 
#define PORT 


#include <stdint-gcc.h> 

void outportb(uint16_t port, uint8_t byte); 
uint8_t inportb(uint16_t port); 
void io_wait(void); 

#endif 

