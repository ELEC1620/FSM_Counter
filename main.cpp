/*  FSM Counter Example
*   Operate an RGB LED using a finite state machine. 
*
*   Board: NUCLEO L476RG
*   Author: Dr Craig Evans
*	Editied: Andrew Knowles 2022
*	MBED OS: 6.14
*/


#include "mbed.h"
 
//led colours    R      B      G
BusOut RGB_LED(PA_15, PA_14, PA_13); //define output bus pins 

void init_led();

int g_fsm[4] = {0b000,0b001,0b010,0b100};
int state = 0;

int main(){
	init_led();
 
    while(1) {  // loop forever
        RGB_LED = g_fsm[state];  // output current state
 
        // check which state we are in and see which the next state should be
        switch(state) {
            case 0:
                state = 1;
                break;
				
            case 1:
                state = 2;
                break;
				
            case 2:
                state = 3;
                break;
				
            case 3:
                state = 0;
                break;
				
            default:
                error("Invalid state");
                state = 0; //invalid state - call error routine
                // and jump to starting state i.e. state = 0
                break;
        }
 
        ThisThread::sleep_for(500ms);  // 500 ms delay
    }
}

void init_led(){
    RGB_LED.write(0);   //turn off all leds by writing the decimal equivalent of 0b111
}
