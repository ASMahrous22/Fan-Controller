/*
 * adc.h
 *
 *  Created on: ١٩‏/٠٢‏/٢٠٢٤
 *  Author: AS.Mahrous
 */

#ifndef ADC_H_
#define ADC_H_

#include "../std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   5
#define ADC_INTERNAL_VOLT_VALUE   2.56

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef struct
{
	enum ADC_ReferenceVoltage
	{
		AREF,AVCC,Reserved,INT_REF_VOLT
	}ref_volt;

	enum ADC_Prescaler
	{
		NO_CLOCK,F_CPU_2,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
	}prescaler;

}ADC_ConfigType;

ADC_ConfigType ADC_Settings;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType *Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
