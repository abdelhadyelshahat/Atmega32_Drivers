/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<< KPD_prog.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
/*
 *
 *
 */

/* LIB includes */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/BIT_MATH.h"
#include <util/delay.h>

/*MCAL includes */
#include "../../MCAL/DIO/DIO_interface.h"

/* HAL include */
#include "KPD_interface.h"
#include "KPD_config.h"
#include "KPD_privite.h"


u8 KPD_Au8RowsPins[4]=   {KPD_u8_ROW1_PIN,KPD_u8_ROW2_PIN,KPD_u8_ROW3_PIN,KPD_u8_ROW4_PIN};
u8 KPD_Au8ColsPins[4]=   {KPD_u8_COL1_PIN,KPD_u8_COL2_PIN,KPD_u8_COL3_PIN,KPD_u8_COL4_PIN};


void H_KPD_void_KPDInit(void)
{
	/* Columns Initialization */
	M_DIO_u8_SetPinDirection(KPD_u8_COLs_PORT,KPD_u8_COL1_PIN,DIO_u8_PIN_INPUT_DIRECTION);
	M_DIO_u8_SetPinDirection(KPD_u8_COLs_PORT,KPD_u8_COL2_PIN,DIO_u8_PIN_INPUT_DIRECTION);
	M_DIO_u8_SetPinDirection(KPD_u8_COLs_PORT,KPD_u8_COL3_PIN,DIO_u8_PIN_INPUT_DIRECTION);
	M_DIO_u8_SetPinDirection(KPD_u8_COLs_PORT,KPD_u8_COL4_PIN,DIO_u8_PIN_INPUT_DIRECTION);

	#if KPD_u8_PULLUP_RES_AVTIVATION == KPD_u8_PULLUP_RES_INTERNAL_ACTIVATION

	/* Columns Initialization */
		M_DIO_u8_SetPinValue(KPD_u8_COLs_PORT,KPD_u8_COL1_PIN,DIO_u8_PIN_VALUE_HIGH);
		M_DIO_u8_SetPinValue(KPD_u8_COLs_PORT,KPD_u8_COL2_PIN,DIO_u8_PIN_VALUE_HIGH);
		M_DIO_u8_SetPinValue(KPD_u8_COLs_PORT,KPD_u8_COL3_PIN,DIO_u8_PIN_VALUE_HIGH);
		M_DIO_u8_SetPinValue(KPD_u8_COLs_PORT,KPD_u8_COL4_PIN,DIO_u8_PIN_VALUE_HIGH);
	#endif

	/* Rows Initialization */
	M_DIO_u8_SetPinDirection(KPD_u8_ROWs_PORT,KPD_u8_ROW1_PIN,DIO_u8_PIN_OUTPUT_DIRECTION);
	M_DIO_u8_SetPinDirection(KPD_u8_ROWs_PORT,KPD_u8_ROW2_PIN,DIO_u8_PIN_OUTPUT_DIRECTION);
	M_DIO_u8_SetPinDirection(KPD_u8_ROWs_PORT,KPD_u8_ROW3_PIN,DIO_u8_PIN_OUTPUT_DIRECTION);
	M_DIO_u8_SetPinDirection(KPD_u8_ROWs_PORT,KPD_u8_ROW4_PIN,DIO_u8_PIN_OUTPUT_DIRECTION);




}


u8 H_KPD_u8_GetKey(void)
{
	/* - Local Array to hold the Rows of pin
	 * = why ?
	 * - the Rows can be any pins from the same port ( in order or not )
	 * - so to make the algorithm more generic I will loop on the indexes values of the array
	 * */
	u8 Local_Au8RowsPins[4]=   {KPD_u8_ROW1_PIN,KPD_u8_ROW2_PIN,KPD_u8_ROW3_PIN,KPD_u8_ROW4_PIN};
	/* - Local Array to hold the Columns of pin
	 * = why ?
	 * - the Columns can be any pins from the same port ( in order or not )
	 * - so to make the algorithm more generic I will loop on the indexes values of the array
	 * */
	u8 Local_Au8ColsPins[4]=   {KPD_u8_COL1_PIN,KPD_u8_COL2_PIN,KPD_u8_COL3_PIN,KPD_u8_COL4_PIN};

	/* local variable to hold the statues of the switch*/
	u8 Local_u8SwitchStatues = KPD_u8_NO_SWICH_PRESSED;

	/* Local variable to hold*/
	u8 Local_u8Keypressed = KPD_u8_NO_SWICH_PRESSED ;
	u8 Local_u8RowsCounter ;
	u8 Local_u8ColsCounter ;
	u8 Local_flag = 0;

	for (Local_u8RowsCounter = 0 ; Local_u8RowsCounter < 4 ; Local_u8RowsCounter ++)
	{
		M_DIO_u8_SetPinValue(KPD_u8_ROWs_PORT,Local_Au8RowsPins[Local_u8RowsCounter],DIO_u8_PIN_VALUE_LOW);

		for (Local_u8ColsCounter = 0 ; Local_u8ColsCounter < 4 ; Local_u8ColsCounter++ )
		{
			M_DIO_u8_GetPinValue(KPD_u8_COLs_PORT, Local_Au8ColsPins[Local_u8ColsCounter],&Local_u8SwitchStatues)	;

			if (Local_u8SwitchStatues == DIO_u8_PIN_VALUE_LOW)
			{
				_delay_ms(50);
				M_DIO_u8_GetPinValue(KPD_u8_COLs_PORT, Local_Au8ColsPins[Local_u8ColsCounter],&Local_u8SwitchStatues)	;

					while (Local_u8SwitchStatues == DIO_u8_PIN_VALUE_LOW)
					{
						M_DIO_u8_GetPinValue(KPD_u8_COLs_PORT, Local_Au8ColsPins[Local_u8ColsCounter],&Local_u8SwitchStatues)	;
					}
					Local_u8Keypressed = KPD_Au8Matrix[Local_u8RowsCounter][Local_u8ColsCounter];
					Local_flag =1;
					break;

			}
		}
		M_DIO_u8_SetPinValue(KPD_u8_ROWs_PORT,Local_Au8RowsPins[Local_u8RowsCounter],DIO_u8_PIN_VALUE_HIGH);
		if (1 == Local_flag)
		{
			break;
		}

	}

	return Local_u8Keypressed;



}
