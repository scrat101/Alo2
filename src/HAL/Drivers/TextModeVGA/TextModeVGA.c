#include <HAL/Drivers/TextModeVGA/TextModeVGA.h> 

static uint8_t generate_color(VGA_color foreground, VGA_color background) { 
	return foreground | (background << 4) ; 
}; 

static uint16_t make_entry(char character, uint8_t  color) { 
	uint16_t res = ((uint16_t)character) | (color << 8); 
	return res; 
}; 

void TextModeVGA_putentry(char c, VGA_color foreground,  VGA_color background, size_t x, size_t y) { 
	TextModeVGA_Buffer[(((TextModeVGA_Width) * y) + x)] = make_entry(c, generate_color(foreground, background)); 
}; 	

