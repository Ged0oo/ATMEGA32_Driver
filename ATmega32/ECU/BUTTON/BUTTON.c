#include "BUTTON.h"

Std_ReturnType Button_init(const ST_buton_t* button)
{
	Std_ReturnType ret = E_OK;
	if(button == NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		gpio_pin_dirction_init(&(button->pin));
	}
	return ret;
}


Std_ReturnType Button_read_status(const ST_buton_t* button, EN_buttonState* state)
{
	Std_ReturnType ret = E_OK;
	EN_logic_t Pin_Logic_Status = GPIO_LOW;
	
	if(button==NULL || state==NULL)
	{
		ret = E_NOT_OK;
	}
	else
	{
		gpio_read_logic(&(button->pin), &Pin_Logic_Status);
		switch(button->connection)
		{
			case PULL_DOWN :
			{
				if(GPIO_HIGH == Pin_Logic_Status)
				{
					*state = PRESSED;
				}
				else
				{
					*state = RELEASSED;
				}
				break;
			}
			
			case PULL_UP:
			{
				if(GPIO_HIGH == Pin_Logic_Status)
				{
					*state = RELEASSED;
				}
				else
				{
					*state = PRESSED;
				}
				break;
			}
			
			default: 
			{
				ret = E_NOT_OK;	
				break;
			}
			
			ret = E_OK;
		}
	}
	return ret;
}
