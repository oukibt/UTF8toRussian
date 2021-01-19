// UTF-8 to Russian by oukibt

#include <cstddef>

#include "SDK/amx/amx.h"
#include "SDK/plugincommon.h"
#include "pluginconfig.h"
#include <cstdio>
#include <cstdlib>
#include <pluginutils.h>
#include <Utility.hpp>

#define PLUGIN_NAME "UTF-8 to Russian"

extern void *pAMXFunctions;
void *(*logprintf)(const char *fmt, ...);

cell AMX_NATIVE_CALL decode(AMX *amx, cell *params)
{
	int size = params[2];
	char32_t *message = new char32_t[size];
	char32_t *fmess = new char32_t[size];

	utility::PawnArrayConvert(amx, message, params[1], size);
	utility::strinschar(message, ' ', 0, size);
	utility::decode(message, fmess, size);
	utility::PluginArrayConvert(amx, fmess, params[1], size);
	
	delete []message;
	delete []fmess;
	return 1;
}

cell AMX_NATIVE_CALL encode(AMX *amx, cell *params)
{
	int size = params[2];
	char32_t *message = new char32_t[size];
	char32_t *fmess = new char32_t[size*3];

	utility::PawnArrayConvert(amx, message, params[1], size);
	utility::strinschar(message, ' ', 0, size);
	utility::encode(message, fmess, size);
	utility::PluginArrayConvert(amx, fmess, params[1], size);
	
	delete []message;
	delete []fmess;
	return 1;
}

static AMX_NATIVE_INFO plugin_natives[] =
{
	{ "decode", decode },
	{ "encode", encode },
};

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
	return PLUGIN_SUPPORTS_FLAGS;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData)
{
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = (void *(*)(const char *fmt, ...))ppData[PLUGIN_DATA_LOGPRINTF];
	if (NULL == pAMXFunctions || NULL == logprintf) return false;
	logprintf("  %s plugin by oukibt was loaded", PLUGIN_NAME);
	return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
	logprintf("  %s plugin was unloaded", PLUGIN_NAME);
}

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX *amx)
{
	amx_Register(amx, plugin_natives, (int)arraysize(plugin_natives));
	return 1;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX *amx)
{
	return AMX_ERR_NONE;
}
