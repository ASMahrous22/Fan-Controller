/*
 * fan_controller.c
 *
 *  Created on: ٢٥‏/٠٢‏/٢٠٢٤
 *  Author: AS.Mahrous
 */
#include "LCD/lcd.h"
#include "ADC/adc.h"
#include "LM35/lm35_sensor.h"
#include "DC_Motor/dc_motor.h"

int main(void)
{
	uint8 temp = 0;
	/* Setting the ADC configuration values " prescaler & reference voltage " */
	ADC_Settings.prescaler = F_CPU_8;
	ADC_Settings.ref_volt = INT_REF_VOLT;

	ADC_init(&ADC_Settings);	           /* Initializing ADC with the chosen configurations */
	DcMotor_init();	                       /* Initializing DC-Motor */
	LCD_init();             	           /* Initializing LCD */

	LCD_moveCursor(1,0);
	LCD_displayString("Temp =    C");

	for(;;)
	{
		/* this if-else is to print the fan condition on or off on the first row */
		if(temp < 30)
		{
			LCD_displayStringRowColumn(0,0,"FAN is OFF");
		}
		else
		{
			LCD_displayStringRowColumn(0,0,"FAN is ON");
			LCD_displayCharacter(' ');
		}

		/* this if-else is to print the temperature value on the second row */
		LCD_moveCursor(1,7);
		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
		}

		/* this multiple if conditions is to adjust the fan speed  */
		temp = LM35_GetTemperature();
		if(temp < 30)
		{
			DcMotor_Rotate(STOP,0);
		}
		if(temp >= 30)
		{
			DcMotor_Rotate(CW,MAX_SPEED * 0.25);
		}
		if(temp >= 60)
		{
			DcMotor_Rotate(CW,MAX_SPEED * 0.50);
		}
		if(temp >= 90)
		{
			DcMotor_Rotate(CW,MAX_SPEED * 0.75);
		}
		if(temp >= 120)
		{
			DcMotor_Rotate(CW,MAX_SPEED);
		}

	}
}
