/*
 * Led.c
 *
 *  Created on: Oct 24, 2023
 *      Author: user
 */

#include "main.h"

void Led_Set(){
//예제 1
//	  GPIOA -> MODER = GPIOA -> MODER & (~0x11);		// 0x10은 특수 목적(예 : 통신), 0x11(Analog),
	  	  	  	  	  	  	  	  	  	  	  	  	  	  // 디지털로 지정	  	  	  	  	// & 비트단위 AND 연산, | 비트단위 OR 연산, ~ 비트단위 NOT 연산, ^ 비트단위 XOR 연산
	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	// << 왼쪽으로 비트 이동, >> 오른쪽으로 비트 이동
//	  GPIOA -> MODER = GPIOA -> MODER | (0x01);			// 0x00은 Input, 0x01은 Output
	  	  	  	  	  	  	  	  	  	  	  	  	  	  // Output으로 지정

// 예제 2
//	  GPIOA -> MODER = GPIOA -> MODER & (~(0x11 << 2));	// GPIOA의 1번 Port를 디지털로 지정 (17~32bit는 아날로그 여부 지정)
//	  GPIOA -> MODER = GPIOA -> MODER | (0x01 << 2);			// GPIOA의 1번을 Output으로 지정   (1~16bit는 Input, Output지정)

//	  GPIOA -> MODER &= (~(0x11 << 2));									// GPIOA -> MODER = GPIOA -> MODER & (~(0x11 << 2));를 생략 가능
//	  GPIOA -> MODER |= (1 << 2);													// GPIOA -> MODER = GPIOA -> MODER | (0x01 << 2)

	// * GPIO는 32bit로 구성되어 2비트 당 1개의 port를 사용함으로 GPIOA의 1번 Port는 2번과 3번  bit를 사용함으로 시프트 연산자 2를 사용
	// * GPIOA에 2번과 3번 Port는 회로가 달라 이 코드로는 사용 불가

// 예제3
//	  GPIOA -> MODER &= (~0x11);
//	  GPIOA -> MODER |= (1);
//	  GPIOA -> MODER &= (~(0x11 << 2));
//	  GPIOA -> MODER |= (1 << 2);
//	  GPIOA -> MODER &= (~(0x11 << 8));
//	  GPIOA -> MODER |= (1 << 8);
//	  GPIOA -> MODER &= (~(0x11 << 10));
//	  GPIOA -> MODER |= (1 << 10);

// 예제 4
	  GPIOA -> MODER &= (~0x11);
	  GPIOA -> MODER |= (1);
	  GPIOA -> MODER &= (~(0x11 << 2));
	  GPIOA -> MODER |= (1 << 2);
	  GPIOA -> MODER &= (~(0x11 << 8));
	  GPIOA -> MODER |= (1 << 8);
	  GPIOA -> MODER &= (~(0x11 << 10));
	  GPIOA -> MODER |= (1 << 10);
}


void Led_Control(){

// 예제 1
//	  GPIOA -> ODR = 0x01;		// GPIOA 0번 Port 레지스터에 1을 입력
//	  HAL_Delay(1000);
//	  GPIOA -> ODR = 0x00;		// GPIOA 0번 Port 레지스터에 0을 입력
//	  HAL_Delay(1000);

// 예제 2
//	  GPIOA -> ODR = 0x01 << 1;		// GPIOA 1번 Port 레지스터에 1을 입력 GPIOA -> ODR = 0x02도 가능
//	  HAL_Delay(1000);
//	  GPIOA -> ODR = 0x00;				// GPIOA 1번 Port 레지스터에 1을 입력
//	  HAL_Delay(1000);

// 예제 3
//	  GPIOA -> ODR = 0x01;
//	  HAL_Delay(1000);
//	  GPIOA -> ODR = 0x00;
//	  GPIOA -> ODR = 0x01 << 1;
//	  HAL_Delay(1000);
//	  GPIOA -> ODR = 0x00;
//	  GPIOA -> ODR = 0x01 << 4;
//	  HAL_Delay(1000);
//	  GPIOA -> ODR = 0x00;
//	  GPIOA -> ODR = 0x01 << 5;
//	  HAL_Delay(1000);
//	  GPIOA -> ODR = 0x00;
//	  HAL_Delay(1000);

// 예제 4
//	  GPIOA -> BSRR |= (1 << 5); 					// GPIOA 5번 Port Set (BSRR은 1~16bit는 Set 여부)
	  // 위 코드와 같은 작동 : GPIOA -> ODR = 0x01 << 5 ;
//	  HAL_Delay(1000);
//	  GPIOA -> BSRR |= (1 << 5) << 16;		// GPIOA 5번 Port Reset (BSRR의 17~32bit는 Reset 여부)
//	  HAL_Delay(1000);

	  GPIOA -> BSRR |= (1 << 5) << 16;
	  GPIOA -> BSRR |= 1 << 0;
	  HAL_Delay(250);
	  GPIOA -> BSRR |=  1 << 16;
	  GPIOA -> BSRR |= 1 << 1;
	  HAL_Delay(250);
	  GPIOA -> BSRR |= (1 << 1) << 16;
	  GPIOA -> BSRR |= 1 << 4;
	  HAL_Delay(250);
	  GPIOA -> BSRR |= (1 << 4) << 16;
	  GPIOA -> BSRR |= 1 << 5;
	  HAL_Delay(250);
}
