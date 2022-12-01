#include "KEYPAD.h"


static const uint8 btn_value[NUMBER_OF_ROW][NUMBER_OF_COLUMNS] = 
{
	{'7' , '8' , '9' , '/'},
	{'4' , '5' , '6' , '*'},
	{'1' , '2' , '3' , '-'},
	{'#' , '0' , '=' , '+'}
};




Std_ReturnType keypad_intialize(const ST_keypad_t* _keypad)
{
	Std_ReturnType ret = E_OK;
	uint8 row_counter=0,column_counter=0;
	if(_keypad == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		for(row_counter=0;row_counter<4;row_counter++)
		{
			ret = gpio_pin_init(&(_keypad->keypad_row_pin[row_counter]));
		}
		for(column_counter=0;column_counter<4;column_counter++)
		{
			ret = gpio_pin_dirction_init(&(_keypad->keypad_column_pin[column_counter]));
		}
	}
	return ret;
}




Std_ReturnType keypad_get_value(const ST_keypad_t* _keypad, uint8* _value)
{
	Std_ReturnType ret =E_OK;
	uint8 row_counter=0, column_counter=0, l_row_counter=0;
	EN_logic_t logic = GPIO_LOW;
	if(_keypad == NULL || _value == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		for(row_counter=0;row_counter<4;row_counter++)
		{
			for(l_row_counter=0 ; l_row_counter<NUMBER_OF_ROW ; l_row_counter++)
			{
				ret = gpio_write_logic(&(_keypad->keypad_row_pin[l_row_counter]), GPIO_LOW);
			}
			ret = gpio_write_logic(&(_keypad->keypad_row_pin[row_counter]), GPIO_HIGH);
			for(column_counter=0;column_counter<4;column_counter++)
			{
				ret = gpio_read_logic(&(_keypad->keypad_column_pin[column_counter]), &logic);
				if(logic)
				{
					*_value = btn_value[row_counter][column_counter];
				}
			}
		}
	}
	return ret;
}
