/*
 * Dev_Inf.h
 *
 *  Created on: Oct 7, 2025
 *      Author: deive
 */

#ifndef INC_DEV_INF_H_
#define INC_DEV_INF_H_

#define	NOR_FLASH       3
#define	SECTOR_NUM      10


struct DeviceSectors
{
	unsigned long		SectorNum;                                              // Number of Sectors
	unsigned long		SectorSize;                                             // Sector Size in Bytes
};

struct StorageInfo
{
	char                 DeviceName[100];			                // Device Name and Description
	unsigned short       DeviceType;					        // Device Type: ONCHIP, EXT8BIT, EXT16BIT, ...
	unsigned long        DeviceStartAddress;		                        // Default Device Start Address
	unsigned long        DeviceSize;					        // Total Size of Device
	unsigned long        PageSize;					        // Programming Page Size
	unsigned char        EraseValue;					        // Content of Erased Memory
	struct 	        DeviceSectors	 sectors[SECTOR_NUM];
};

#endif /* INC_DEV_INF_H_ */
