#ifndef TIMER_0_H_
#define TIMER_0_H_

/*					section includes					*/
#include "../StdTypes.h"
#include "../MemoryMap.h"
#include "../DIO/DIO.h"

/*					section: macro declaration					*/

#define TIMER0_DISABLE						0X00
#define TIMER0_1_PRESCALER					0X01
#define TIMER0_8_PRESCALER					0X02
#define TIMER0_64_PRESCALER					0X03
#define TIMER0_256_PRESCALER				0X04
#define TIMER0_1024_PRESCALER				0X05
#define TIMER0_EXITRNAL_FALLING				0X06
#define TIMER0_EXITRNAL_RISING				0X07


/*					section: macro function declaration					*/

#define SET_PERSCALLEER(PRESCALER)					(TCCR0 = TCCR0 | PRESCALER)
#define SET_OCO_MODE(MODE)							(TCCR0 = TCCR0 | (MODE<<4))

#define TIMER0_OVERFLOW_INTERRUPT_ENABLE()          (TIMSK |=  (1<<TOIE0))
#define TIMER0_OVERFLOW_INTERRUPT_DISABLE()         (TIMSK &= ~(1<<TOIE0))

#define TIMER0_OC_INTERRUPT_ENABLE()				(TIMSK |=  (1<<OCIE0))
#define TIMER0_OC_INTERRUPT_DISABLE()				(TIMSK &= ~(1<<OCIE0))



/*					section: data type declaration					*/

typedef enum
{
	TIMER0_NOTMAL_MODE = 0,
	TIMER0_PHASS_CORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FAST_PWM_MODE
}EN_timer0Modes_t;

typedef enum
{
	OCO_DISCONNECTED = 0,
	OCO_TOGGLE,
	OCO_NON_INVERTING,
	OCO_INVERTING
}EN_OCOMode_t;

typedef struct
{
	uint8 prescaller;
	EN_timer0Modes_t mode;
	EN_OCOMode_t ocMode;
	void (*TIMER0_OV_interruptHandler) (void);
	void (*TIMER0_OC_interruptHandler) (void);
}ST_timer0_t;


/*					section:function declaration					*/

Std_ReturnType TMR0_init(const ST_timer0_t* timer_0);
Std_ReturnType TMR0_Write_Value(uint8 timer_0);
Std_ReturnType TMR0_Read_Value(uint8* timer_0);
Std_ReturnType TMR0_OverFlow_Iterrupt_Enable(const ST_timer0_t* timer_0);
Std_ReturnType TMR0_OverFlow_Iterrupt_Disable(const ST_timer0_t* timer_0);
Std_ReturnType TMR0_OC_Iterrupt_Enable(const ST_timer0_t* timer_0);
Std_ReturnType TMR0_OC_Iterrupt_Disnable(const ST_timer0_t* timer_0);

#endif /* TIMER_0_H_ */