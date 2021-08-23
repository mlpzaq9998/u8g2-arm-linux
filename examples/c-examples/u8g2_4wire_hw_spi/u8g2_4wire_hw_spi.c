#include <stdio.h>
#include "u8g2port.h"

// By default, SPI bus /dev/spidev0.0 is used, as defined in port/U8g2lib.h
#define OLED_SPI_PIN_RES            14
#define OLED_SPI_PIN_DC             4

// CS pin is controlled by linux spi driver, thus not defined here, but need to be wired
// #define OLED_SPI_PIN_CS             6

int main(void)
{
    u8g2_t u8g2;

    // Initialization
    u8g2_Setup_nt7534_tg12864r_f(&u8g2, U8G2_R2, u8x8_byte_arm_linux_hw_spi, u8x8_arm_linux_gpio_and_delay);
    u8x8_SetPin(u8g2_GetU8x8(&u8g2), U8X8_PIN_DC, OLED_SPI_PIN_DC);
    u8x8_SetPin(u8g2_GetU8x8(&u8g2), U8X8_PIN_RESET, OLED_SPI_PIN_RES);
    // u8x8_SetPin(u8g2_GetU8x8(&u8g2), U8X8_PIN_CS, OLED_SPI_PIN_CS);

    u8g2_InitDisplay(&u8g2);
    u8g2_SetPowerSave(&u8g2, 0);

    // Draw
    /* full buffer example, setup procedure ends in _f */
    u8g2_ClearBuffer(&u8g2);

    u8g2_SetFont(&u8g2, u8g2_font_ncenB08_tr);
    u8g2_DrawStr(&u8g2, 1, 18, "U8g2 HW SPI");

    u8g2_SetFont(&u8g2, u8g2_font_unifont_t_symbols);
    u8g2_DrawGlyph(&u8g2, 112, 56, 0x2603 );

    u8g2_SendBuffer(&u8g2);

    printf("Initialized ...\n");

    return 0;
}
