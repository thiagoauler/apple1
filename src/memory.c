#include "inc/types.h"
#include "inc/rom.h"
#include "inc/memory.h"

/*
    
 memory model:

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
  
db ram_memory[4096]; // total memory: 4KB

db read_byte(dw address)
{
    if (address >= 0x0000 && address <= 0x0FFF)
    {
        // 4KB memory RAM
        return ram_memory[address];
    }
    else if (address >= 0xFF00 && address <= 0xFFFF)
    {
        // wozmon ROM
        address = address & 0x00FF;
        return rom_memory[address];
    }
    else
    {
        // unused memory
        return 0x00;
    }
}

dw read_word(dw address)
{
    dw word;
    db low_byte;
    db high_byte;
    
    low_byte  = read_byte(address);
    high_byte = read_byte(address + 1);
    
    word = high_byte << 8;  // shifts high byte to its place
    word = word | low_byte; // appends low byte to form the complete word
    
    // the word is store in little-endian format on the memory
    return word;
}

void write_mem(dw address, db data)
{
    if (address >= 0x0000 && address <= 0x0FFF)
    {
        // 4KB memory RAM
        ram_memory[address] = data;
    }
    
    // any other addressed memory will be ignored on write
}
