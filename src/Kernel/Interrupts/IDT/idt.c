#include "../../../../include/Kernel/Interrupts/IDT/idt.h" 

void idt_set_gate(idt_entry_t *ptr, uint32_t base, uint16_t sel, uint8_t flags) { 
	ptr->base_low = (uint16_t)(base & 0xFFFF); 
	ptr->base_high = (uint16_t)((base & 0xFFFF0000) >> 16); 
	ptr->sel = sel; 
	ptr->alwayssettozero = 0; 
	ptr->flags = flags; 
}; 


void idt_init(void) { 
	theidtptr.limit = (sizeof(idt_entry_t) * 256) - 1; 
	theidtptr.base = &idt; 
	
	for (size_t i = 0; i < ((sizeof (idt_entry_t) * 256) - 1); i++) { 
		*((uint8_t*)&idt) = 0; 
	}; 

	load_idt(theidtptr); 
}; 

