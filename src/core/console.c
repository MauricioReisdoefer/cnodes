#include "console.h"
#include <stdio.h>
#include <stdarg.h>

static unsigned int _console_flags;

void Struct_Console_Init(StructConsoleFlags flags)
{
    _console_flags = flags;
}

void Struct_Console_Shutdown(void)
{
}

void Struct_Console_Print(StructConsoleLevel level, const char *fmt, ...)
{
    const char *prefix = "";

    switch (level)
    {
    case STRUCT_CONSOLE_INFO:
        prefix = "[INFO] ";
        break;
    case STRUCT_CONSOLE_WARN:
        prefix = "[WARN] ";
        break;
    case STRUCT_CONSOLE_ERROR:
        prefix = "[ERROR] ";
        break;
    case STRUCT_CONSOLE_DEBUG:
        prefix = "[DEBUG] ";
        break;
    }

    if (!(_console_flags & STRUCT_CONSOLE_FLAG_DEBUG_MODE) && level == STRUCT_CONSOLE_DEBUG)
    {
        return;
    }

    printf("%s", prefix);

    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);

    printf("\n");
}