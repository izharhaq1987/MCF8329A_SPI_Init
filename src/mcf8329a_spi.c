#include "mcf8329a_spi.h"
#include "stm32f1xx_hal.h"
#include "uart_debug.h"  // Optional, for debug output

extern SPI_HandleTypeDef hspi1;

void mcf8329a_init(void)
{
    mcf8329a_write_register(MCF_REG_CTRL1, 0x0304);
    uart_log("[MCF8329A INIT] CTRL1 set to 0x0304\n");
}

void mcf8329a_write_register(uint8_t reg, uint16_t value)
{
    uint8_t tx_data[3] = { reg, (value >> 8) & 0xFF, value & 0xFF };
    HAL_SPI_Transmit(&hspi1, tx_data, 3, HAL_MAX_DELAY);
}

uint16_t mcf8329a_read_register(uint8_t reg)
{
    uint8_t tx_data[1] = { reg | 0x80 };
    uint8_t rx_data[2] = { 0 };

    HAL_SPI_Transmit(&hspi1, tx_data, 1, HAL_MAX_DELAY);
    HAL_SPI_Receive(&hspi1, rx_data, 2, HAL_MAX_DELAY);

    return (rx_data[0] << 8) | rx_data[1];
}
