#include<reg51.h>
// for 11.0592MHz Crystal
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
sbit led1 = P2^0;
void main()
{
	P2 = 0x00;
	while(1)
	{
		led1 = 0;
		delay(500);
		led1 = 1;
		delay(500);
	}
}