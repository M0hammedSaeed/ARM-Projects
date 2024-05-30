/**************************************************************************************
 *  [File Name]	 : NVIC_config.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef NVIC_CONFIG_H_
#define NVIC_CONFIG_H_

/*
 * Priority Grouping Options for NVIC
 *
 * Options:
 * - MNVIC_GROUP_4_SUB_0:  16 Priority Levels, No Sub-priority.
 * - MNVIC_GROUP_3_SUB_1:  8  Priority Levels, 2  Sub-priority Levels.
 * - MNVIC_GROUP_2_SUB_2:  4  Priority Levels, 4  Sub-priority Levels.
 * - MNVIC_GROUP_1_SUB_3:  2  Priority Levels, 8  Sub-priority Levels.
 * - MNVIC_GROUP_0_SUB_4:  No Grouping, 16 Sub-priority Levels.
 */

#define MNVIC_GROUP_SUB_DISTRIBUTION   MNVIC_GROUP_2_SUB_2

#endif	/* NVIC_CONFIG_H_ */
