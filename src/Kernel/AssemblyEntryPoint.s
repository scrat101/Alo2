 .intel_syntax noprefix 
 
 # Declare constants used for creating a multiboot header.
.set ALIGN,    1<<0             # align loaded modules on page boundaries
.set MEMINFO,  1<<1             # provide memory map
.set FLAGS,    ALIGN | MEMINFO  # this is the Multiboot 'flag' field
.set MAGIC,    0x1BADB002       # 'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS) # checksum of above, to prove we are multiboot

# Declare a header as in the Multiboot Standard. We put this into a special
# section so we can force the header to be in the start of the final program.
# You don't need to understand all these details as it is just magic values that
# is documented in the multiboot standard. The bootloader will search for this
# magic sequence and recognize us as a multiboot kernel.
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM
 
 
#Here is the stack part: 

.section .TheStack, "aw", @nobits 
stack_bottom: 
.skip 32768 # 32 kilobytes. 
stack_top: 


# Here is our entry point! 

.section .text 
.global _start 
.type _start, @function 
_start: 
	.att_syntax prefix
	movl $stack_top, %esp #For some reason, when I do the intel equivalent "mov esp, stack_top", it tries to assign to esp the VALUE of the address of stack_top, not the address itself (GAS has some problems!)
	.intel_syntax noprefix 
	push ebx 
	call Alo_Main 
	pop ebx 
	call DivideByZero #This is me testing my processor exception handling code by making it divide by zero; delete it if you want! 
	cli #This should put the computer in an infinite loop. In multiprocessor systems this may be more complicated, but we are just going to assume there is just one processor for now 
	hlt 
	.InfiniteLoop: 
		jmp .InfiniteLoop 
		
		
.size _start, . - _start  
