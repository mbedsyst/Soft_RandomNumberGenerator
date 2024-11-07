#include "Soft_RNG.h"

#define SEED_CONST		0x5A5A5A5A

static void TIM2_Init(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->CR1 &= ~TIM_CR1_DIR;
	TIM2->PSC = 1;
	TIM2->ARR = 0xFFFFFFFF;
	TIM2->CR1 |= TIM_CR1_CEN;
}

static uint32_t GetHardwareSeed(void)
{
	return TIM2->CNT;
}

static uint16_t GetLFSR(uint16_t seed16)
{
	uint16_t lsb = (seed16 & 0x01);
	seed16 >>= 1;
	if(lsb)
	{
		seed16 ^= 0xB400;
	}
	return seed16;
}

static uint32_t GetXORShift(uint32_t seed32)
{
	uint32_t state = seed32;
	state ^= (state << 13);
	state ^= (state >> 17);
	state ^= (state << 5);
	return state;
}

static uint32_t GetFNVHash(uint32_t val)
{
	uint32_t hash = 2166136261U;
	hash ^= val;
	hash *= 16777619;
	return hash;
}

void SoftRNG_Init(void)
{
	TIM2_Init();
	UART2_Init();
}

uint32_t SoftRNG_Generate(void)
{
	uint32_t hardwareSeed = GetHardwareSeed();
	uint32_t seedValue = hardwareSeed ^ SEED_CONST;
	uint16_t seed16 = seedValue & 0xFFFF;
	uint16_t lfsrVal = GetLFSR(seed16);
	uint32_t xorVal = GetXORShift(seedValue);
	uint32_t combined = lfsrVal & xorVal;
	uint32_t randomVal = GetFNVHash(combined);
	return randomVal;
}
