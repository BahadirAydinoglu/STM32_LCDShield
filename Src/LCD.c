/*
	Karakter LCD Kütüphanesi
	Hüseyin Cemre Yilmaz
	hcemreyilmaz@gmail.com
    
    Düzenleyen
    Bahadir Aydinoglu  19.02.19
    bahadirayd@gmail.com
	
	Kullanim	: CubeMX ile proje olustururken 6 adet GPIO pini
							asagidaki gibi tanimlanmalidir.
							
							No.		| Pin Name| Type	| Alt. Func.	| Label
							----------------------------------------------
							xx		| Pxx			| I/O		| GPIO_Output | LCD_RS
							xx		| Pxx			| I/O		| GPIO_Output | LCD_EN
							xx		| Pxx			| I/O		| GPIO_Output | LCD_D4
							xx		| Pxx			| I/O		| GPIO_Output | LCD_D5
							xx		| Pxx			| I/O		| GPIO_Output | LCD_D6
							xx		| Pxx			| I/O		| GPIO_Output | LCD_D7
							
							LCD Shield için --->	LCD_RS -> PA9
																		LCD_EN -> PC7
																		LCD_D4 ->	PB5
																		LCD_D5 -> PB4
																		LCD_D6 -> PB10
																		LCD_D8 ->	PA8
																		
																		
							Pin ve port farketmeksizin, Output olarak tanimlanan pinler
							yukaridaki gibi isimlendirilmeli ve baglanti gerektigi gibi
							yapilmalidir.						
							
							Init Örnegi:							
							lcd_init(_LCD_4BIT, _LCD_FONT_5x8, _LCD_2LINE);
							
							4-Bit, 5x8 Font'lu, 2 satirli display kullanilacagi belirtiliyor.
							Farkli varyasyonlara LCD.h dosyasindan bakabilirsiniz.
                            
                            Kontrast ayari için pot kullanmak istemiyorsaniz baglantiniz asagidaki gibi olmali
                            
                            VDD-------------LCD VDD
                            |
                            10K
                            |                            
                            |---------------LCD VEE
                            |
                            1K
                            |
                            GND-------------LCD VSS
*/

#include "stm32f0xx_hal.h"
#include "main.h"
#include "LCD.h"
	
void Delay(uint32_t nCount)
{
  for(; nCount != 0; nCount--);
}
void lcd_delay(void)
{
	Delay(200);
}

void lcd_cmd(char out_char)
{
	LCD_RS_GPIO_Port->BRR  = LCD_RS_Pin;
	
	LCD_EN_GPIO_Port->BRR  = LCD_EN_Pin;
	LCD_D4_GPIO_Port->BRR  = LCD_D4_Pin;
	LCD_D5_GPIO_Port->BRR  = LCD_D5_Pin;
	LCD_D6_GPIO_Port->BRR  = LCD_D6_Pin;
	LCD_D7_GPIO_Port->BRR  = LCD_D7_Pin;
	
	lcd_delay();
	
	LCD_EN_GPIO_Port->ODR |= LCD_EN_Pin;
		
	if((out_char & 0x10)>>4) LCD_D4_GPIO_Port->BSRR = LCD_D4_Pin; else LCD_D4_GPIO_Port->BSRR = (uint32_t)LCD_D4_Pin << 16;
	if((out_char & 0x20)>>5) LCD_D5_GPIO_Port->BSRR = LCD_D5_Pin; else LCD_D5_GPIO_Port->BSRR = (uint32_t)LCD_D5_Pin << 16;
	if((out_char & 0x40)>>6) LCD_D6_GPIO_Port->BSRR = LCD_D6_Pin; else LCD_D6_GPIO_Port->BSRR = (uint32_t)LCD_D6_Pin << 16;
	if((out_char & 0x80)>>7) LCD_D7_GPIO_Port->BSRR = LCD_D7_Pin; else LCD_D7_GPIO_Port->BSRR = (uint32_t)LCD_D7_Pin << 16;
	
	lcd_delay();
	
	LCD_EN_GPIO_Port->BRR = LCD_EN_Pin;
	LCD_D4_GPIO_Port->BRR = LCD_D4_Pin;
	LCD_D5_GPIO_Port->BRR = LCD_D5_Pin;
	LCD_D6_GPIO_Port->BRR = LCD_D6_Pin;
	LCD_D7_GPIO_Port->BRR = LCD_D7_Pin;
	
	lcd_delay();
	
	LCD_EN_GPIO_Port->ODR |= LCD_EN_Pin;
	
	if(out_char & 0x01) LCD_D4_GPIO_Port->BSRR = LCD_D4_Pin; else LCD_D4_GPIO_Port->BSRR = (uint32_t)LCD_D4_Pin << 16;
	if((out_char & 0x02)>>1) LCD_D5_GPIO_Port->BSRR = LCD_D5_Pin; else LCD_D5_GPIO_Port->BSRR = (uint32_t)LCD_D5_Pin << 16;
	if((out_char & 0x04)>>2) LCD_D6_GPIO_Port->BSRR = LCD_D6_Pin; else LCD_D6_GPIO_Port->BSRR = (uint32_t)LCD_D6_Pin << 16;
	if((out_char & 0x08)>>3) LCD_D7_GPIO_Port->BSRR = LCD_D7_Pin; else LCD_D7_GPIO_Port->BSRR = (uint32_t)LCD_D7_Pin << 16;

	lcd_delay();
	
	LCD_EN_GPIO_Port->BRR = LCD_EN_Pin;
	LCD_D4_GPIO_Port->BRR = LCD_D4_Pin;
	LCD_D5_GPIO_Port->BRR = LCD_D5_Pin;
	LCD_D6_GPIO_Port->BRR = LCD_D6_Pin;
	LCD_D7_GPIO_Port->BRR = LCD_D7_Pin;
}

void lcd_char_cp(char out_char)
{
	LCD_RS_GPIO_Port->ODR |= LCD_RS_Pin;
	
	LCD_EN_GPIO_Port->BRR  = LCD_EN_Pin;
	LCD_D4_GPIO_Port->BRR  = LCD_D4_Pin;
	LCD_D5_GPIO_Port->BRR  = LCD_D5_Pin;
	LCD_D6_GPIO_Port->BRR  = LCD_D6_Pin;
	LCD_D7_GPIO_Port->BRR  = LCD_D7_Pin;
	
	lcd_delay();
	
	LCD_EN_GPIO_Port->ODR |= LCD_EN_Pin;
		
	if((out_char & 0x10)>>4) LCD_D4_GPIO_Port->BSRR = LCD_D4_Pin; else LCD_D4_GPIO_Port->BSRR = (uint32_t)LCD_D4_Pin << 16;
	if((out_char & 0x20)>>5) LCD_D5_GPIO_Port->BSRR = LCD_D5_Pin; else LCD_D5_GPIO_Port->BSRR = (uint32_t)LCD_D5_Pin << 16;
	if((out_char & 0x40)>>6) LCD_D6_GPIO_Port->BSRR = LCD_D6_Pin; else LCD_D6_GPIO_Port->BSRR = (uint32_t)LCD_D6_Pin << 16;
	if((out_char & 0x80)>>7) LCD_D7_GPIO_Port->BSRR = LCD_D7_Pin; else LCD_D7_GPIO_Port->BSRR = (uint32_t)LCD_D7_Pin << 16;
	
	lcd_delay();
	
	LCD_EN_GPIO_Port->BRR = LCD_EN_Pin;
	LCD_D4_GPIO_Port->BRR = LCD_D4_Pin;
	LCD_D5_GPIO_Port->BRR = LCD_D5_Pin;
	LCD_D6_GPIO_Port->BRR = LCD_D6_Pin;
	LCD_D7_GPIO_Port->BRR = LCD_D7_Pin;
	
	lcd_delay();
	
	LCD_EN_GPIO_Port->ODR |= LCD_EN_Pin;
	
	if(out_char & 0x01) LCD_D4_GPIO_Port->BSRR = LCD_D4_Pin; else LCD_D4_GPIO_Port->BSRR = (uint32_t)LCD_D4_Pin << 16;
	if((out_char & 0x02)>>1) LCD_D5_GPIO_Port->BSRR = LCD_D5_Pin; else LCD_D5_GPIO_Port->BSRR = (uint32_t)LCD_D5_Pin << 16;
	if((out_char & 0x04)>>2) LCD_D6_GPIO_Port->BSRR = LCD_D6_Pin; else LCD_D6_GPIO_Port->BSRR = (uint32_t)LCD_D6_Pin << 16;
	if((out_char & 0x08)>>3) LCD_D7_GPIO_Port->BSRR = LCD_D7_Pin; else LCD_D7_GPIO_Port->BSRR = (uint32_t)LCD_D7_Pin << 16;

	lcd_delay();
	
	LCD_EN_GPIO_Port->BRR = LCD_EN_Pin;
	LCD_D4_GPIO_Port->BRR = LCD_D4_Pin;
	LCD_D5_GPIO_Port->BRR = LCD_D5_Pin;
	LCD_D6_GPIO_Port->BRR = LCD_D6_Pin;
	LCD_D7_GPIO_Port->BRR = LCD_D7_Pin;
}

void lcd_out_cp(char *out_char)
{
	while(*out_char)
	{
		lcd_char_cp(*out_char++);
        lcd_delay();
	}
	
}


void lcd_init(char bits, char font, char lines)
{		
    HAL_Delay(250);
		lcd_cmd(_RETURN_HOME);
    HAL_Delay(50);
    lcd_cmd(0x20 | bits | font | lines);
    HAL_Delay(50);
    lcd_cmd(_LCD_INIT);
    HAL_Delay(50);
    lcd_cmd(0x0E);
    HAL_Delay(50);
    lcd_cmd(0x0C);
    HAL_Delay(50);
    lcd_cmd(0x01);
    HAL_Delay(100);
}

void lcd_gotoxy(unsigned char row, unsigned char column)
{	
	if(row == 1)
	{
		lcd_cmd(0x80 + (column - 1));
	}
	else if(row == 2)
	{
		lcd_cmd(0xC0 + (column - 1));
	} 
    HAL_Delay(5);    
    
}

void lcd_char(unsigned char row, unsigned char column, char out_char)
{
	lcd_gotoxy(row, column);
	lcd_char_cp(out_char);
}

void lcd_print(unsigned char row, unsigned char column, char *out_char)
{
	lcd_gotoxy(row, column);
	lcd_out_cp(out_char);  
    HAL_Delay(5);      
}
void lcd_clear(void) {
    
	lcd_cmd(_CLEAR);
    HAL_Delay(5);
    
}
void lcd_line1(void) {
	lcd_cmd(0x80);
}

void lcd_line2(void) {
	lcd_cmd(0xC0);
}
