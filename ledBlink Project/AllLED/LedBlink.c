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
		P0 = 0x00;
		delay(2000);
		P0 = 0xFF;
		delay(2000);
	}
}