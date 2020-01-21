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
sbit in1 = P2^0;
sbit in2 = P2^1;
sbit en1 = P2^2;
sbit en2 = P2^3;
sbit in3 = P2^4;
sbit in4 = P2^5;

void main()
{
	in1 = 0;
	in2 = 0;
	in3 = 0;
	in4 = 0;
	en1 = 1;
	en2 = 1;
	while(1)
	{
		in1 = 1;
		in2 = 0;
		
		in3 = 0;
		in4 = 1;
		delay(2000);
		
		
		in1 = 0;
		in2 = 0;
		in3 = 0;
		in4 = 0;
		delay(100);
		
		in1 = 0;
		in2 = 1;
		in3 = 1;
		in4 = 0;
		delay(2000);
		
		
		in1 = 0;
		in2 = 0;
		in3 = 0;
		in4 = 0;
		delay(100);
		
		
	}
	
}