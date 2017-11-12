#include "inc/types.h"
#include "inc/ram.h"

db ram_memory[4096]; // total memory: 4KB

void ram_read()
{
    ram.mdr = ram_memory[ram.mar];
}

void ram_write()
{
    ram_memory[ram.mar] = ram.mdr;
}
