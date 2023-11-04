/*
 * global.h
 *
 *  Created on: Nov 4, 2023
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"

#define INIT 1
#define RED_GREEN 2
#define RED_YELLOW 3
#define GREEN_RED 4
#define GREEN_YELLOW 5

#define MAN_RED 11
#define MAN_YELLOW 12
#define MAN_GREEN 13

extern int status;
extern int led_buffer[4];
extern int index_led;
extern int horizontal_number;
extern int vertical_number;
void display7SEG(int num);
void update7SEG (int index);
void updateClockBuffer();
void countDown();
void setInitialValue(int horizontal, int vertical);
void setHorizontalLeds(int red, int green, int yellow);
void setVerticalLeds(int red, int green, int yellow);

extern int red_duration;
extern int green_duration;
extern int yellow_duration;

#endif /* INC_GLOBAL_H_ */
