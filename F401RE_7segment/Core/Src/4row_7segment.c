/*
 * 4row_7segment.c
 *
 *  Created on: Nov 17, 2023
 *      Author: user
 */

#include "4row_7segment.h"

void Segment_init(){

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, RESET);		// DP
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);		// A
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);		// B
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);		// C
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);		// D
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);		// E
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, RESET);		// F
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, RESET);		// G

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, SET);			// 1 row
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, SET);			// 2 row
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, SET);			// 3 row
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, SET);			// 4 row

	  HAL_Delay(50);

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);		// DP
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);		// A
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);		// B
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);		// C
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);		// D
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);		// E
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, SET);		// F
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, SET);		// G

	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET);			// 1 row
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, RESET);			// 2 row
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, RESET);			// 3 row
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, RESET);			// 4 row

	  HAL_Delay(50);
}

void Segment_SET(){

	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);		// DP
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);		// A
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);		// B
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);		// C
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);		// D
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);		// E
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, SET);		// F
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, SET);		// G
}

void Segment_ROW(){

	int num, num2, num3, num4;

	for(num = 0;  num < 50000;  num++){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, SET);				// 1 row
		Segment_control(num);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET);			// 1 row
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, SET);				// 1 row
		Segment_control(num);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET);			// 1 row
	}

	for(num2 = 5000;  num2 < 50000;  num2 += 5000){
		for(num = 0;  num < 50000;  num++){
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, SET);				// 2 row
			Segment_control(num2);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, RESET);			// 2 row
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, SET);				// 1 row
			Segment_control(num);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET);			// 1 row
		}
	}
	for(num3 = 5000;   num3 < 50000;  num3 += 5000){
		for(num2 = 0;  num2 < 50000;  num2 += 5000){
			for(num = 0;  num < 50000;  num += 10){
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, SET);				// 3 row
				Segment_control(num3);
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, RESET);			// 3 row
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, SET);				// 2 row
				Segment_control(num2);
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, RESET);			// 2 row
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, SET);				// 1 row
				Segment_control(num);
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET);			// 1 row
			}
		}
	}
	for(num4 = 5000;  num4 < 50000;  num4 += 5000){
		for(num3 = 0;   num3 < 50000;  num3 += 5000){
			for(num2 = 0;  num2 < 50000;  num2 += 5000){
				for(num = 0;  num < 50000;  num += 10){
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, SET);				// 4 row
					Segment_control(num4);
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, RESET);			// 4 row
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, SET);				// 3 row
					Segment_control(num3);
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, RESET);			// 3 row
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, SET);				// 2 row
					Segment_control(num2);
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, RESET);			// 2 row
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, SET);				// 1 row
					Segment_control(num);
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET);			// 1 row
				}
			}
		}
	}
}

void Segment_control(int num){
	if(num >= 0 && num < 5000){
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);		// A
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);		// B
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);		// C
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);		// D
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);		// E
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, RESET);		// F
	}
	else if(num >= 5000 && num < 10000){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);		// B
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);		// C
	}

	else if(num >= 10000 && num < 15000){
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);		// A
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);		// B
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);		// D
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);		// E
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, RESET);		// G
	}

	else if(num >= 15000 && num < 20000){
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);		// A
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);		// B
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);		// C
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);		// D
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, RESET);		// G
	}
	else if(num >= 20000 && num < 25000){
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);		// B
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);		// C
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, RESET);		// F
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, RESET);		// G
	}
	else if(num >= 25000 && num < 30000){
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);		// A
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);		// C
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);		// D
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, RESET);		// F
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, RESET);		// G
	}
	else if(num >= 30000 && num < 35000){
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);		// A
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);		// C
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);		// D
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);		// E
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, RESET);		// F
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, RESET);		// G
	}
	else if(num >= 35000 && num < 40000){
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);		// A
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);		// B
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);		// C
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, RESET);		// F
	}
	else if(num >= 40000 && num < 45000){
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);		// A
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);		// B
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);		// C
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);		// D
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);		// E
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, RESET);		// F
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, RESET);		// G
	}
	else if(num >= 45000 && num < 50000){
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);		// A
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);		// B
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);		// C
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);		// D
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, RESET);		// F
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, RESET);		// G
	}
	Segment_SET();
}
