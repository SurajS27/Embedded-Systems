#include <reg51.h>

void init_serial() {
    TMOD = 0x20;  // Set Timer 1 in Mode 2
    TH1 = 0xFD;   // Set baud rate to 9600 bps
    SCON = 0x50;  // Enable serial communication
    TR1 = 1;      // Start Timer 1
}

void send_char(char c) {
    SBUF = c;     // Load character into buffer
    while(TI == 0); // Wait until transmission is complete
    TI = 0;       // Clear transmit interrupt flag
}

void send_string(char *str) {
    while(*str) {
        send_char(*str++);
    }
}

void main() {
    char *number = "20BCE10690"; // The number to be sent
    init_serial(); // Initialize serial communication
    while(1) { // Continuously send the number
        send_string(number);
    }
}