
#ifndef BUTTON_H_
#define BUTTON_H_


/*..............section : includes .......*/
#include "../../MCAL/DIO/DIO.h"


/*.............section: macro declaration.....*/

/*...................section: macro function declaration.......*/

/*..........section: data type declaration..............*/
typedef enum
{
	PULL_UP = 0,
	PULL_DOWN
}EN_connction_t;

typedef enum
{
	PRESSED = 0,
	RELEASSED
}EN_buttonState;

typedef struct
{
	ST_pinCofig_t pin;
	EN_connction_t connection;
	EN_buttonState state;
}ST_buton_t;


/*...............section:function declaration..........  */
Std_ReturnType Button_init(const ST_buton_t* button);
Std_ReturnType Button_read_status(const ST_buton_t* button ,EN_buttonState* state);




#endif /* BUTTON_H_ */