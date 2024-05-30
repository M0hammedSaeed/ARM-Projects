/**************************************************************************************
 *  [File Name]	 : IR_private.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef IR_PRIVATE_H_
#define IR_PRIVATE_H_

#define POWER_BUTTON             69
#define MODE_BUTTON              70
#define MUTE_BUTTON              71
#define PLAY_BUTTON              68
#define LEFT_BUTTON              64
#define RIGHT_BUTTON             67
#define EQ_BUTTON                7
#define VOL_DOWN_BUTTON          21
#define VOL_UP_BUTTON            9
#define ZERO_BUTTON              22
#define RPT_BUTTON               25
#define USD_BUTTON               13
#define ONE_BUTTON               12
#define TWO_BUTTON               24
#define THREE_BUTTON             94
#define FOUR_BUTTON              8
#define FIVE_BUTTON              28
#define SIX_BUTTON               90
#define SEVEN_BUTTON             66
#define EIGHT_BUTTON             82
#define NINE_BUTTON              74


#define START_EDGE_OF_DATA  	 	17
#define END_EDGE_OF_DATA     	 	24

#define FRAME_TIME                  67500

#define MIN_INTERVAL_TIME          	1000
#define MAX_INTERVAL_TIME          	1500


static void HIR_voidGetFrame(void);
static void HIR_voidTakeAction(void);

#endif /* IR_PRIVATE_H_ */
