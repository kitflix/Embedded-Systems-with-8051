#include<reg51.h>
#include "lcd.c"
void delay(unsigned int count)
{
	unsigned int i;
	while(count)
	{
		i = 115;
		while(i > 0)
			i--;
		count--;
	}
}

void main()
{
	int count = 0;
	lcd_init();
	lcd_out(1,1,"Timer as Counter");
	TMOD = 0x05;	//0000 0101
	TH0 = 0x00;
	TL0 = 0x00;
	TR0 = 1;
	while(1)
	{	
		count = TL0;
		lcd_print(2,1,count,3);
		delay(200);
	}

}