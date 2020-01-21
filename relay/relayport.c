#include<reg51.h>

sbit relay = P2^0;
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
	
	relay = 1;
	delay(1000);
	
	relay = 0;
	delay(1000);
}