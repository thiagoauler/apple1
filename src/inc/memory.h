#ifndef _APPLE_I_MEMORY_H_
#define _APPLE_I_MEMORY_H_

#include "types.h"

  db read_byte(dw address);
  dw read_word(dw address);
void write_mem(dw address, db data);

#endif
