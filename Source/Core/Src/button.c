/*
 * button.c
 *
 *  Created on: Nov 4, 2023
 *      Author: Admin
 */

#include "button.h"

int button_flag[4] = {0};
int KeyReg[4][4] = {
		{0,0,0,0},
		{NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE},
		{NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE},
		{NORMAL_STATE,NORMAL_STATE,NORMAL_STATE,NORMAL_STATE}
};
int TimerForKeyPress = 100;

int button_ports[4] = {0, BUTTON1_GPIO_Port, BUTTON2_GPIO_Port, BUTTON3_GPIO_Port};
int button_pins[4] = {0,BUTTON1_Pin, BUTTON2_Pin, BUTTON3_Pin};

int isButtonPressed(int key){
	if(button_flag[key] == 1){
		button_flag[key] = 0;
		return 1;
	}
	return 0;
}
void subKeyProcess(int key){
	button_flag[key] = 1;
}
void getKeyInput(int key){
	KeyReg[key][0] = KeyReg[key][1];
	KeyReg[key][1] = KeyReg[key][2];
	KeyReg[key][2] = HAL_GPIO_ReadPin(button_ports[key],button_pins[key]);
	if((KeyReg[key][0] == KeyReg[key][1]) && (KeyReg[key][1] == KeyReg[key][2])){
		if(KeyReg[key][3] != KeyReg[key][2]){
			KeyReg[key][3] = KeyReg[key][2];
			if(KeyReg[key][2] == PRESSED_STATE){
				subKeyProcess(key);
				TimerForKeyPress = 100;
			}
		}else{
			TimerForKeyPress--;
			if(TimerForKeyPress == 0){
				KeyReg[key][3] = NORMAL_STATE;
			}
		}
	}
}
