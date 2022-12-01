#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_



/*					section includes					*/
#include "../StdTypes.h"
#include "../MemoryMap.h"
#include "../DIO/DIO.h"

/*					section: macro declaration					*/

#define EXI_INT0_GENERATE_INTERRUPT_AT_LOW_LEVEL			0x00
#define EXI_INT0_GENERATE_INTERRUPT_AT_HIGH_LEVEL			0x01
#define EXI_INT0_GENERATE_INTERRUPT_AT_FALLING_EDGE			0x02
#define EXI_INT0_GENERATE_INTERRUPT_AT_RISING_EDGE			0x03

#define EXI_INT1_GENERATE_INTERRUPT_AT_LOW_LEVEL			0x00
#define EXI_INT1_GENERATE_INTERRUPT_AT_HIGH_LEVEL			0x01
#define EXI_INT1_GENERATE_INTERRUPT_AT_FALLING_EDGE			0x02
#define EXI_INT1_GENERATE_INTERRUPT_AT_RISING_EDGE			0x03

#define EXI_INT2_GENERATE_INTERRUPT_AT_RISING_EDGE			0x01
#define EXI_INT2_GENERATE_INTERRUPT_AT_FALLING_EDGE			0x00


/*					section: macro function declaration					*/

#define EXI_INT0_SET_EDGE(EDGE)								(MCUCR  |= EDGE)
#define EXI_INT1_SET_EDGE(EDGE)								(MCUCR  |= (EDGE<<2))
#define EXI_INT2_SET_EDGE(EDGE)								(MCUCSR |= (EDGE<<6))


/*					section: data type declaration					*/

typedef enum
{
	EXI_INT0,
	EXI_INT1,
	EXI_INT2
}EN_externalInterruptSource_t;


typedef struct
{
	EN_externalInterruptSource_t source;
	uint8 edge;
	void (*INT0_fpt) (void);
	void (*INT1_fpt) (void);
	void (*INT2_fpt) (void);
	
}ST_externalInterrupt_t;


/*					section:function declaration					*/

Std_ReturnType EXI_interrupt_init(const ST_externalInterrupt_t* interrupt);
Std_ReturnType EXI_CallBack(const ST_externalInterrupt_t* interrupt);


#endif /* EXTERNAL_INTERRUPT_H_ */