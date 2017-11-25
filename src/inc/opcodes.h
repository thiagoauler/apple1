#ifndef _APPLE_I_OPCODES_H_
#define _APPLE_I_OPCODES_H_

#include "types.h"

extern dw pc; // program counter
extern db ac; // accumulator
extern db x;  // x register
extern db y;  // y register
extern db sp; // stack pointer
extern db sr; // status register
extern db ir; // instruction register

enum opcodes_table
{       ///        aaa00            aaa01            aaa10
/* aaa *///================================================
/* 000 */                   ORA = 0b00001,   ASL = 0b00010,
/* 001 */  BIT = 0b00100,   AND = 0b00101,   ROL = 0b00110,
/* 010 */  JMP = 0b01000,   EOR = 0b01001,   LSR = 0b01010,
/* 011 */  JPA = 0b01100,   ADC = 0b01101,   ROR = 0b01110,
/* 100 */  STY = 0b10000,   STA = 0b10001,   STX = 0b10010,
/* 101 */  LDY = 0b10100,   LDA = 0b10101,   LDX = 0b10110,
/* 110 */  CPY = 0b11000,   CMP = 0b11001,   DEC = 0b11010,
/* 111 */  CPX = 0b11100,   SBC = 0b11101,   INC = 0b11110
};

enum opcodes_list
{
    BRK = 0x00, BPL = 0x10, JSR = 0x20, BMI = 0x30, RTI = 0x40, BVC = 0x50,
    RTS = 0x60, BVS = 0x70, BCC = 0x90, BCS = 0xB0, BNE = 0xD0, BEQ = 0xF0,
    PHP = 0x08, CLC = 0x18, PLP = 0x28, SEC = 0x38, PHA = 0x48, CLI = 0x58, PLA = 0x68, SEI = 0x78,
    DEY = 0x88, TYA = 0x98, TAY = 0xA8, CLV = 0xB8, INY = 0xC8, CLD = 0xD8, INX = 0xE8, SED = 0xF8,
    TXA = 0x8A, TXS = 0x9A, TAX = 0xAA, TSX = 0xBA, DEX = 0xCA, NOP = 0xEA
};

enum address_mode
{
    immediate   = 0b000,
    zero_page   = 0b001,
    accumulator = 0b010,
    absolute    = 0b011,
    indirect_y  = 0b100,
    zero_page_x = 0b101,
    absolute_y  = 0b110,
    absolute_x  = 0b111,
    indirect_x,
    zero_page_y,
    relative
};

typedef enum opcodes_table oct;
typedef enum opcodes_list  ocl;
typedef enum address_mode  am;

extern am address_mode;

void adc(void); // add memory to accumulator with carry
void and(void); // and memory with accumulator
void asl(void); // shift left one bit (memory or accumulator)
void bcc(void); // branch on carry clear
void bcs(void); // branch on carry set
void beq(void); // branch on result zero
void bit(void); // test bits in memory with accumulator
void bmi(void); // branch on result minus
void bne(void); // branch on result not zero
void bpl(void); // branch on result plus
void brk(void); // force break
void bvc(void); // branch on overflow clear
void bvs(void); // branch on overflow set
void clc(void); // clear carry flag
void cld(void); // clear decimal mode
void cli(void); // clear interrupt disable bit
void clv(void); // clear overflow flag
void cmp(void); // compare memory with accumulator
void cpx(void); // compare memory and index x
void cpy(void); // compare memory and index y
void dec(void); // decrement memory by one
void dex(void); // decrement index x by one
void dey(void); // decrement index y by one
void eor(void); // exclusive-or memory with accumulator
void inc(void); // increment memory by one
void inx(void); // increment index x by one
void iny(void); // increment index y by one
void jmp(void); // jump to new location (indirect)
void jpa(void); // jump to new location (absolute)
void jsr(void); // jump to new location saving return address
void lda(void); // load accumulator with memory
void ldx(void); // load index x with memory
void ldy(void); // load index y with memory
void lsr(void); // shift one bit right (memory or accumulator)
void nop(void); // no operation
void ora(void); // or memory with accumulator
void pha(void); // push accumulator on stack
void php(void); // push processor status on stack
void pla(void); // pull accumulator from stack
void plp(void); // pull processor status from stack
void rol(void); // rotate on bit left (memory or accumulator)
void ror(void); // rotate on bit right (memory or accumulator)
void rti(void); // return from interrupt
void rts(void); // return from subroutine
void sbc(void); // subtract memory from accumulator with borrow
void sec(void); // set carry flag
void sed(void); // set decimal flag
void sei(void); // set interrupt disable status
void sta(void); // store accumulator in memory
void stx(void); // store index x in memory
void sty(void); // store index y in memory
void tax(void); // transfer accumulator to index x
void tay(void); // transfer accumulator to index y
void tsx(void); // transfer stack pointer to index x
void txa(void); // transfer index x to accumulator
void txs(void); // transfer index x to stack pointer
void tya(void); // transfer index y to accumulator

#define N_IS_SET    (sr & 0b10000000) // negative
#define N_SET   sr = sr | 0b10000000
#define N_UNSET sr = sr & 0b01111111
#define V_IS_SET    (sr & 0b01000000) // overflow
#define V_SET   sr = sr | 0b01000000
#define V_UNSET sr = sr & 0b10111111
#define B_IS_SET    (sr & 0b00010000) // break
#define B_SET   sr = sr | 0b00010000
#define B_UNSET sr = sr & 0b11101111
#define D_IS_SET    (sr & 0b00001000) // decimal mode
#define D_SET   sr = sr | 0b00001000
#define D_UNSET sr = sr & 0b11110111
#define I_IS_SET    (sr & 0b00000100) // interrupt disabled
#define I_SET   sr = sr | 0b00000100
#define I_UNSET sr = sr & 0b11111011
#define Z_IS_SET    (sr & 0b00000010) // zero
#define Z_SET   sr = sr | 0b00000010
#define Z_UNSET sr = sr & 0b11111101
#define C_IS_SET    (sr & 0b00000001) // carry
#define C_SET   sr = sr | 0b00000001
#define C_UNSET sr = sr & 0b11111110

#endif
