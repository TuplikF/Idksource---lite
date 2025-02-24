void kernel_main(void) {
    // Your kernel code here
    // For example, a simple "Hello, world!" print to the screen
    char* video_memory = (char*)0xB8000;
    const char* str = "Hello, world!";
    while (*str) {
        *video_memory++ = *str++;
        *video_memory++ = 0x07; // Attribute-byte: light grey on black screen
    }
    while (1); // Infinite loop to keep the kernel running
}