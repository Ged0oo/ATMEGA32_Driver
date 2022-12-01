
#ifndef LCD_H_
#define LCD_H_

/*..............section : includes .......*/

#include "../../MCAL/DIO/DIO.h"

/*.............section: macro declaration.....*/
#define _LCD_CLEAR                      0X01
#define _LCD_RETURN_HOME                0x02
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF   0x04
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON    0x05
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF   0x06
#define _LCD_ENTRY_MODE_INC_SHIFT_ON    0x07


#define _LCD_CURSOR_MOVE_SHIFT_LEFT     0x10
#define _LCD_CURSOR_MOVE_SHIFT_RIGHT    0x14
#define _LCD_DISPLAY_SHIFT_LEFT         0x18
#define _LCD_DISPLAY_SHIFT_RIGHT        0x1C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF 0x0C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON  0x0D
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF  0x0E
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON   0x0F
#define _LCD_DISPLAY_OFF_CURSOR_OFF              0x08
#define _LCD_8BIT_MODE_2_LINE           0x38
#define _LCD_4BIT_MODE_2_LINE           0x28

#define _LCD_CGRAM_START                0x40
#define _LCD_DDRAM_START                0x80




#define ROW1     1
#define ROW2     2
#define ROW3     3
#define ROW4     4

/*...................section: macro function declaration.......*/


/*..........section: data type declaration..............*/

typedef struct{
	ST_pinCofig_t lcd_rs;
	ST_pinCofig_t lcd_en;
	ST_pinCofig_t lcd_data[4];

}char_4bit_lcd_t;

typedef struct{
	ST_pinCofig_t lcd_rs;
	ST_pinCofig_t lcd_en;
	ST_pinCofig_t lcd_data[8];

}char_8bit_lcd_t;

/*...............section:function declaration..........  */
Std_ReturnType LCD_4Bit_Init(const char_4bit_lcd_t *_lcd);
Std_ReturnType LCD_4Bit_Send_Command(const char_4bit_lcd_t *_lcd,uint8 _command);
Std_ReturnType LCD_4Bit_Send_Data_char(const char_4bit_lcd_t *_lcd,uint8 _char);
Std_ReturnType LCD_4Bit_send_Data_char_Pos(const char_4bit_lcd_t *_lcd, uint8 _char ,uint8 row, uint8 column);
Std_ReturnType LCD_4Bit_Send_Data_String(const char_4bit_lcd_t *_lcd,uint8 *_char);
Std_ReturnType LCD_4Bit_send_Data_String_Pos(const char_4bit_lcd_t *_lcd,uint8 *_char,uint8 row,uint8 column);
Std_ReturnType LCD_4Bit_Send_Cust_Char(const char_4bit_lcd_t *_lcd,uint8 row,uint8 column,uint8 _char[],uint8 mem_pos);
Std_ReturnType lcd_4bit_Send_Number(const char_4bit_lcd_t *_lcd,uint32 _number);
Std_ReturnType lcd_4bit_Send_Number_Pos(const char_4bit_lcd_t *_lcd,uint32 _number,uint8 row,uint8 column);





Std_ReturnType LCD_8Bit_Init(const char_8bit_lcd_t *_lcd);
Std_ReturnType lcd_8bit_send_comand(const char_8bit_lcd_t *_lcd,uint8 _command);
Std_ReturnType LCD_8Bit_Send_Data_char(const char_8bit_lcd_t *_lcd,uint8 _char);
Std_ReturnType LCD_8Bit_send_Data_char_Pos(const char_8bit_lcd_t *_lcd,uint8 _char,uint8 row,uint8 column);
Std_ReturnType LCD_8Bit_Send_Data_String(const char_8bit_lcd_t *_lcd,uint8 _char);
Std_ReturnType LCD_8Bit_send_Data_String_Pos(const char_8bit_lcd_t *_lcd,uint8 _char,uint8 row,uint8 column);


#endif /* LCD_H_ */