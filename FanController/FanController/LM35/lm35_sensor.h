/*
 * lm35_sensor.h
 *
 *  Created on: ٢٠‏/٠٢‏/٢٠٢٤
 *  Author: AS.Mahrous
 */

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "../std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define LM35_CHANNEL_ID         2
#define LM35_MAX_VOLT_VALUE   1.5
#define LM35_MAXIMUM_TEMPERATURE_VALUE    150

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

uint8 LM35_GetTemperature(void);

#endif /* LM35_SENSOR_H_ */
