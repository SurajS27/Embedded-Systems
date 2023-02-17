#include <reg51.h>
#define display_port P2
sbit rs =P3^2;
sbit en =P3^4;

void dely(unsigned int dly);
void lcd_cmd(unsigned char ch);
void lcd_data(unsigned char ch);
void lcd_str(unsigned char *str);
void main(void)
{
	lcd_cmd(0x38);
	lcd_cmd(0x0C);
  while(1) /* infinity loop */
	{
	lcd_cmd(0x80);
	lcd_str("Embedded Systems"); // '\0'
	lcd_cmd(0xc0);
	lcd_str("Ravi kiran Bolla"); // '\0'
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_str("Subscribe to"); // '\0'
	lcd_cmd(0xc0);
	lcd_str("This Youtube Channel"); // '\0'
	lcd_cmd(0x01);
	}
	
}
void lcd_str(unsigned char *str)
{
	unsigned int loop =0;
	for(loop =0; str[loop]!= '\0'; loop++)
	{
		lcd_data(str[loop]);
	}
}
void lcd_data(unsigned char ch)
{
	display_port = ch;
	rs = 1;  // data
	en = 1;
	dely(10);
	en = 0;
}

void lcd_cmd(unsigned char ch)
{
	display_port = ch;
	rs = 0;  // cmd
	en = 1;
	dely(10);
	en = 0;
}
void dely(unsigned int dly)
{
	unsigned int loop =0;
	unsigned int delay_gen =0;
	for(loop =0; loop < dly; loop++)
	for(delay_gen =0; delay_gen < 1000; delay_gen++); /* delay */
}