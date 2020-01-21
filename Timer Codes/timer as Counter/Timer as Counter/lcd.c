#include<reg51.h>

sbit LCD_RS = P2^2;
sbit LCD_EN = P2^3;
sbit LCD_D4 = P2^4;
sbit LCD_D5 = P2^5;
sbit LCD_D6 = P2^6;
sbit LCD_D7 = P2^7;







void delay_ms(unsigned int count);
void lcd_init();
void lcd_set_4bit();
void lcd_busy();
void lcd_cmd(unsigned char);
void lcd_data(char);
void lcd_out(char row, char column, char*);
void lcd_cursor (char row, char column);
void lcd_print(char row, char coloumn, unsigned int value, int digits);






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

void lcd_init()
{
                lcd_set_4bit();                // function call here
                delay_ms(5);
                lcd_cmd(0x28);        //LCD 4-bit mode and 2 lines.
                lcd_cmd(0x01);
                lcd_cmd(0x06);
                lcd_cmd(0x0E);
                lcd_cmd(0x80);
                lcd_cmd(0x0C);
}

// THIS FUNCTION IS REQUIRED for MAKING LCD WORK IN 4-bit mode, it was missed
void lcd_set_4bit()
{
                LCD_RS = 0;  LCD_EN = 0; LCD_D6 = 0; LCD_D7 = 0;
                delay_ms(1);
                LCD_D5 = 1;
                LCD_D4 = 1;
                LCD_EN = 1;
                delay_ms(1);
                LCD_EN = 0;
                delay_ms(1);

                LCD_D5 = 1;
                LCD_D4 = 1;
                LCD_EN = 1;
                delay_ms(1);
                LCD_EN = 0;
                delay_ms(1);

                LCD_D5 = 1;
                LCD_D4 = 1;
                LCD_EN = 1;
                delay_ms(1);
                LCD_EN = 0;
                delay_ms(1);

                LCD_D5 = 1;
                LCD_D4 = 0;
                LCD_EN = 1;
                delay_ms(1);
                LCD_EN = 0;
                delay_ms(1);
}

void lcd_busy()
{
                char a;
                a=255;
                while(a--);
                a=255;
                while(a--);
                a=255;
                while(a--);
                a=255;
                while(a--);
                a=255;
                while(a--);
                a=255;
                while(a--);
                a=255;
                while(a--);        
}

void lcd_cmd(unsigned char cmd)
{
                if(cmd & 0x80) LCD_D7 = 1; else LCD_D7 = 0;
                if(cmd & 0x40) LCD_D6 = 1; else LCD_D6 = 0;
                if(cmd & 0x20) LCD_D5 = 1; else LCD_D5 = 0;
                if(cmd & 0x10) LCD_D4 = 1; else LCD_D4 = 0;
                LCD_RS = 0;
                LCD_EN = 1;
                delay_ms(2);        
                LCD_EN = 0;
                delay_ms(1);
                if(cmd & 0x08) LCD_D7 = 1; else LCD_D7 = 0;
                if(cmd & 0x04) LCD_D6 = 1; else LCD_D6 = 0;
                if(cmd & 0x02) LCD_D5 = 1; else LCD_D5 = 0;
                if(cmd & 0x01) LCD_D4 = 1; else LCD_D4 = 0;
                LCD_RS = 0;
                LCD_EN = 1;
                delay_ms(2);
                LCD_EN = 0;
}

void lcd_data(unsigned char letter)
{
                if(letter & 0x80) LCD_D7 = 1; else LCD_D7 = 0;
                if(letter & 0x40) LCD_D6 = 1; else LCD_D6 = 0;
                if(letter & 0x20) LCD_D5 = 1; else LCD_D5 = 0;
                if(letter & 0x10) LCD_D4 = 1; else LCD_D4 = 0;

                LCD_RS = 1;
                LCD_EN = 1;
                delay_ms(2);
                LCD_EN = 0;


                if(letter & 0x08) LCD_D7 = 1; else LCD_D7 = 0;
                if(letter & 0x04) LCD_D6 = 1; else LCD_D6 = 0;
                if(letter & 0x02) LCD_D5 = 1; else LCD_D5 = 0;
                if(letter & 0x01) LCD_D4 = 1; else LCD_D4 = 0;
                LCD_RS = 1;
                LCD_EN = 1;
                delay_ms(2);
                LCD_EN = 0;        
}

void lcd_out(char row, char column, char *str)
{
                lcd_cursor(row, column);
          while(*str != '\0')
                {
                                lcd_data(*str);
                                str++;
                }
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

