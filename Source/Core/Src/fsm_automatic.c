/*
 * fsm_automatic.c
 *
 *  Created on: Nov 4, 2023
 *      Author: Admin
 */

#include "fsm_automatic.h"

int red_duration = 5;
int green_duration = 3;
int yellow_duration = 2;
int index_led = 0;


void fsm_automatic_run(){
	switch(status) {
		case INIT:
			status = RED_GREEN;
			setInitialValue(red_duration, green_duration);
			setTimer(green_duration*100, 0);
			setTimer(100, 1);
			setTimer(10, 2);
			break;
		case RED_GREEN:
			setHorizontalLeds(RESET,SET,SET);
			setVerticalLeds(SET,RESET, SET);

			if(timer_flag[0] == 1){
				setInitialValue(yellow_duration, yellow_duration);
				setTimer(yellow_duration*100, 0);
				status = RED_YELLOW;
			}
			if(timer_flag[1] == 1){
				countDown();
				setTimer(100, 1);
			}
			if(isButtonPressed(1) == 1){
				setHorizontalLeds(SET,SET,SET);
				setVerticalLeds(SET,SET, SET);
				setTimer(100, 3);
				status = MAN_RED;
			}
			if(timer_flag[2] == 1){
				updateClockBuffer();
				update7SEG(index_led++);
				if(index_led >= 4) index_led = 0;
				setTimer(10, 2);
			}
			break;
		case RED_YELLOW:
			setHorizontalLeds(RESET,SET,SET);
			setVerticalLeds(SET,SET, RESET);
			if(timer_flag[0] == 1){
				setInitialValue(green_duration, red_duration);
				setTimer(green_duration*100, 0);
				status = GREEN_RED;
			}
			if(timer_flag[1] == 1){
				countDown();
				setTimer(100, 1);
			}
			if(timer_flag[2] == 1){
				updateClockBuffer();
				update7SEG(index_led++);
				if(index_led >= 4) index_led = 0;
				setTimer(10, 2);
			}
			break;
		case GREEN_RED:
			setHorizontalLeds(SET,RESET,SET);
			setVerticalLeds(RESET,SET,SET);
			if(timer_flag[0] == 1){
				setInitialValue(yellow_duration, yellow_duration);
				setTimer(yellow_duration*100, 0);
				status = GREEN_YELLOW;
			}
			if(timer_flag[1] == 1){
				countDown();
				setTimer(100, 1);
			}
			if(timer_flag[2] == 1){
				updateClockBuffer();
				update7SEG(index_led++);
				if(index_led >= 4) index_led = 0;
				setTimer(10, 2);
			}
			break;
		case GREEN_YELLOW:
			setHorizontalLeds(SET,RESET,SET);
			setVerticalLeds(SET,SET,RESET);
			if(timer_flag[0] == 1){
				setInitialValue(red_duration, green_duration);
				setTimer(green_duration*100, 0);
				status = RED_GREEN;
			}
			if(timer_flag[1] == 1){
				countDown();
				setTimer(100, 1);
			}
			if(timer_flag[2] == 1){
				updateClockBuffer();
				update7SEG(index_led++);
				if(index_led >= 4) index_led = 0;
				setTimer(10, 2);
			}
			break;
		default:
			break;
	}


};
