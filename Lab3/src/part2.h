/*
 * part2.h
 *
 *  Created on: Oct 14, 2019
 *      Author: kylez
 */

#ifndef SRC_PART2_H_
#define SRC_PART2_H_

void timerA0_config(float period);
void timerA0_IRQHandler(void);
volatile int flag;

#endif /* SRC_PART2_H_ */
