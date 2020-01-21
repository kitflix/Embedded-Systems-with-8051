#include<reg51.h>
sbit rs = P1^0;
sbit en = P1^1;

// copy paste this in every code
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

void lcd_data(unsigned char abc)
{
	rs = 1;
	P2 = abc;
	en = 1;
	delay(50);
	en = 0;
}
void lcd_cmd(unsigned char abc)
{
	rs = 0;
	P2 = abc;
	en = 1;
	delay(50);
	en = 0;
}
void lcd_init()
{
		lcd_cmd(0x38);        //LCD 4-bit mode and 2 lines.
		lcd_cmd(0x01);
		lcd_cmd(0x06);
		lcd_cmd(0x0E);
		lcd_cmd(0x80);
		lcd_cmd(0x0C);
}
void lcd_clear()
{
		lcd_cmd(0x01);
}
void lcd_cursor(char row, char column)	
{
		switch (row) 
		{
				case 1: lcd_cmd(0x80 + column - 1); break;
				case 2: lcd_cmd(0xc0 + column - 1); break;
				case 3: lcd_cmd(0x94 + column - 1); break;
				case 4: lcd_cmd(0xd4 + column - 1); break;
				default: break;
		}
}
void lcd_out(char row, char column, char *str)// lcd_out(1,1,451);
{
		lcd_cursor(row, column);
		while(*str != '\0')
		{
				lcd_data(*str);
				str++;
		}
}

void lcd_print(char row, char coloumn, unsigned int value, int digits)
{
		unsigned int temp;
		unsigned int unit;
		unsigned int tens;
		unsigned int hundred;
		unsigned int thousand;
		unsigned int million;
		unsigned char flag=0;

		if(row==0||coloumn==0)
		{
				lcd_cmd(0x80);
		}
		else
		{
				lcd_cursor(row,coloumn);
		}
		if(digits==5 || flag==1)
		{
				million=value/10000+48;
				lcd_data(million);
				flag=1;
		}
		if(digits==4 || flag==1)
		{
				temp = value/1000;
				thousand = temp%10 + 48;
				lcd_data(thousand);
				flag=1;
		}
		if(digits==3 || flag==1)
		{
				temp = value/100;
				hundred = temp%10 + 48;
				lcd_data(hundred);
				flag=1;
		}
		if(digits==2 || flag==1)
		{
				temp = value/10;
				tens = temp%10 + 48;
				lcd_data(tens);
				flag=1;
		}
		if(digits==1 || flag==1)
		{
				unit = value%10 + 48;
				lcd_data(unit);
		}
		if(digits>5)
		{
				lcd_data('E');
		}        
}
void main()
{
	int count = 0;
	lcd_init();
	lcd_out(1,1,"Welcome");
	delay(1000);
	lcd_clear();
	while(1)
	{	
		lcd_out(1,1,"Seconds:");
		lcd_print(2,1,count,2);	// 0035
		count++;
		delay(1000);
	}
}