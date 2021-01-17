#pragma once
#include "Utility.hpp"

using namespace std;

namespace utility
{
	int PawnArrayConvert(AMX *amx, char32_t *array, cell input, cell count)
	{
		cell *addr;
		amx_GetAddr(amx, input, &addr);
		for(int i = 0; i < count; i++) array[i] = addr[i];
		return 1;
	}

	int PluginArrayConvert(AMX *amx, char32_t *array, cell input, cell count)
	{
		cell *addr;
		amx_GetAddr(amx, input, &addr);
		for(int i = 0; i < count; i++) addr[i] = array[i];
		return 1;
	}

	int strinschar(char32_t *string, char input, int pos, int len)
	{
		for(int i = len; i >= pos; i--)
		{
			string[i+1] = string[i];
		}
		string[pos] = input;
		return 1;
	}
	
	int decode(char32_t *string, char32_t *ret_str, int size)
	{
		int i = 1, idx = 0;
		if(!(128 <= string[i+1] && string[i+1] <= 191)) ret_str[idx++] = string[i];
		for(; i < size; i++)
		{
			if(string[i+1] == 208 || string[i+1] == 209) continue;
			if((176 <= string[i+1] && string[i+1] <= 191) && string[i] == 208) ret_str[idx++] = string[i+1]+48;
			else if((128 <= string[i+1] && string[i+1] <= 143) && string[i] == 209) ret_str[idx++] = string[i+1]+112;
			else if((144 <= string[i+1] && string[i+1] <= 175) && string[i] == 208) ret_str[idx++] = string[i+1]+48;
			else ret_str[idx++] = string[i+1];
		}
		ret_str[idx+1] = '\0';
		return 1;
	}

	int encode(char32_t *string, char32_t *ret_str, int size)
	{
		int i = 1, idx = 0;
		for(; i < size; i++)
		{
			if(176+48 <= string[i] && string[i] <= 191+48) 
			{
				ret_str[idx++] = 208;
				ret_str[idx++] = string[i]-48;
			}
			else if(128+112 <= string[i] && string[i] <= 143+112) 
			{
				ret_str[idx++] = 209;
				ret_str[idx++] = string[i]-112;
			}
			else if(144+48 <= string[i] && string[i] <= 175+48) 
			{
				ret_str[idx++] = 208;
				ret_str[idx++] = string[i]-48;
			}
			else ret_str[idx++] = string[i];
		}
		ret_str[idx+1] = '\0';
		return 1;
	}
}