#include "inc/types.h"
#include "inc/rom.h"
#include "inc/basic.h"
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
 | 7FFF    |
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
  
db ram_memory[32 * 1024];  // total memory: 32KB

db keyboard_buffer;   // 0xD010
db keyboard_control;  // 0xD011
db display_buffer;    // 0xD012
db display_control;   // 0xD013

db read_byte(dw address)
{
    if (address >= 0x0000 && address <= 0x7FFF)
    {
        // 32KB memory RAM
        return ram_memory[address];
    }
    else if (address == 0xD010)
    {
        // when reading from keyboard buffer,
        // its status control is disabled again
        keyboard_control = 0x00;
        return keyboard_buffer;
    }
    else if (address == 0xD011)
    {
        return keyboard_control;
    }
    else if (address == 0xD012)
    {
        return display_buffer;
    }
    else if (address >= 0xE000 && address <= 0xEFFF)
    {
        // BASIC
        address = address & 0xFFF;
        return basic_memory[address];
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
    if (address >= 0x0000 && address <= 0x7FFF)
    {
        // 32KB memory RAM
        ram_memory[address] = data;
    }
    else if (address == 0xD012)
    {
        display_buffer = data | 0x80;
    }
    
    // any other addressed memory will be ignored on write
}
