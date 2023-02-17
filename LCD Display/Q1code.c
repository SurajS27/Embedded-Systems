#include <reg51.h>
#define LCD_dat P2
sbit rs =P3^2;
sbit en =P3^4;

void dely(unsigned int dly);
void lcd_cmd(unsigned char ch);
void lcd_data(unsigned char ch);
void lcd_str(unsigned char *str);

void lcdinit(void);

void main(void)
{
LCD_dat = 0x00;   
rs = 0;   
en = 0;
	
lcdinit();

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

void lcdinit(void)
{
	 P2 &= 0x0F;		   // Make P2.4 to P2.7 zero
	 P2 |= (0x30&0xF0);    // Write 0x03
	
	 en  = 1;               
	 dely(10);
	 en  = 0;              
	 dely(10);

	 P2 &= 0x0F;		   // Make P2.4 to P2.7 zero
	 P2 |= (0x30&0xF0);    // Write 0x03
	
	 en  = 1;               
	 dely(10);
	 en  = 0;              
	 dely(10);

	 P2 &= 0x0F;		   // Make P2.4 to P2.7 zero
	 P2 |= (0x30&0xF0);    // Write 0x03
	
	 en  = 1;               
	 dely(10);
	 en  = 0;               
	 dely(10);

	 P2 &= 0x0F;		   // Make P2.4 to P2.7 zero
	 P2 |= (0x20&0xF0);    // Write 0x02
	
	 en  = 1;               
	 dely(10);
	 en  = 0;               
	 dely(10);

   lcd_cmd(0x28);    //function set: 4 bit two line
   lcd_cmd(0x0c);    //display on,cursor off,blink off
   lcd_cmd(0x01);    //clear display
   lcd_cmd(0x06);    //entry mode, set increment
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
	rs = 1;  // data
	LCD_dat &= 0x0F;	
	LCD_dat |= (ch & 0xF0);     // Write Upper nibble of data
	
	en = 1;
	dely(10);
	en = 0;
	dely(10);
	
	LCD_dat &= 0x0F;	
	LCD_dat |= ((ch<<4)& 0xF0);// Write Lower nibble of data
	en = 1;
	dely(10);
	en = 0;
	dely(10);
}

void lcd_cmd(unsigned char ch)
{
	rs = 0;  // cmd 
	LCD_dat &= 0x0F;	
	LCD_dat |= (ch & 0xF0); 

	en = 1;
	dely(10);
	en = 0;
	dely(10);
	
	LCD_dat &= 0x0F;	
  LCD_dat |= ((ch<<4)& 0xF0); 
	en = 1;
	dely(10);
	en = 0;
	dely(10);
}
void dely(unsigned int dly)
{
	unsigned int loop =0;
	unsigned int delay_gen =0;
	for(loop =0; loop < dly; loop++)
	for(delay_gen =0; delay_gen < 1000; delay_gen++); /* delay */
}



