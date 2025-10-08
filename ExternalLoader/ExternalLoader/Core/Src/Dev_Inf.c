/*
 * Dev_Inf.c
 *
 *  Created on: Oct 7, 2025
 *      Author: deive
 */

#include "Dev_Inf.h"

#if EXTERNAL_MEM == W25Q256

struct StorageInfo const StorageInfo  =  {
		"IW-CORE-BOARD-32MB",			// Device Name + version number
		NOR_FLASH,                     	// Device Type
		0x90000000,                     // Device Start Address
		0x2000000,                 		// Device Size in Bytes (32MBytes)
		0x100,                 			// Programming Page Size 256Bytes
		0xFF, 							// Initial Content of Erased Memory
		{
			/* Specify Size and Address of Sectors (view example below */
			{0x00000200, 0x000010000},	// Sector Num : 512 ,Sector Size: 64KBytes
			{0x00000000, 0x00000000}
		}
};


#else


#endif
