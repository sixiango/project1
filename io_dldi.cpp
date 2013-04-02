#include "disc_io.h"

static bool g_binited = false;
bool virtual_card_startup()
{

	g_binited = true;

	return true;
}

bool virtual_card_isinserted()

{
	return g_binited;
}

bool virtual_card_read_sector(u32 sector, u8 numSecs, void* buffer)
{

	return true;
}

bool virtual_card_write_sector(u32 sector, u8 numSecs, void* buffer)
{

	return true;
}

bool virtual_card_clear_status()
{

	return true;
}

bool virtual_card_shutdown()
{
	return true;
}

//
//IO_INTERFACE _io_dldi={
//	.ul_ioType:"DLDI",
//	.ul_Features = 0x00000000,
//	.fn_StartUp = virtual_card_startup,
//	.fn_IsInserted = virtual_card_startup,
//	.fn_ReadSectors = virtual_card_read_sector,
//	.fn_WriteSectors = virtual_card_write_sector,
//	.fn_ClearStatus = virtual_card_clear_status,
//	.fn_Shutdown = virtual_card_shutdown
//};

IO_INTERFACE _io_dldi={
	/*"DLDI"*/0xDEDE,
	0x00000000,
	virtual_card_startup,
	virtual_card_startup,
	virtual_card_read_sector,
	virtual_card_write_sector,
	virtual_card_clear_status,
	virtual_card_shutdown
};