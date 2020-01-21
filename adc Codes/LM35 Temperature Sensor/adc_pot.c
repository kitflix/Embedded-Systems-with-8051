#include <REG51.H>
#include "lcd.c"

sbit rd = P3^5;                  //Read signal 
sbit wr = P3^6;                  //Write signal 
sbit intr = P3^7;                //INTR signal 

unsigned char adc_val;		// 8 - bit read the adc
unsigned int mv;		// 16 bit read or calculate the voltage

void conv();                     //Start of conversion function
void read();                     //Read ADC function

unsigned int temp;
void main()
{
    delay_ms(100);
		intr = 1;	// make this pin work as INPUT
		lcd_init();
		lcd_out(1,1,"Temp:");
		lcd_out(2,1,"Voltage: ");		// mV
		
		
		while(1)
		{				                    //Forever loop
			conv();                  //Start conversion
			read();   
		 		
			lcd_print(1,6,adc_val,4);		// 0 - 255
			
			//mv = adc_val * 10;	//  use it when using LM35
			
			//temp = mv / 10;
			
			//lcd_print(2,13,mv,4);
			
    }
}

void conv()
{  
        wr = 0;                      //Make WR low
        wr = 1;                      //Make WR high
        while(intr == 1)
				{
				
				}
}

void read()	 		// function to read the Analog to digital converted value
{

        rd = 1;                      //Make RD low
        rd = 0;
        adc_val = P1;          //Read ADC port
		    delay_ms(250);
        rd = 1;                      //Make RD high
}
