#include <reg51.h>
sbit OUTPUT_PIN = P1^0 ;
sbit TMR_INTERRUPT = TCON^5; 
sbit TMR_START = TCON^4;

void delay_20ms()
{
		//Run timer for 20000us
		TH1 = 0xB1;  //Load register to count 20,000us = 20 ms
		TL1 = 0xE0;
		TMR_START = 1;  //Start timer
		while(TMR_INTERRUPT == 0){}  //Wait until timer interrupt occurs
		TMR_START = 0;   //Stop timer
		TMR_INTERRUPT = 0;  //CLear interrupt flag
}
void main()
{
			TCON = 0x00;   
			TMOD = 0x01;  //Timer 0 in mode 1
			P1 = 0; //Set P1 as output
			while(1){
				OUTPUT_PIN = 0;
				delay_20ms();
				OUTPUT_PIN = 1;
				delay_20ms();
			}
			
}