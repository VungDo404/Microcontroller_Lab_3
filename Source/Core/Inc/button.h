/*
 * button.h
 *
 *  Created on: Nov 4, 2023
 *      Author: Admin
 */
#include "main.h"
#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET
int isButtonPressed(int key);
void getKeyInput(int key);

#endif /* INC_BUTTON_H_ */
