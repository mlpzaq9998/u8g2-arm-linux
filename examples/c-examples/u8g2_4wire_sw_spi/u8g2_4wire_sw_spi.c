#include <stdio.h>
#include "u8g2port.h"


#define OLED_SPI_PIN_MOSI           7
#define OLED_SPI_PIN_SCK            5

// Use a different pin here rather than default SPI pins, which may cause issue
#define OLED_SPI_PIN_RES            14
#define OLED_SPI_PIN_DC             4
#define OLED_SPI_PIN_CS             6

int main(void)
{
    u8g2_t u8g2;

    // Initialization
    u8g2_Setup_nt7534_tg12864r_f(&u8g2, U8G2_R2, u8x8_byte_4wire_sw_spi, u8x8_arm_linux_gpio_and_delay);
    u8x8_SetPin(u8g2_GetU8x8(&u8g2), U8X8_PIN_RESET, OLED_SPI_PIN_RES);
    u8x8_SetPin(u8g2_GetU8x8(&u8g2), U8X8_PIN_DC, OLED_SPI_PIN_DC);
    u8x8_SetPin(u8g2_GetU8x8(&u8g2), U8X8_PIN_SPI_DATA, OLED_SPI_PIN_MOSI);
    u8x8_SetPin(u8g2_GetU8x8(&u8g2), U8X8_PIN_SPI_CLOCK, OLED_SPI_PIN_SCK);
    u8x8_SetPin(u8g2_GetU8x8(&u8g2), U8X8_PIN_CS, OLED_SPI_PIN_CS);

    u8g2_InitDisplay(&u8g2);
    u8g2_SetPowerSave(&u8g2, 0);
	
	onled();

    // Draw    
    /* full buffer example, setup procedure ends in _f */
    u8g2_ClearBuffer(&u8g2);
    int i;
    for(i=0;i<128;i++){
        u8g2_DrawPixel(&u8g2, i,i); //diagonal -> dx bottom
        u8g2_DrawPixel(&u8g2, i,127-i); //diagonal -> dx top
        u8g2_DrawPixel(&u8g2, i,0); //line top
        u8g2_DrawPixel(&u8g2, i,7); //line top
        u8g2_DrawPixel(&u8g2, i,127); //line bottom
        u8g2_DrawPixel(&u8g2, i,120); //line bottom
        u8g2_DrawPixel(&u8g2, 0,i); //line left
        u8g2_DrawPixel(&u8g2, 7,i); //line left
        u8g2_DrawPixel(&u8g2, 127,i); //line right
        u8g2_DrawPixel(&u8g2, 120,i); //line right
    }

    u8g2_SendBuffer(&u8g2);

    printf("Initialized ...\n");

    return 0;
}
