#include "ADC.h"


static void (*(ADC_InterruptCallBack))(void);


Std_ReturnType ADC_Init(const ST_ADC_t* adc)
{
	Std_ReturnType ret=E_OK;
	if(NULL == adc)
	{
		ret = E_NOT_OK;
	}
	else
	{
		DDRA=0;
		ADC_SET_VOLTAGE_REV(adc->revrance);
		ADC_SET_PRESCALER(adc->prescaler);
		ADC_SET_READ_ADJUST(adc->read_adjust);
		if(adc->start_conversion_type == ADC_AUTO_START_ENABLE)
		{
			SET_BIT(ADCSRA,ADATE);
			ADC_SELECT_AUTO_TRIGGER(adc->auto_trigger);
			
		}
		else if(adc->start_conversion_type == ADC_AUTO_START_DISABLE)
		{
			CLEAR_BIT(ADCSRA,ADATE);
		}
		CLEAR_BIT(ADCSRA,ADIE);
		SET_BIT(ADCSRA,ADEN);
		SET_BIT(ADCSRA,ADSC);
	}
	return ret;
}


Std_ReturnType ADC_Read(const ST_ADC_t* adc, uint16* value_conversion)
{
	Std_ReturnType ret=E_OK;
	EN_chanlleslect_t chanle = adc->channle;
	chanle &= 0x07;
	ADMUX &= 0xE0;
	ADMUX |=(uint8)chanle;
	SET_BIT(ADCSRA,ADSC);
	while(READ_BIT(ADCSRA,ADSC));

	if(adc->read_adjust == ADC_READ_RIGHT_ADJUST)
	{
		*value_conversion = ADCL;
		*value_conversion += (ADCH << 8);
	}
	else if(adc->read_adjust == ADC_READ_LEFT_ADJUST)
	{
		*value_conversion = (ADCL>>6);
		*value_conversion += (ADCH<<2);
	}
	else
	{
		*value_conversion = ADCL;
		*value_conversion += (ADCH << 8);
	}
	*value_conversion = adc;
	return ret;
}


Std_ReturnType ADC_Interript_Enable(const ST_ADC_t* adc);
Std_ReturnType ADC_Interript_Disable();
