#pragma once
#include "SDK/amx/amx.h"
#include <xstring>
#include <windows.h>

namespace utility
{
	int PawnArrayConvert(AMX *amx, char32_t *array, cell input, cell count); //in
	int PluginArrayConvert(AMX *amx, char32_t *array, cell input, cell count); //out
	int strinschar(char32_t *string, char input, int pos, int len);
	int decode(char32_t *string, char32_t *ret_str, int size);
	int encode(char32_t *string, char32_t *ret_str, int size);
};