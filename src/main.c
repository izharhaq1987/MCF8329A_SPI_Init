#include "mcf8329a_spi.h"
#include "stm32f1xx_hal.h"

int main(void)
{
    HAL_Init();
    SystemClock_Config(); // Implement this or use CubeMX-generated code

    MX_GPIO_Init();
    MX_SPI1_Init();       // Your SPI init function

    mcf8329a_init();

    while (1)
    {
        // Main loop logic
    }
}
