
/*
 * DC_MOTOR.h
 *
 * Created: 10/28/2022 12:43:12 AM
 *  Author: Mohamed Nagy
 */ 

#ifndef DC_MOTOR_H
#define	DC_MOTOR_H

/*..............section : includes .......*/
#include "../../MCAL/DIO/DIO.h"

/*.............section: macro declaration.....*/

/*...................section: macro function declaration.......*/

/*..........section: data type declaration..............*/
typedef struct{
	
	ST_pinCofig_t pin[2];

}ST_dcMotor_t;
/*...............section:function declaration..........  */

Std_ReturnType DC_Motor_Init(const ST_dcMotor_t* _motor);
Std_ReturnType DC_Motor_Move_Right(const ST_dcMotor_t* _motor);
Std_ReturnType DC_Motor_Move_Lift(const ST_dcMotor_t* _motor);
Std_ReturnType DC_Stop_Motor(const ST_dcMotor_t* _motor);

#endif	/* DC_MOTOR_H */

