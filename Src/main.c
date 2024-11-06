#include <stdint.h>
#include "LED.h"
#include "SYSTICK.h"
#include "W25Qxx.h"
#include "Soft_RNG.h"

int main()
{
	uint32_t random;

	LED_Init();
	SoftRNG_Init();

	for(int i = 0; i < W25Q_PageCount; i++)
	{
		LED_Toggle();
		random = SoftRNG_Generate();
		W25Q_WriteData(i, 0, 2, (uint8_t *)&random);
		LED_Toggle();
	}

	while(1)
	{

	}
}
