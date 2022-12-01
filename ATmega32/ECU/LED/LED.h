#ifndef LED_H
#define	LED_H

/*..............section : includes .......*/
#include "../../MCAL/DIO/DIO.h"

/*.............section: macro declaration.....*/

/*...................section: macro function declaration.......*/

/*..........section: data type declaration..............*/

typedef enum
{
    LED_OFF = 0,
    LED_ON        
}EN_ledStatus_t;

typedef struct
{
    uint8 port;
    uint8 pin;
    EN_ledStatus_t status;
}ST_led_t;

/*...............section:function declaration  */

Std_ReturnType Led_Init(const ST_led_t* led);
Std_ReturnType Led_Turn_On(const ST_led_t* led);
Std_ReturnType Led_Turn_Off(const ST_led_t* led);
Std_ReturnType Led_Toggle(const ST_led_t* led);

#endif	/* LED_H */

