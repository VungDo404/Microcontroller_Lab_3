/*
 * global.c
 *
 *  Created on: Nov 4, 2023
 *      Author: Admin
 */

#include "global.h"
int status = 0;
int horizontal_number = 0;
int vertical_number = 0;
int led_buffer [4] = {0 , 0 , 0 , 0};

void display7SEG(int num){
	  switch(num){
			case 0:
				  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, SET);
				  break;
			case 1:
				  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, SET);
				  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, SET);
				  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
				  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, SET);
				  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, SET);
				  break;
			case 2:
				  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, SET);
				  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, SET);
				  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
				  break;
			case 3:
				  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
				  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, SET);
				  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
				  break;
			case 4:
				  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, SET);
				  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, SET);
				  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
				  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
				  break;
			case 5:
				  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, SET);
				  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
				  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
				  break;
			case 6:
				  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, SET);
				  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
				  break;
			case 7:
				  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, SET);
				  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
				  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, SET);
				  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, SET);
				  break;
			case 8:
				  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
				  break;
			case 9:
				  HAL_GPIO_WritePin(GPIOB, SEG0_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG1_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG2_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG3_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG4_Pin, SET);
				  HAL_GPIO_WritePin(GPIOB, SEG5_Pin, RESET);
				  HAL_GPIO_WritePin(GPIOB, SEG6_Pin, RESET);
				  break;

	  }
}
void update7SEG (int index) {
	  display7SEG(led_buffer[index]);
	  switch (index){
	  case 0:
		  HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
		  HAL_GPIO_WritePin(GPIOA, EN1_Pin, SET);
		  HAL_GPIO_WritePin(GPIOA, EN2_Pin, SET);
		  HAL_GPIO_WritePin(GPIOA, EN3_Pin, SET);
		  break;
	  case 1:
		  HAL_GPIO_WritePin(GPIOA, EN0_Pin, SET);
		  HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
		  HAL_GPIO_WritePin(GPIOA, EN2_Pin, SET);
		  HAL_GPIO_WritePin(GPIOA, EN3_Pin, SET);
	  	  break;
	  case 2:
		  HAL_GPIO_WritePin(GPIOA, EN0_Pin, SET);
		  HAL_GPIO_WritePin(GPIOA, EN1_Pin, SET);
		  HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
		  HAL_GPIO_WritePin(GPIOA, EN3_Pin, SET);
	  	  break;
	  case 3:
		  HAL_GPIO_WritePin(GPIOA, EN0_Pin, SET);
		  HAL_GPIO_WritePin(GPIOA, EN1_Pin, SET);
		  HAL_GPIO_WritePin(GPIOA, EN2_Pin, SET);
		  HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);
	  	  break;
	  default:
	  	  break;
	  }
};
void updateClockBuffer(){
    led_buffer[0] = horizontal_number / 10;
    led_buffer[1] = horizontal_number % 10;
    led_buffer[2] = vertical_number / 10;
    led_buffer[3] = vertical_number % 10;
}
void countDown(){
	horizontal_number--;
	vertical_number--;
}
void setInitialValue(int horizontal, int vertical){
	horizontal_number = horizontal;
	vertical_number = vertical;
}
void setHorizontalLeds(int red, int green, int yellow){
	HAL_GPIO_WritePin(LED_RED_HORI_GPIO_Port, LED_RED_HORI_Pin, red);
	HAL_GPIO_WritePin(LED_YELLOW_HORI_GPIO_Port, LED_YELLOW_HORI_Pin, yellow);
	HAL_GPIO_WritePin(LED_GREEN_HORI_GPIO_Port, LED_GREEN_HORI_Pin, green);
}
void setVerticalLeds(int red, int green, int yellow){
	HAL_GPIO_WritePin(LED_RED_VERTI_GPIO_Port, LED_RED_VERTI_Pin, red);
	HAL_GPIO_WritePin(LED_YELLOW_VERTI_GPIO_Port, LED_YELLOW_VERTI_Pin, yellow);
	HAL_GPIO_WritePin(LED_GREEN_VERTI_GPIO_Port, LED_GREEN_VERTI_Pin, green);
}
