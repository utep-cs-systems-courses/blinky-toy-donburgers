#include <msp430.h>

#define INPUT_PIN BIT0  // P2.0
#define OUTPUT_PIN BIT4 // P1.4

void setup() {
    WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer

    P2DIR &= ~INPUT_PIN;  // Set P2.0 (input pin) to input direction
    P2REN |= INPUT_PIN;   // Enable P2.0 internal resistance
    P2OUT |= INPUT_PIN;   // Set P2.0 as pull-Up resistance

    P1DIR |= OUTPUT_PIN;  // Set P1.4 (output pin) to output direction
    P1OUT &= ~OUTPUT_PIN; // Initially set output pin to Low
}

void loop() {
    if((P2IN & INPUT_PIN) != 0) { // If input pin is HIGH
        P1OUT |= OUTPUT_PIN; // Set output pin to High
        __delay_cycles(50000); // Delay

        P1OUT &= ~OUTPUT_PIN; // Set output pin to Low
        __delay_cycles(50000); // Delay
    }
}

int main(void) {
    setup();

    while(1) { // Infinite loop
        loop();
    }
}
