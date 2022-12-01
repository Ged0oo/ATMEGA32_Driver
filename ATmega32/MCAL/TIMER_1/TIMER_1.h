#ifndef TIMER_1_H_
#define TIMER_1_H_


/*					section includes					*/

#include "../StdTypes.h"
#include "../MemoryMap.h"
#include "../DIO/DIO.h"


/*					section: macro declaration					*/

#define TMR1_NO_CLOCK_SOURCE   0X00
#define TMR1_1_PRESCALER       0X01
#define TMR1_8_PRESCALER       0X02
#define TMR1_64_PRESCALER      0X03
#define TMR1_256_PRESCALER     0X04
#define TMR1_1024_PRESCALER    0X05

#define ICU_FALLING_EDGE        0x06
#define ICU_RISING_EDGE         0x07


/*					section: macro function declaration					*/

#define TMR1_SET_PRESCALER(_PRESCALER)               (TCCR1B = TCCR1B | _PRESCALER)

#define TMR1_SET_EDGE(_EDGE)                         (TCCR1B = TCCR1B | _PRESCALER)

#define TMR1_SELECT_CHANNLE(_CHANLLE)                (TCCR1A = TCCR1A | (_CHANLLE))

#define TMR1_INTERRUPT_OVER_FLOW_ENABLE()            (TIMSK = TIMSK | 0X04)
#define TMR1_INTERRUPT_OVER_FLOW_DISABLE()           (TIMSK = TIMSK & 0XFB)

#define TMR1_INTERRUPT_COMPA_ENABLE()                (TIMSK = TIMSK | 0X10)
#define TMR1_INTERRUPT_COMPA_DISABLE()               (TIMSK = TIMSK & 0XEF)

#define TMR1_INTERRUPT_COMPB_ENABLE()                (TIMSK = TIMSK | 0X08)
#define TMR1_INTERRUPT_COMPB_DISABLE()               (TIMSK = TIMSK & 0XF7)

#define TMR1_INTERRUPT_CAPT_ENABLE()                 (TIMSK = TIMSK | 0X20)
#define TMR1_INTERRUPT_CAPT_DISABLE()                (TIMSK = TIMSK & 0XDF)


/*					section: data type declaration					*/

typedef enum
{
	TMR1_NORMAL_MODE = 0,
	TMR1_PWM_PASS_CORRECT_8BIT_MODE,
	TMR1_PWM_PASS_CORRECT_9BIT_MODE,
	TMR1_PWM_PASS_CORRECT_10BIT_MODE,
	TMR1_CTC_OCR1A_MODE,
	TMR1_PWM_FAST_MODE_8BIT,
	TMR1_PWM_FAST_MODE_9BIT,
	TMR1_PWM_FAST_MODE_10BIT,
	TMR1_PWM_PASS_FRQ_ICR1_MODE,
	TMR1_PWM_PASS_FRQ_OCR1A_MODE,
	TMR1_PWM_PASS_CORRECT_ICR1_MODE,
	TMR1_PWM_PASS_CORRECT_OCR1A_MODE,
	TMR1_CTC_ICR1_MODE,
	REVERSED,
	TMR1_PWM_FAST_MODE_ICR1,
	TMR1_PWM_FAST_MODE_OCR1A
}EN_timer1Modes_t;


typedef enum
{
	NORMAL_PORT_OPRATION = 0,
	TOGGLE_IN_COMPARE_MATCH,
	CLEAR_IN_COMPARE_MATCH,
	SET_IN_COMPARE_MATCH
}EN_compareNonPwm_t;


typedef enum
{
	TIMER1_OCR1A = 0xC0,
	TIMER1_OCR1b = 0x30
}EN_timer1Channle_t;


typedef enum
{
	OC1_DISCONNECTED=0,
	OC1_TOGGLE,
	OC1_NON_INVERTING,
	OC1_INVERTING
}EN_compareFastPwm_t;


typedef struct
{
	uint8 prescaler;
	EN_timer1Modes_t mode;
	EN_compareNonPwm_t non_pwm_mode;
	EN_compareFastPwm_t fast_pwm;
	EN_timer1Channle_t channle;
	void (*(TMR1_InterriptOveFlow)) (void);
	void (*(TMR1_InterriptComA)) (void);
	void (*(TMR1_InterriptComB)) (void);
	void (*(TMR1_InterriptCAPT))(void);
}ST_timer1_t;


/*					section:function declaration					*/

Std_ReturnType TIMER1_Init(const ST_timer1_t* timer_1);
Std_ReturnType TIMER1_Interrupt_Over_Flow_enable(const ST_timer1_t* timer_1);
Std_ReturnType TIMER1_Interrupt_Over_Flow_Disable();

Std_ReturnType TIMER1_voidSetOCR1A(uint16 Copy_u16Value);
Std_ReturnType TIMER1_voidSetOCR1B(uint16 Copy_u16Value);

Std_ReturnType TIMER1_voidSetICR1(uint16 Copy_u16Value);
Std_ReturnType TIMER1_voidSetTCNT1(uint16 Copy_u16Value);

Std_ReturnType PWM_FreQ_KHz(uint16 _ferq);
Std_ReturnType PWM_FreQ_Hz(uint16 _ferq);

Std_ReturnType PWM_SetDuty_Cycle(uint8 _duty);
Std_ReturnType TIMER1_Set_CaptureEdge(uint8 _edge);

Std_ReturnType TIMER1_Interrupt_COMPA_enable(const ST_timer1_t* timer_1);
Std_ReturnType TIMER1_Interrupt_COMPA_Disable();

Std_ReturnType TMR1_Interrupt_COMPB_enable(const ST_timer1_t* timer_1);
Std_ReturnType TMR1_Interrupt_COMPB_Disable();

Std_ReturnType TIMER1_Interrupt_CAPT_enable(void (*fun)(void));
Std_ReturnType TIMER1_Interrupt_CAPT_Disable();

Std_ReturnType PWM1_voidRead(uint32 *ReturnFreq, uint8 *ReturnDuty);


#endif /* TIMER_1_H_ */