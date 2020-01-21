#include <reg51.h>
sbit led = P2^0;
void delay_ms(unsigned int count)
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
void uart1_init()
{
        TMOD = 0x20;	// 0 0 10 0000
        SCON = 0x50;	// 0101 0000
        TH1  = 0xFD;
        TL1  = 0xFD;
        TR1  = 1;
}
void uart1_write(unsigned char dat)
{
        SBUF = dat;
				while(!TI);
        TI = 0;
}

void uart1_write_text(unsigned char *dat)
{
	while(*dat)
	{	
		uart1_write(*dat);
		dat++;
	}
}
unsigned char uart_read()
{
        while(RI == 0);
        RI = 0;
        return SBUF;
}
char a;
void main(void)
{
	led = 0;
	uart1_init();	
	uart1_write_text("Hello Serial Port");
	while(1)
	{
		a = uart_read();
		if(a == 'A')
		{
			led = 1;
		}
		if(a == 'B')
		{
			led = 0;
		}
		delay_ms(1000);
		uart1_write(a);
	}
}

