#ifndef ISR 
#define ISR 
#include "../IDT/idt.h" 
#include <stdint-gcc.h> 
#include "../../BasicVGA/BasicVGA.h" 

void isr0(void);
void isr1(void);
void isr2(void);
void isr3(void);
void isr4(void);
void isr5(void);
void isr6(void);
void isr7(void);
void isr8(void);
void isr9(void);
void isr10(void);
void isr11(void);
void isr12(void);
void isr13(void);
void isr14(void);
void isr15(void);
void isr16(void);
void isr17(void);
void isr18(void);
void isr19(void);
void isr20(void);
void isr21(void);
void isr22(void);
void isr23(void);
void isr24(void);
void isr25(void);
void isr26(void);
void isr27(void);
void isr28(void);
void isr29(void);
void isr30(void);
void isr31(void); 

/* This defines what the stack looks like after an ISR was running */
typedef struct __attribute__((packed))
{
    uint32_t gs, fs, es, ds;      /* pushed the segs last */
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;  /* pushed by 'pusha' */
    uint32_t int_no, err_code;    /* our 'push byte #' and ecodes do this */
    uint32_t eip, cs, eflags, useresp, ss;   /* pushed by the processor automatically */ 
} fault_regs_t; 

static uint8_t *msgs[] = { 
	"Divide by Zero", 
	"Debug", 
	"Non Maskable interrupt", 
	"Breakpoint", 
	"Into Detected Overflow", 
	"Out of Bounds", 
	"Invalid Opcode", 
	"No coprocessor", 
	"Double Fault", 
	"Coprocessor Segment Overrun", 
	"Bad TSS", 
	"Segment not present", 
	"Stack Fault", 
	"GPF", 
	"Page Fault", 
	"Unknown Interrupt", 
	"Coprocessor fault", 
	"Alignment check", 
	"Machine check", 
	"Reserved" 
}; 

void isr_fault_handler(fault_regs_t registers); 
void isrs_init(void); 
#endif