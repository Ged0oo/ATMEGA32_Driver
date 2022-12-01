#include "MCAL/DIO/DIO.h"
#include "ECU/LED/LED.h"
#include "ECU/BUTTON/BUTTON.h"
#include "MCAL/TIMER_0/TIMER_0.h"
#include "MCAL/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.h"
#include "ECU/LCD/LCD.h"
#include "ECU/KEYPAD/KEYPAD.h"
#include "ECU/DC_MOTOR/DC_MOTOR.h"
#include "SERVICES/UART_SERVICES/UART_SERVICES.h"
Std_ReturnType ret = E_OK;


ST_dcMotor_t motor_1 =
{
	.pin[0].port = PORTD_INDEX,
	.pin[0].pin = GPIO_PIN4,
	.pin[0].pin_direction = GPIO_DIRECTION_OUTPUT,
	.pin[0].pin_logic = GPIO_LOW,
	
	.pin[1].port = PORTD_INDEX,
	.pin[1].pin = GPIO_PIN5,
	.pin[1].pin_direction = GPIO_DIRECTION_OUTPUT,
	.pin[1].pin_logic = GPIO_LOW,
};

int main(void)
{
	ret = DC_Motor_Init(&motor_1)
;	
	while (1)
	{
		ret = DC_Motor_Move_Right(&motor_1);
	}
}

