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

void main()
{
	P2 = 0x00;
	while(1)
	{
		P2 = 0xAA;
		delay(1000);
		P2 = 0x55;
		delay(1000);
	}
}