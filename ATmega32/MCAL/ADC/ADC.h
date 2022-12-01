#ifndef ADC_H_
#define ADC_H_


/*					section includes					*/
#include "../StdTypes.h"
#include "../MemoryMap.h"
#include "../DIO/DIO.h"


/*					section: macro declaration					*/

#define ADC_INTERNAL_VOLTAGE_REV_OFF     0X00
#define ADC_VCC_VOLTAGE_REV              0X01
#define ADC_25_INTERNAL_VOLTAGE_REV      0X03

#define ADC_FREE_RUNNING_MODE            0X00
#define ADC_ANALOG_COMPARTOR             0X01
#define ADC_EXTERNAL_INTERRUPT_REQ       0X02
#define ADC_TMR0_COUNTER_COMPARE_MATCH   0X03
#define ADC_TMR0_COUNTER_OVERFLOW        0X04
#define ADC_TMR_COUNTER_COMPARE_MATCH    0X05
#define ADC_TMR1_COUNTER_OVERFLOW        0X06
#define ADC_TMR1_COUNTER_CAPTURE_EVENT   0X07

#define ADC_AUTO_START_DISABLE			 0
#define ADC_AUTO_START_ENABLE            1

#define ADC_READ_RIGHT_ADJUST            0X00
#define ADC_READ_LEFT_ADJUST             0X01



/*					section: macro function declaration					*/

#define ADC_SET_VOLTAGE_REV(REV)			(ADMUX |= (REV<<6))

#define ADC_SET_PRESCALER(PRESCALER)		(ADCSRA |= PRESCALER)

#define ADC_SET_READ_ADJUST(ADJUST)        (ADMUX |= (ADJUST<<5))

#define ADC_SELECT_AUTO_TRIGGER(TRIGGER)   (SFIOR |= (TRIGGER<<5))



/*					section: data type declaration					*/

typedef enum
{	
	ADC_CHANNLE_1=0,
	ADC_CHANNLE_2,
	ADC_CHANNLE_3,
	ADC_CHANNLE_4,
	ADC_CHANNLE_5,
	ADC_CHANNLE_6,
	ADC_CHANNLE_7,
}EN_chanlleslect_t;


typedef enum
{
	ADC_PRESCALER_2=0,
	ADC_PRESCALER_2_,
	ADC_PRESCALER_4,
	ADC_PRESCALER_8,
	ADC_PRESCALER_16,
	ADC_PRESCALER_32,
	ADC_PRESCALER_64,
	ADC_PRESCALER_128
}EN_prescaler_t;


typedef struct
{
	uint8 revrance;
	uint8 read_adjust;
	uint8 auto_trigger;
	uint8 start_conversion_type;
	EN_chanlleslect_t channle;
	EN_prescaler_t prescaler;
}ST_ADC_t;


/*					section:function declaration					*/

Std_ReturnType ADC_Init(const ST_ADC_t* adc);
Std_ReturnType ADC_Read(const ST_ADC_t* adc, uint16* value_conversion);
Std_ReturnType ADC_Interript_Enable(const ST_ADC_t* adc);
Std_ReturnType ADC_Interript_Disable();


#endif /* ADC_H_ */