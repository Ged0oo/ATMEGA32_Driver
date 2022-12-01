
/*
 * DC_MOTOR.c
 *
 * Created: 10/28/2022 12:42:59 AM
 *  Author: Mohamed Nagy
 */ 

#include "DC_MOTOR.h"

Std_ReturnType DC_Motor_Init(const ST_dcMotor_t* _motor)
{
	Std_ReturnType ret = E_OK;
	if(_motor == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		ret = gpio_pin_dirction_init(&(_motor->pin[0]));
		ret = gpio_write_logic(&(_motor->pin[0]),GPIO_LOW);
		ret = gpio_pin_dirction_init(&(_motor->pin[1]));
		ret = gpio_write_logic(&(_motor->pin[1]),GPIO_LOW);
	}
	return ret;
}


Std_ReturnType DC_Motor_Move_Right(const ST_dcMotor_t* _motor)
{
	Std_ReturnType ret =E_OK;
	if(_motor == NULL){
		ret = E_NOT_OK;
	}
	else{
		ret = gpio_write_logic(&(_motor->pin[0]),GPIO_LOW);
		ret = gpio_write_logic(&(_motor->pin[1]),GPIO_HIGH);
	}
	return ret;
}


Std_ReturnType DC_Motor_Move_Lift(const ST_dcMotor_t* _motor)
{
	Std_ReturnType ret =E_OK;
	if(_motor == NULL){
		ret = E_NOT_OK;
	}
	else{
		ret = gpio_write_logic(&(_motor->pin[0]),GPIO_HIGH);
		ret = gpio_write_logic(&(_motor->pin[1]),GPIO_LOW);
	}
	return ret;
}


Std_ReturnType DC_Stop_Motor(const ST_dcMotor_t* _motor)
{
	Std_ReturnType ret =E_OK;
	if(_motor == NULL){
		ret = E_NOT_OK;
	}
	else{
		ret = gpio_write_logic(&(_motor->pin[0]),GPIO_LOW);
		ret = gpio_write_logic(&(_motor->pin[1]),GPIO_LOW);
	}
	return ret;
}