#include <stdio.h>
#include <stdint.h>

#include "LED.h"
#include "SYSTICK.h"
#include "W25Qxx.h"
#include "Soft_RNG.h"

uint32_t count = 0;

int main()
{
    uint32_t random;
    LED_Init();
    W25Q_Init();
    SoftRNG_Init();

    for(int i = 0; i < 10000; i++)
    {
        random = SoftRNG_Generate();
        W25Q_WriteData(i, 0, 4, (uint8_t *)&random);
        count++;
        delay_ms(i%100);
    }

    while(1)
    {

    }
}
