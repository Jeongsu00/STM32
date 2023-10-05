/*
 * Led.c
 *
 *  Created on: Oct 5, 2023
 *      Author: user
 */

#include "led.h"
#include "main.h" // 사용하는 피ン과 관련된 헤더 파일을 포함해야 함

void LED_Control(uint32_t adcValue) {
    if (adcValue <= 500) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); // LED ON
    }
    else if (adcValue >= 4000) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET); // LED OFF
    }
}

void LED_Control2(uint32_t adcValue) {
    if (adcValue <= 500) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET); // LED ON
    }
    else if (adcValue >= 4000) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET); // LED OFF
    }
    // 추가적인 LED 제어 로직을 여기에 추가할 수 있음
}
