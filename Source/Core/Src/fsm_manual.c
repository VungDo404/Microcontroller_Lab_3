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

			if(isButtonPressed(1) == 1){
				setHorizontalLeds(SET,SET,SET);
				setVerticalLeds(SET,SET, SET);
				setTimer(100, 3);
				status = MAN_YELLOW;
			}

			break;
		case MAN_YELLOW:
			setInitialValue(yellow_duration_clone,3);

			if(isButtonPressed(1) == 1){
				setHorizontalLeds(SET,SET,SET);
				setVerticalLeds(SET,SET, SET);
				setTimer(100, 3);
				status = MAN_GREEN;
			}

			break;
		case MAN_GREEN:
			setInitialValue(green_duration_clone,4);

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
