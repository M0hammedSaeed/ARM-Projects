/**************************************************************************************
 *  [File Name]	 : NVIC_private.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

/********************************************************************************
 *                              Register Description
 ********************************************************************************/

/* Struct for the NVIC Register Mapping */
typedef struct
{
	volatile u32 ISER[3]       ;   /* INTERRUPT SET-ENABLE REGISTERS */
	volatile u32 RESERVED0[29] ;
	volatile u32 ICER[3]       ;   /* INTERRUPT CLEAR-ENABLE REGISTERS */
	volatile u32 RESERVED1[29] ;
	volatile u32 ISPR[3]       ;   /* INTERRUPT SET-PENDING REGISTERS */
	volatile u32 RESERVED2[29] ;
	volatile u32 ICPR[3]       ;   /* INTERRUPT CLEAR-PENDING REGISTERS */
	volatile u32 RESERVED3[29] ;
	volatile u32 IABR[3]       ;   /* INTERRUPT ACTIVE BIT REGISTERS */
	volatile u32 RESERVED4[61] ;
	volatile u8 IPR[80]        ;   /* INTERRUPT PRIORITY REGISTERS BASE ADDRESS */
}MNVIC_t;

/* Register Definitions */
#define MNVIC_BASE_ADDRESS		0xE000E100
#define MNVIC                    ((volatile MNVIC_t *) MNVIC_BASE_ADDRESS)
#define MNVIC_STIR             	*((volatile u32 *) MNVIC_BASE_ADDRESS + 0xE00 )
#define SCB_AIRCR             	*((volatile u32 *) 0xE000ED0C )


/* constants */
#define AIRCR_PRIVKEY         	0x05FA0000
#define GROUPING_BIT          	8


/* Group priority options */
#define MNVIC_GROUP_4_SUB_0		0b011	/* 16 Priority Levels, No Sub-priority 		  */
#define MNVIC_GROUP_3_SUB_1		0b100	/* 8  Priority Levels, 2  Sub-priority Levels */
#define MNVIC_GROUP_2_SUB_2		0b101	/* 4  Priority Levels, 4  Sub-priority Levels */
#define MNVIC_GROUP_1_SUB_3		0b110	/* 2  Priority Levels, 8  Sub-priority Levels */
#define MNVIC_GROUP_0_SUB_4		0b111	/* No Grouping, 	   16 Sub-priority Levels */

#endif	/* NVIC_PRIVATE_H_ */
