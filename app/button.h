#ifndef _BUTTON_H__
#define _BUTTON_H__

enum LCD_BTN_TYPE
{
	LCD_BTN_UP_SCLICK,											//low 4 bits used to indicate SCLICK
	LCD_BTN_DOWN_SCLICK,
	LCD_BTN_LEFT_SCLICK,
	LCD_BTN_RIGHT_SCLICK,
	LCD_BTN_ESC_SCLICK,
	LCD_BTN_ENTER_SCLICK,

	LCD_BTN_UP_LPRESS = 	(LCD_BTN_UP_SCLICK+1)<<4,			//high 4 bits used to indicate LPRESS
	LCD_BTN_DOWN_LPRESS = 	(LCD_BTN_DOWN_SCLICK+1)<<4,
	LCD_BTN_LEFT_LPRESS = 	(LCD_BTN_LEFT_SCLICK+1)<<4,
	LCD_BTN_RIGHT_LPRESS = 	(LCD_BTN_RIGHT_SCLICK+1)<<4,
	LCD_BTN_ESC_LPRESS = 	(LCD_BTN_ESC_SCLICK+1)<<4,
	LCD_BTN_ENTER_LPRESS = 	(LCD_BTN_ENTER_SCLICK+1)<<4,
};

#endif