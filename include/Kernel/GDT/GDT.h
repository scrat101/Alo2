#ifndef GDT 
#define GDT 


#include <stdint-gcc.h> 
#include <stddef.h> 

typedef struct __attribute__((packed)) { 
	uint16_t limit_low; 
	uint16_t base_low; 
	uint8_t base_middle; 
	uint8_t access; 
	uint8_t granularity; 
	uint8_t base_high; 
} gdt_entry_t; 

typedef struct __attribute__((packed)) { 
	uint16_t limit; /* size */ 
	uint32_t base; /* address */ 
} gdt_ptr_t; 

gdt_entry_t thegdt[3]; 
gdt_ptr_t thegdtptr; 


void assign_gdt(gdt_ptr_t agdtptr); /* Only needed when you install a new gdt; after that, any changes to the GDT will be registered */ 
void gdt_set_gate(gdt_entry_t *gdtentry, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity); 
void gdt_init(void); /* sets up a basic GDT */ 

#endif 