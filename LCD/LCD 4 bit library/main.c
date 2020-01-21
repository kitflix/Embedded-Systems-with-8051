#include <REG51.H>
#include "lcd.c"


int a = 0;
void main()
{
		lcd_init();
		lcd_out(1,1,"LCD Test");
		
		while(1)
		{				                    //Forever loop
			lcd_print(2,1,a,5);
			a = a + 1;
			delay_ms(100);
    }
}