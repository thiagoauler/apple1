#ifndef _APPLE_I_OPCODES_H_
#define _APPLE_I_OPCODES_H_

#include "types.h"

dw pc; // program counter
db ac; // accumulator
db x;  // x register
db y;  // y register
db sp; // stack pointer
db ir; // intruction register

enum opcodes
{
    BIT = 0b00100,
    JMP = 0b01000,
    JPA = 0b01100,
    STY = 0b10000,
    LDY = 0b10100,
    CPY = 0b11000,
    CPX = 0b11100,
    
    ORA = 0b00001,
    AND = 0b00101,
    EOR = 0b01001,
    ADC = 0b01101,
    STA = 0b10001,
    LDA = 0b10101,
    CMP = 0b11001,
    SBC = 0b11101,
       
    ASL = 0b00010,
    ROL = 0b00110,
    LSR = 0b01010,
    ROR = 0b01110,
    STX = 0b10010,
    LDX = 0b10110,
    DEC = 0b11010,
    INC = 0b11110,
};

enum opcodes_comp
{
    BRK = 0x00,
    BPL = 0x10,
    JSR = 0x20,
    BMI = 0x30,
    RTI = 0x40,
    BVC = 0x50,
    RTS = 0x60,
    BVS = 0x70,
    BCC = 0x90,
    BCS = 0xB0,
    BNE = 0xD0,
    BEQ = 0xF0,
    
    PHP = 0x08,
    CLC = 0x18,
    PLP = 0x28,
    SEC = 0x38,
    PHA = 0x48,
    CLI = 0x58,
    PLA = 0x68,
    SEI = 0x78,
    DEY = 0x88,
    TYA = 0x98,
    TAY = 0xA8,
    CLV = 0xB8,
    INY = 0xC8,
    CLD = 0xD8,
    INX = 0xE8,
    SED = 0xF8,
    
    TXA = 0x8A,
    TXS = 0x9A,
    TAX = 0xAA,
    TSX = 0xBA,
    DEX = 0xCA,
    NOP = 0xEA
};

typedef enum opcodes oc1;
typedef enum opcodes_comp oc2;

void adc(); // add memory to accumalator with carry
void and(); // and memory with accumulator
void asl(); // shift left one bit (memory on accumulator)
void bcc(); // branch on carry clear
void bcs(); // branch on carry set
void beq(); // branch on result zero
void bit(); // test bits in memory with accumulator
void bmi(); // branch on result minus
void bne(); // branch on result not zero
void bpl(); // branch on result plus
void brk(); // force break
void bvc(); // branch on overflow clear
void bvs(); // branch on overflow set
void clc(); // clear carry flag
void cld(); // clear decimal mode
void cli(); // clear interrupt disable bit
void clv(); // clear overflow flag
void cmp(); // compare memory with accumulator
void cpx(); // compare memory and index x
void cpy(); // compare memory and index y
void dec(); // decrement memory by one
void dex(); // decrement index x by one
void dey(); // decrement index y by one
void eor(); // exclusive-or memory with accumulator
void inc(); // increment memory by one
void inx(); // increment index x by one
void iny(); // increment index y by one
void jmp(); // jump to new location
void jsr(); // jump to new location saving return address
void lda(); // load accumulator with memory
void ldx(); // load index x with memory
void ldy(); // load index y with memory
void lsr(); // shift one bit right (memory or accumulator)
void nop(); // no operation
void ora(); // or memory with accumulator
void pha(); // push accumulator on stack
void php(); // push processor status on stack
void pla(); // pull accumulator from stack
void plp(); // pull processor status from stack
void rol(); // rotate on bit left (memory or accumulator)
void ror(); // rotate on bit right (memory or accumulator)
void rti(); // return from interrupt
void rts(); // retrun from subroutine
void sbc(); // subtract memory from accumulator with borrow
void sec(); // set carry flag
void sed(); // set decimal flag
void sei(); // set interrupt disable status
void sta(); // store accumulator in memory
void stx(); // store index x in memory
void sty(); // store index y in memory
void tax(); // transfer accumulator to index x
void tay(); // transfer accumulator to index y
void tsx(); // transfer stack pointer to index x
void txa(); // transfer index x to accumulator
void txs(); // transfer index x to stack pointer
void tya(); // transfer index y to accumulator

#endif