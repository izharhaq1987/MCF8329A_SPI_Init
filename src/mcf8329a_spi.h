#ifndef MCF8329A_SPI_H
#define MCF8329A_SPI_H

#include "stm32f1xx_hal.h"

#define MCF_REG_CTRL1  0x02  // Example register
#define MCF_REG_CTRL2  0x03

void mcf8329a_init(void);
void mcf8329a_write_register(uint8_t reg, uint16_t value);
uint16_t mcf8329a_read_register(uint8_t reg);

#endif
