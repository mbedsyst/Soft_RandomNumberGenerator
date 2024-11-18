# Software Random Number Generator
A Software library to generate 32-bit Random Numbers using onboard 32-bit Timers
and a combination of LFSR, XOR Shift and the FNV hash function on an STM32F401
Nucleo Development Board.

For a detailed explanation and implementation guide, visit the article on my blog:
https://mbedsyst.blogspot.com/2024/11/software-random-number-generator-v10.html

Note: Generate Random Numbers with an adaptive delay. A non-stop call to the 
SoftRNG_Generate() function will start to output 32-bit numbers that shows a
pattern when looked at large scale.
