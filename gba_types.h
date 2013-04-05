/*
 * gba_types.h
 *
 *  Created on: Apr 3, 2013
 *      Author: zhl
 */

#ifndef GBA_TYPES_H_
#define GBA_TYPES_H_

#include <stdio.h>
#include <stdlib.h>
#include "vpk_log.h"

typedef unsigned int 		u32;
typedef int 				s32;
typedef unsigned short 	u16;
typedef unsigned char 	u8;

typedef int 				bool;
#define true 				1
#define false              0

#define return_if_fail(p)          if(!(p)) { ftk_logw("%s:%d "#p" failed.\n", __func__, __LINE__); return;}
#define return_val_if_fail(p, val) if(!(p)) { ftk_logw("%s:%d "#p" failed.\n", __func__, __LINE__); return (val);}

#define iprintf 			printf
#define progressDraw(...)
#define progressEnd(...)


#endif /* GBA_TYPES_H_ */
