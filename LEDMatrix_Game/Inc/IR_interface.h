/**************************************************************************************
 *  [File Name]	 : IR_interface.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef IR_INTERFACE_H_
#define IR_INTERFACE_H_

void HIR_voidInit(void);

void HIR_voidPlay(void);

void HIR_voidPowerButton	(void (*pvNotificationFunction)(void));
void HIR_voidModeButton		(void (*pvNotificationFunction)(void));
void HIR_voidMuteButton		(void (*pvNotificationFunction)(void));
void HIR_voidPlayButton		(void (*pvNotificationFunction)(void));
void HIR_voidLeftButton		(void (*pvNotificationFunction)(void));
void HIR_voidRightButton	(void (*pvNotificationFunction)(void));
void HIR_voidEQButton	   	(void (*pvNotificationFunction)(void));
void HIR_voidVolDownButton	(void (*pvNotificationFunction)(void));
void HIR_voidVolUPButton	(void (*pvNotificationFunction)(void));
void HIR_voidZeroButton		(void (*pvNotificationFunction)(void));
void HIR_voidRptButton		(void (*pvNotificationFunction)(void));
void HIR_voidUsdButton		(void (*pvNotificationFunction)(void));
void HIR_voidOneButton		(void (*pvNotificationFunction)(void));
void HIR_voidTwoButton		(void (*pvNotificationFunction)(void));
void HIR_voidThreeButton	(void (*pvNotificationFunction)(void));
void HIR_voidFourButton		(void (*pvNotificationFunction)(void));
void HIR_voidFiveButton		(void (*pvNotificationFunction)(void));
void HIR_voidSixButton		(void (*pvNotificationFunction)(void));
void HIR_voidSevenButton	(void (*pvNotificationFunction)(void));
void HIR_voidEightButton	(void (*pvNotificationFunction)(void));
void HIR_voidNineButton		(void (*pvNotificationFunction)(void));

#endif /* IR_INTERFACE_H_ */
