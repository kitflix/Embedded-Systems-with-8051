#include<reg51.h>

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

void fwd()
{
		P2 = 0x0C;
		delay(100);
		P2 = 0x06;
		delay(100);
		P2 = 0x03;
		delay(100);
		P2 = 0x09;
		delay(100);
}
void rev()
{
		P2 = 0x09;
		delay(100);
		P2 = 0x03;
		delay(1000);
		P2 = 0x06;
		delay(100);
		P2 = 0x0C;
		delay(100);
}
void main()
{
	while(1)
	{
			fwd();
			delay(500);
		
		  rev();
		  delay(500);
		
		
	}
	
}