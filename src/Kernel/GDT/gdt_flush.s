.intel_syntax noprefix 

.global assign_gdt
.type assign_gdt, @function 
assign_gdt: 
	lgdt [esp + 4] # should load our GDT ptr; since after the gdt pointer was pushed onto the stack GCC automatically put in a 32 bit return address, the gdt pointer resides at "esp + 4" to "esp + 9", due to the fact that it is a 48 bit structure! 
	mov ax, 0x10 #Lets reload the registers now; since a GDT entry is 64 bit, and our data descriptor is the third one, it makes it so the third descriptor starts at 0x10 in the GDT. 
	mov ds, ax 
	mov es, ax
	mov fs, ax
	mov gs, ax  
	mov ss, ax 
	jmp 0x08:Section2 #Code descriptor, same reason why you use 0x08 as you use 0x10 for the other thing, except for the fact that the code descriptor is the second entry! 
Section2: 

	ret 

