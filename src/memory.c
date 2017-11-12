#include "inc/types.h"
#include "inc/ram.h"
#include "inc/rom.h"
#include "inc/memory.h"

/*

 + - - - - +
 | 0000    |
 |         |
 |         |
 |   RAM   | 
 |         |
 |         |
 | 0FFF    |
 + - - - - +
 |         |
 
    . . .
   unused   
    . . .
    
 |         |
 + - - - - +
 | FF00    |
 |         |
 |   ROM   |
 |         |
 | FFFF    |
 + - - - - +

 */

void mem_read()
{
    if (mem.mar >= 0x0000 && mem.mar <= 0x0FFF)
    {
        // 4KB memory RAM
        ram.mar = mem.mar;
        ram_read();
        mem.mdr = ram.mdr;
    }
    else if (mem.mar >= 0xFF00 && mem.mar <= 0xFFFF)
    {
        // wozmon ROM
        rom.mar = mem.mar & 0x00FF;
        rom_read();
        mem.mdr = rom.mdr;
    }
    else
    {
        mem.mdr = 0x00;
    }
}

void mem_write()
{
    if (mem.mar >= 0x0000 && mem.mar <= 0x0FFF)
    {
        // 4KB memory RAM
        ram.mar = mem.mar;
        ram.mdr = mem.mdr;
        ram_write();
    }
}
