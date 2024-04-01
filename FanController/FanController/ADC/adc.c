/*
 * adc.c
 *
 *  Created on: ١٩‏/٠٢‏/٢٠٢٤
 *      Author: AS.Mahrous
 */

#include "adc.h"
#include <avr/io.h>
#include "../common_macros.h"


void ADC_init(const ADC_ConfigType *Config_Ptr)
{
	/* ADC voltage reference selection */
	//ADMUX = (ADMUX & (0x3F)) | ((Config_Ptr -> ref_volt) & 0xC0);
	switch(Config_Ptr -> ref_volt)
	{
	case AREF:
		/* do noting */
		break;

	case AVCC:
		ADMUX = (1<<REFS0);
		break;

	case Reserved:
		/* do noting */
		break;

	case INT_REF_VOLT:
		ADMUX = (1<<REFS0) | (1<<REFS1);
		break;
	}

	/* setting prescaler */
	//ADCSRA = (ADCSRA & (0xF8)) | ((Config_Ptr -> prescaler) & 0x07);
	switch(Config_Ptr -> prescaler)
	{
	case NO_CLOCK:
			ADCSRA &=~((1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2));
	break;

	case F_CPU_2:
			ADCSRA |=(1<<ADPS0);
	break;

	case F_CPU_4:
			ADCSRA |=(1<<ADPS1) ;
	break;

	case F_CPU_8:
			ADCSRA |= (1<<ADPS0) | (1<<ADPS1);
	break;

	case F_CPU_16:
			ADCSRA |= (1<<ADPS2);
	break;

	case F_CPU_32:
			ADCSRA |= (1<<ADPS0) |(1<<ADPS2);
	break;

	case F_CPU_64:
			ADCSRA |= (1<<ADPS2)| (1<<ADPS1);
	break;

	case F_CPU_128:
			ADCSRA |= (1<<ADPS0)|(1<<ADPS2)|(1<<ADPS1) ;
	 break;
	}

	/* enabling ADC by setting ADC enable bit */
	SET_BIT(ADCSRA,ADEN);

	/* enabling ADC interrupt by setting ADC interrupt bit */
	SET_BIT(ADCSRA,ADIE);
}

uint16 ADC_readChannel(uint8 ch_num)
{
	uint16 data=0;

	/* inserting the channel number into the first 5-bits in ADMUX register */
	ADMUX = (ADMUX & 0xD0) | (ch_num & 0x1F);

	/* setting the ADSC bit to start conversion */
	SET_BIT(ADCSRA,ADSC);

	/* polling condition " waiting until ADC interrupt flag = 1 " */
	while(BIT_IS_CLEAR(ADCSRA,ADSC));

	/* clearing ADC interrupt flag */
	SET_BIT(ADCSRA,ADIF);

	/* reading the data updated in the ADC register */
	data = ADC;

	return data;
}
