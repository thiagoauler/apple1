#ifndef _APPLE_I_MEMORY_H_
#define _APPLE_I_MEMORY_H_

#include "types.h"

  db read_byte(dw address);
  dw read_word(dw address);
void write_mem(dw address, db data);

extern db keyboard_buffer;   // 0xD010
extern db keyboard_control;  // 0xD011
extern db display_buffer;    // 0xD012
extern db display_control;   // 0xD013

#endif
