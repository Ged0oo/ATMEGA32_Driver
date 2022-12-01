
#ifndef KEYPAD_H_
#define KEYPAD_H_


/*					section includes					*/
#include "../../MCAL/DIO/DIO.h"


/*					section: macro declaration					*/

#define NUMBER_OF_ROW       4
#define NUMBER_OF_COLUMNS   4



/*					section: macro function declaration					*/

/*					section: data type declaration					*/

typedef struct {
	ST_pinCofig_t keypad_row_pin[NUMBER_OF_ROW];
	ST_pinCofig_t keypad_column_pin[NUMBER_OF_COLUMNS];
	
}ST_keypad_t;


/*					section:function declaration					*/

Std_ReturnType keypad_intialize(const ST_keypad_t* _keypad);
Std_ReturnType keypad_get_value(const ST_keypad_t* _keypad, uint8* _value);




#endif /* KEYPAD_H_ */