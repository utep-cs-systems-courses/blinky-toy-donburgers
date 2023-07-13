#define INPUT_PIN BIT0  // P2.0
#define OUTPUT_PIN BIT4 // P1.4

#define WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer
#define P2DIR &= ~INPUT_PIN;  // Set P2.0 (input pin) to input direction
#define P2REN |= INPUT_PIN;   // Enable P2.0 internal resistance
#define P2OUT |= INPUT_PIN;   // Set P2.0 as pull-Up resistance

#define P1DIR |= OUTPUT_PIN;  // Set P1.4 (output pin) to output direction
#define P1OUT &= ~OUTPUT_PIN; // Initially set output pin to Low

#endif
