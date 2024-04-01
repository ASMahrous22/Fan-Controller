/*
 * lm35_sensor.c
 *
 *  Created on: ٢٠‏/٠٢‏/٢٠٢٤
 *      Author: AS.Mahrous
 */

#include "../ADC/adc.h"
#include "lm35_sensor.h"
//#include "util/delay.h"

uint8 LM35_GetTemperature(void)
{
	uint8 temperature = 0;

	uint16 ADC_digitalValue = 0;

	ADC_digitalValue = ADC_readChannel(LM35_CHANNEL_ID);

	//_delay_ms(5);

	temperature = (uint8) (((uint32) LM35_MAXIMUM_TEMPERATURE_VALUE * ADC_INTERNAL_VOLT_VALUE * ADC_digitalValue) / (LM35_MAX_VOLT_VALUE * ADC_MAXIMUM_VALUE));

	return temperature;
}
