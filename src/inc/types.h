#ifndef _APPLE_I_TYPES_H_
#define _APPLE_I_TYPES_H_

typedef unsigned char  db;
typedef unsigned short dw;
typedef unsigned int   dd;

struct memory_registers
{
    dw mar; // memory address register
    db mdr; // memory data register
};

typedef struct memory_registers mr;

#endif
