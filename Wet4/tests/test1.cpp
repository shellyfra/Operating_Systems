#include "aux_macro.h"
#include "../malloc_1.cpp"


int main()
{

    PRINT_POINTER(smalloc(1););
    PRINT_POINTER(smalloc(4););
    PRINT_POINTER(smalloc(64););
    PRINT_POINTER(smalloc(0););
    PRINT_POINTER(smalloc(-1););
    PRINT_POINTER(smalloc(-10););
    PRINT_POINTER(smalloc(100000000 - 1););
    PRINT_POINTER(smalloc(100000000););
    PRINT_POINTER(smalloc(100000000 + 1););
    PRINT_POINTER(smalloc(1000000000););
    PRINT_POINTER(smalloc(1000000000););
}