/*
 * Utils.c
 *
 *  Created on: Oct 18, 2025
 *      Author: Deived
 */
#include "Utils.h"


void DWT_Delay_Init(void) {
    // Enable DWT access
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;

    // Reset counter
    DWT->CYCCNT = 0;

    // Enable cycles counter
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
}


void DWT_Delay_us(uint32_t us) {
    uint32_t cycles = (SystemCoreClock / 1000000L) * us;
    uint32_t start = DWT->CYCCNT;

    while ((DWT->CYCCNT - start) < cycles);
}
