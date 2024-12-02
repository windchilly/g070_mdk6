#include "oled.h"
#include "cdos.h"

uint8_t OLED_GRAM[128][8];

uint8_t dino[] = {
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe0, 0xf0, 0x30, 0x30, 0x30, 0x30, 0x0, 0x0, 0xf0, 0xf0, 0xc0, 0xc0, 0xf0, 0xf0, 0x0, 0x0, 0xf0, 0xf0, 0xb0, 0xb0, 0x70, 0x60, 0x0, 0x0, 0xe0, 0xf0, 0x30, 0x30, 0xf0, 0xe0, 0x0, 0x0, 0xf0, 0xf0, 0x30, 0xf0, 0xf0, 0x30, 0xf0, 0xe0, 0x0, 0xe0, 0xe0, 0x90, 0x90, 0x90, 0x90, 0x90, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf3, 0xf7, 0x36, 0x36, 0xf6, 0xe6, 0x0, 0xf0, 0xf7, 0x7, 0xc1, 0xc1, 0x37, 0x37, 0xf0, 0xc0, 0x7, 0xc7, 0xe0, 0x30, 0x37, 0x37,
0xe0, 0xc0, 0x3, 0x7, 0x6, 0xf6, 0xf7, 0xb3, 0xb0, 0xb0, 0xf7, 0xe7, 0x0, 0xf7, 0xf7, 0x0, 0x7, 0xf7, 0xf0, 0x3, 0xe3, 0xf4, 0x34, 0x34, 0xf4, 0xe4, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x10, 0xc, 0x4, 0x14, 0x14, 0x12, 0x11, 0x11, 0x11, 0x10, 0x11, 0x12, 0x12, 0x12, 0x14, 0x1c, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xf, 0xc, 0xc, 0xf, 0x7, 0x0, 0xf, 0xf, 0x0, 0xf, 0xf, 0x0, 0x0, 0xf, 0xf, 0x0, 0x3, 0x7, 0xc, 0xc, 0xc, 0x7, 0x3, 0x0, 0x0, 0x0, 0xf, 0xf, 0x1, 0x1, 0x1, 0xe, 0xe, 0x0, 0x7, 0xf, 0xc, 0xc, 0x7, 0x7, 0x0, 0xf, 0xf, 0x0, 0x0, 0xf, 0xf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0xc0, 0x60, 0xa0, 0xa0, 0xa0, 0x90, 0x88, 0x88, 0x8c, 0x88, 0x90, 0x90, 0xb0, 0xa0, 0xc0, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40, 0x40, 0x0, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x0, 0x0, 0xf0, 0xfc, 0xfc, 0x9c, 0x9c, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xf0, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0x0, 0x0, 0x8, 0x0, 0x0, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x0, 0x0, 0x80, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x4f, 0x4f, 0x4f, 0x4f, 0x4f, 0x4f, 0xf, 0xf, 0xf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0x80, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0x80, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0xfe, 0xfe, 0xfe, 0x0, 0x0, 0xf0, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf0, 0xf8, 0xf0, 0x0, 0x0, 0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0x80, 0x80, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xf8, 0xf8, 0xe0, 0xe0, 0x80, 0x80, 0x80, 0xc0, 0xe0, 0xf8, 0xf8, 0xf8, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x18, 0x8, 0x38, 0x38, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0x1, 0x0, 0x0, 0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0xff, 0xff, 0x0, 0xfc, 0xfe, 0x4, 0x0, 0xff, 0xff, 0xff, 0xc, 0xc, 0x8f, 0x83, 0x0, 0xf0, 0xf0, 0x0, 0x80, 0x9f, 0x3f, 0x7f, 0x70, 0x70, 0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0,
0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0x7, 0xf, 0x1f, 0x1f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x1f, 0x17, 0x7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x3, 0x7, 0x7, 0x7, 0xff, 0xff, 0xff, 0xff, 0x3, 0x3, 0x1, 0x0, 0x0, 0x3, 0x7, 0xe, 0xc, 0xff, 0xff, 0xff,
0x0, 0x0, 0x1f, 0x3f, 0x20, 0xff, 0xff, 0x20, 0x1f, 0xf, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0xff, 0x3, 0x3, 0x3, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
0x82, 0x82, 0x82, 0x2, 0x2, 0x22, 0x22, 0x22, 0x22, 0x2, 0x2, 0x2, 0x82, 0x82, 0x0, 0x0, 0x0, 0x1, 0xff, 0x9f, 0x9f, 0x7, 0x7, 0x1, 0x1, 0x7, 0x7, 0xff, 0x80, 0x80, 0x0, 0x0, 0x2, 0x2, 0x2, 0x2, 0xc2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x82, 0x82, 0x82, 0x82, 0x2, 0x2, 0x32, 0x32, 0x32, 0x22, 0x2, 0x2, 0x2, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x42, 0x42, 0x2, 0x2, 0x2, 0x2, 0x2, 0x0, 0xf, 0xf, 0xf, 0xf, 0x0, 0x1, 0x1, 0x1, 0x11, 0x11, 0x1, 0x1, 0x0, 0xf, 0xf, 0xf, 0x0, 0x1, 0x31, 0x11, 0x0, 0xf, 0xf, 0x0, 0xd, 0xd, 0x1, 0x11, 0x11, 0x10, 0x1f, 0x1f, 0x1f, 0x1f, 0x10, 0x0, 0xd, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0xd, 0xd, 0x1, 0x0, 0x0,
};

void draw_dino(void)
{
	uint8_t *temp;
	temp = dino;

    for (uint8_t i = 0; i < 8; i++)
	{
		for (uint8_t n = 0; n < 128; n++)
		{
			OLED_GRAM[n][i]=*temp++;
		}
	}
	refresh();
}

void OLED_WR_Byte(uint8_t dat, uint8_t cmd)
{
    uint8_t i;

    if (cmd){OLED_DC_Set();}
    else{OLED_DC_Clr();}
    OLED_CS_Clr();

    for (i = 0; i < 8; i++)
    {
        OLED_SCL_Clr();
        if (dat & 0x80){OLED_SDA_Set();}
        else{OLED_SDA_Clr();}
        OLED_SCL_Set();
        dat <<= 1;
    }

    OLED_CS_Set();
    OLED_DC_Set();
}

void refresh(void)
{
    uint8_t i, n;
    for (i = 0; i < 8; i++)
    {
        OLED_WR_Byte(0xb0 + i, OLED_CMD); //设置行起始地址
        OLED_WR_Byte(0x00, OLED_CMD);	  //设置低列起始地址
        OLED_WR_Byte(0x10, OLED_CMD);	  //设置高列起始地址
        for (n = 0; n < 128; n++)
		{
			OLED_WR_Byte(OLED_GRAM[n][i], OLED_DATA);
		}
    }
}

void clear(void)
{
    uint8_t i, n;
    for (i = 0; i < 8; i++)
    {
        for (n = 0; n < 128; n++)
        {
            OLED_GRAM[n][i] = 0; //清除所有数据
        }
    }
    refresh(); //更新显示
}

void setpixel(int x, int y, unsigned int t)
{
    uint8_t i, m, n;
    i = y / 8;
    m = y % 8;
    n = 1 << m;
    if (t)
    {
        OLED_GRAM[x][i] |= n;
    }
    else
    {
        OLED_GRAM[x][i] = ~OLED_GRAM[x][i];
        OLED_GRAM[x][i] |= n;
        OLED_GRAM[x][i] = ~OLED_GRAM[x][i];
    }
}

void oled_init(void)
{
    OLED_RES_Clr();
    HAL_Delay(200);
    OLED_RES_Set();

    OLED_WR_Byte(0xAE, OLED_CMD); //--turn off oled panel
    OLED_WR_Byte(0x00, OLED_CMD); //---set low column address
    OLED_WR_Byte(0x10, OLED_CMD); //---set high column address
    OLED_WR_Byte(0x40, OLED_CMD); //--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
    OLED_WR_Byte(0x81, OLED_CMD); //--set contrast control register
    OLED_WR_Byte(0xCF, OLED_CMD); // Set SEG Output Current Brightness
    OLED_WR_Byte(0xA1, OLED_CMD); //--Set SEG/Column Mapping     0xa0左右反置 0xa1正常
    OLED_WR_Byte(0xC8, OLED_CMD); // Set COM/Row Scan Direction   0xc0上下反置 0xc8正常
    OLED_WR_Byte(0xA6, OLED_CMD); //--set normal display
    OLED_WR_Byte(0xA8, OLED_CMD); //--set multiplex ratio(1 to 64)
    OLED_WR_Byte(0x3f, OLED_CMD); //--1/64 duty
    OLED_WR_Byte(0xD3, OLED_CMD); //-set display offset	Shift Mapping RAM Counter (0x00~0x3F)
    OLED_WR_Byte(0x00, OLED_CMD); //-not offset
    OLED_WR_Byte(0xd5, OLED_CMD); //--set display clock divide ratio/oscillator frequency
    OLED_WR_Byte(0x80, OLED_CMD); //--set divide ratio, Set Clock as 100 Frames/Sec
    OLED_WR_Byte(0xD9, OLED_CMD); //--set pre-charge period
    OLED_WR_Byte(0xF1, OLED_CMD); // Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
    OLED_WR_Byte(0xDA, OLED_CMD); //--set com pins hardware configuration
    OLED_WR_Byte(0x12, OLED_CMD);
    OLED_WR_Byte(0xDB, OLED_CMD); //--set vcomh
    OLED_WR_Byte(0x40, OLED_CMD); // Set VCOM Deselect Level
    OLED_WR_Byte(0x20, OLED_CMD); //-Set Page Addressing Mode (0x00/0x01/0x02)
    OLED_WR_Byte(0x02, OLED_CMD); //
    OLED_WR_Byte(0x8D, OLED_CMD); //--set Charge Pump enable/disable
    OLED_WR_Byte(0x14, OLED_CMD); //--set(0x10) disable
    OLED_WR_Byte(0xA4, OLED_CMD); // Disable Entire Display On (0xa4/0xa5)
    OLED_WR_Byte(0xA6, OLED_CMD); // Disable Inverse Display On (0xa6/a7)
    clear();
    OLED_WR_Byte(0xAF, OLED_CMD);
}
INIT_DEVICE_EXPORT(oled_init);
