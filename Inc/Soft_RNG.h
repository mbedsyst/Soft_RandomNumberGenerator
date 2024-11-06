#ifndef SOFT_RNG_H_
#define SOFT_RNG_H_

#include <stdio.h>
#include "stm32f4xx.h"
#include "UART.h"

void SoftRNG_Init(void);
uint32_t SoftRNG_Generate(void);

#endif
