/**************************************************************************************
 *  [File Name]	 : DAC_interface.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef DAC_INTERFACE_H_
#define DAC_INTERFACE_H_

/* Enable Port Clock and Configure DAC pins as OUTPUT */
void HDAC_voidInit(void);

/*
 * Write one byte of the audio to the DAC port.
 * Period of the task will determine the audio frequency
 * for human at least period must be 125 us
 */
void HDAC_voidPlay(void);

/* set the array of the audio */
void HDAC_voidSetSong(const u8 *Copy_u8Arr, u32 Copy_u32SongLen);

#endif /* DAC_INTERFACE_H_ */
