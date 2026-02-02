#ifndef STRUCT_CONSOLE_H
#define STRUCT_CONSOLE_H

typedef enum
{
    STRUCT_CONSOLE_FLAG_DEBUG_MODE = 1 << 0,
} StructConsoleFlags;

typedef enum
{
    STRUCT_CONSOLE_INFO,
    STRUCT_CONSOLE_WARN,
    STRUCT_CONSOLE_ERROR,
    STRUCT_CONSOLE_DEBUG
} StructConsoleLevel;

void Struct_Console_Init(StructConsoleFlags flags);
void Struct_Console_Shutdown(void);
void Struct_Console_Print(StructConsoleLevel level, const char *fmt, ...);

#define STRUCT_CONSOLE_INFO(...) Struct_Console_Print(STRUCT_CONSOLE_INFO, __VA_ARGS__)
#define STRUCT_CONSOLE_WARN(...) Struct_Console_Print(STRUCT_CONSOLE_WARN, __VA_ARGS__)
#define STRUCT_CONSOLE_ERROR(...) Struct_Console_Print(STRUCT_CONSOLE_ERROR, __VA_ARGS__)
#define STRUCT_CONSOLE_DEBUG(...) Struct_Console_Print(STRUCT_CONSOLE_DEBUG, __VA_ARGS__)

#endif
