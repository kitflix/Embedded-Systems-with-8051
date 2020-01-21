#include<reg51.h>

sbit led =P2^0;
sbit sw1 =P2^7;
sbit sw2 =P2^6;
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
	sw1 = 1;  
	sw2 = 1;
	while(1)
	{
			if(sw1==0 && sw2==0)
			{
				led=1;
			}
			else
			{
				led=0;
			}

	}
}