#include<reg51.h>
sbit led=P1^0;              //connect one led to p1.0 
/*void delay(unsigned int count)
{
	unsigned int i;
	while(count)
	{
		i = 115;
		while(i > 0)
		i--;
		count--;
	}
}*/

void timer_delay()
{
	int i;
	for(i = 0; i < 1000; i++)
	{
		TMOD = 0x01;
		TH0 = 0xFC;	//64441
		TL0 = 0x17;
		TR0 = 1;				// 1111	1111 1111	1111
		while(TF0 == 0);
		TF0 = 0;	
		TR0 = 0;
	}
}

void main()
{
	while(1)
	{
		led = 0;
		timer_delay();
		led = 1;
		timer_delay();
	}
}