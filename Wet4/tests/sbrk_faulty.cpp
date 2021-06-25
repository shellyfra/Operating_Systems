#include <stdint.h>
#include <stdio.h>
void *sbrk(intptr_t increment)
{
     increment++;
     printf("Faulty sbrk\n");
     return (void*) -1;
}