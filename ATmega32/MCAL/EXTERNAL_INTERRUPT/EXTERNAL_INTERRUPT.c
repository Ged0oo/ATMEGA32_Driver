#include "EXTERNAL_INTERRUPT.h"


static void (*INT0_fptr) (void) = NULL;
static void (*INT1_fptr) (void) = NULL;
static void (*INT2_fptr) (void) = NULL;


static void EXI_SET_SOURCE(const ST_externalInterrupt_t* interrupt);
static void EXI_SET_EDGE(const ST_externalInterrupt_t* interrupt);


Std_ReturnType EXI_interrupt_init(const ST_externalInterrupt_t* interrupt)
{
	Std_ReturnType ret = E_OK;
	if(NULL == interrupt)
	{
		ret = E_NOT_OK;
	}
	else
	{
		EXI_SET_SOURCE(interrupt);
		EXI_SET_EDGE(interrupt);
	}
	return ret;
}


Std_ReturnType EXI_CallBack(const ST_externalInterrupt_t* interrupt)
{
	Std_ReturnType ret = E_OK;
	if(NULL == interrupt)
	{
		ret = E_NOT_OK;
	}
	else
	{
		switch(interrupt->source)
		{
			case EXI_INT0:
				INT0_fptr = (interrupt->INT0_fpt);
				break;
				
			case EXI_INT1:
				INT1_fptr = (interrupt->INT1_fpt);
				break;
				
			case EXI_INT2:
				INT2_fptr = (interrupt->INT2_fpt);
				break;
		}
	}
	return ret;
}


static void EXI_SET_SOURCE(const ST_externalInterrupt_t* interrupt)
{
	switch(interrupt->source)
	{
		case EXI_INT0:
			SET_BIT(GICR,INT0);
			break;
			
		case EXI_INT1:
			SET_BIT(GICR,INT1);
			break;
			
		case EXI_INT2:
			SET_BIT(GICR,INT2);
			break;
	}
}


static void EXI_SET_EDGE(const ST_externalInterrupt_t* interrupt)
{
	switch(interrupt->source)
	{
		case EXI_INT0:
			switch(interrupt->edge)
			{
				case EXI_INT0_GENERATE_INTERRUPT_AT_LOW_LEVEL:
					EXI_INT0_SET_EDGE(EXI_INT0_GENERATE_INTERRUPT_AT_LOW_LEVEL);
					break;
				
				case EXI_INT0_GENERATE_INTERRUPT_AT_HIGH_LEVEL:
					EXI_INT0_SET_EDGE(EXI_INT0_GENERATE_INTERRUPT_AT_HIGH_LEVEL);
					break;
					
				case EXI_INT0_GENERATE_INTERRUPT_AT_RISING_EDGE:
					EXI_INT0_SET_EDGE(EXI_INT0_GENERATE_INTERRUPT_AT_RISING_EDGE);
					break;
					
				case EXI_INT0_GENERATE_INTERRUPT_AT_FALLING_EDGE:
					EXI_INT0_SET_EDGE(EXI_INT0_GENERATE_INTERRUPT_AT_FALLING_EDGE);
					break;
			}
			break;
			
		case EXI_INT1:
			switch(interrupt->edge)
			{
				case EXI_INT1_GENERATE_INTERRUPT_AT_LOW_LEVEL:
					EXI_INT0_SET_EDGE(EXI_INT1_GENERATE_INTERRUPT_AT_LOW_LEVEL);
					break;
			
				case EXI_INT1_GENERATE_INTERRUPT_AT_HIGH_LEVEL:
					EXI_INT0_SET_EDGE(EXI_INT1_GENERATE_INTERRUPT_AT_HIGH_LEVEL);
					break;
					
				case EXI_INT0_GENERATE_INTERRUPT_AT_RISING_EDGE:
					EXI_INT0_SET_EDGE(EXI_INT1_GENERATE_INTERRUPT_AT_RISING_EDGE);
					break;
					
				case EXI_INT0_GENERATE_INTERRUPT_AT_FALLING_EDGE:
					EXI_INT0_SET_EDGE(EXI_INT1_GENERATE_INTERRUPT_AT_FALLING_EDGE);
					break;
			}
			break;
			
		case EXI_INT2:
			switch(interrupt->edge)
			{
				case EXI_INT2_GENERATE_INTERRUPT_AT_RISING_EDGE:
					EXI_INT2_SET_EDGE(EXI_INT2_GENERATE_INTERRUPT_AT_RISING_EDGE);
					break;
					
				case EXI_INT2_GENERATE_INTERRUPT_AT_FALLING_EDGE:
					EXI_INT2_SET_EDGE(EXI_INT2_GENERATE_INTERRUPT_AT_FALLING_EDGE);
					break;
			}
			break;
	}
}


ISR(INT0_vect)
{
	if(INT0_fptr != NULL)
	{
		INT0_fptr();
	}
}


ISR(INT1_vect)
{
	if(INT1_fptr != NULL)
	{
		INT1_fptr();
	}
}


ISR(INT2_vect)
{
	if(INT2_fptr != NULL)
	{
		INT2_fptr();
	}
}