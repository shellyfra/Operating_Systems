#ifndef _AUX_H
#define _AUX_H
// Macros used for DEBUG (if compiled with DDEBUG flag)
#include <stdio.h>

void *base_address;
void *last_address;
bool set_base = false;

#define DEBUG_PRINT(command)  \
    do                        \
    {                         \
        printf("Executing "); \
        printf(#command);     \
        printf("\n");         \
        command               \
    } while (0)

#define PRINT_POINTER(command)                                           \
    do                                                                   \
    {                                                                    \
        void *temp;                                                      \
        if (!set_base)                                                   \
        {                                                                \
            set_base = true;                                             \
            DEBUG_PRINT(base_address = command);                         \
            temp = base_address;                                         \
        }                                                                \
        else                                                             \
            DEBUG_PRINT(temp = command);                                 \
        last_address = temp;                                             \
        if (!temp)                                                       \
        {                                                                \
            printf("Relative pointer: NULL\n");                          \
        }                                                                \
        else                                                             \
        {                                                                \
            void *rel_p = (void *)((char *)temp - (char *)base_address); \
            if (!rel_p)                                                  \
                printf("Relative pointer: 0x0\n");                       \
            else                                                         \
                printf("Relative pointer: %p\n", rel_p);                 \
        }                                                                \
    } while (0)

#endif