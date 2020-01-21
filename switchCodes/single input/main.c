#include<reg51.h>

sbit led=P2^0;
sbit sw =P2^7;
void delay(unsigned int count)
{
	unsigned int i;
	while(count)
	{
	i=115;
	while(i>0)
	i--;
	count--;
	}
	
}
void main()
{ 
	sw = 1;  
	led = 0;
	while(1)
	{
			if(sw==0)
			{
				led=1;
				delay(1000);
			}
			else
			{
				led=0;
			}

	}
}