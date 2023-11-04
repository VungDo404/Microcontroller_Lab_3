/*
 * fsm_manual.c
 *
 *  Created on: Nov 4, 2023
 *      Author: Admin
 */


#include "fsm_manual.h"

int red_duration_clone;
int yellow_duration_clone;
int green_duration_clone;
void initializeDurationClones(){
    red_duration_clone = red_duration;
    yellow_duration_clone = yellow_duration;
    green_duration_clone = green_duration;
}
void fsm_manual_run(){

	switch (status) {
		case MAN_RED:
			setInitialValue(red_duration_clone,2);
			if(timer_flag[3] == 1){
				HAL_GPIO_TogglePin(LED_RED_HORI_GPIO_Port, LED_RED_HORI_Pin);
				HAL_GPIO_TogglePin(LED_RED_VERTI_GPIO_Port, LED_RED_VERTI_Pin);
				setTimer(100, 3);
			}
			if(isButtonPressed(1) == 1){
				setHorizontalLeds(SET,SET,SET);
				setVerticalLeds(SET,SET, SET);
				setTimer(100, 3);
				status = MAN_YELLOW;
			}
			if(isButtonPressed(2) == 1){
				red_duration_clone++;
				if(red_duration_clone >= 99) red_duration_clone = red_duration;
			}
			if(isButtonPressed(3) == 1){
				red_duration =  red_duration_clone;
				green_duration = red_duration - yellow_duration;
				status = INIT;
			}
			break;
		case MAN_YELLOW:
			setInitialValue(yellow_duration_clone,3);
			if(timer_flag[3] == 1){
				HAL_GPIO_TogglePin(LED_YELLOW_HORI_GPIO_Port, LED_YELLOW_HORI_Pin);
				HAL_GPIO_TogglePin(LED_YELLOW_VERTI_GPIO_Port, LED_YELLOW_VERTI_Pin);
				setTimer(100, 3);
			}
			if(isButtonPressed(1) == 1){
				setHorizontalLeds(SET,SET,SET);
				setVerticalLeds(SET,SET, SET);
				setTimer(100, 3);
				status = MAN_GREEN;
			}

			break;
		case MAN_GREEN:
			setInitialValue(green_duration_clone,4);
			if(timer_flag[3] == 1){
				HAL_GPIO_TogglePin(LED_GREEN_HORI_GPIO_Port, LED_GREEN_HORI_Pin);
				HAL_GPIO_TogglePin(LED_GREEN_VERTI_GPIO_Port, LED_GREEN_VERTI_Pin);
				setTimer(100, 3);
			}
			if(isButtonPressed(1) == 1){
				setHorizontalLeds(SET,SET,SET);
				setVerticalLeds(SET,SET, SET);
				status = INIT;
			}

			break;
		default:
			initializeDurationClones();
			break;
	}
}
