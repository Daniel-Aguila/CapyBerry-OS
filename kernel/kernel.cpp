#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Check if the compiler thinks you are targeting the wrong operating system */

#if defined(__linux__)
#error  "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

#if !defined(__x86_64__)
#error "This tutorial needs to be compiled with a x86_64-elf compiler"
#endif

/* 4 Bits for color: 2^4 = 16 colors: I | R | G | B   intensity, red, green, blue */

enum vga_color {
    VGA_COLOR_BLACK = 0,
    VGA_COLOR_BLUE = 1,
    VGA_COLOR_GREEN = 2,
    VGA_COLOR_CYAN = 3,
    VGA_COLOR_RED = 4,
    VGA_COLOR_MAGENTA = 5,
    VGA_COLOR_BROWN = 6,
    VGA_COLOR_LIGHT_GREY = 7,
    VGA_COLOR_DARK_GREY = 8,
    VGA_COLOR_LIGHT_BLUE = 9,
    VGA_COLOR_LIGHT_GREEN = 10,
    VGA_COLOR_LIGHT_CYAN = 11,
    VGA_COLOR_LIGHT_RED = 12,
    VGA_COLOR_LIGHT_MAGENTA = 13,
    VGA_COLOR_LIGHT_BROWN = 14,
    VGA_COLOR_WHITE = 15
};

static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg){
    /* we send the bg to the first four */
    return static_cast<uint8_t>(fg | (bg << 4));
}

static inline unit16_t vga_entry(unsigned char uc, unit8_t color){
    return (uint16_t) uc | (uint16_t) color << 8;
}

size_t strlen(const char* str){
    size_t len = 0;
    while(str[len])
        len++;
    return len;
}

void kernel_main(void){
    
}
