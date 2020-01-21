#include<reg51.h>
sbit red = P2^0;
sbit yellow = P2^1;
sbit green = P2^2;
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
		red = 1;
		delay(10000);
		red = 0;
		yellow = 1;
		delay(5000);
		yellow = 0;
		green = 1;
		delay(8000);
		green = 0;
	}
}