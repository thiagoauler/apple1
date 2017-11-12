#include <stdio.h>

#include "inc/opcodes.h"

void adc()
{
    // add memory to accumalator with carry
    printf("ADC\n");
}

void and()
{
    // and memory with accumulator
    printf("AND\n");
}

void asl()
{
    // shift left one bit (memory on accumulator)
    printf("ASL\n");
}

void bcc()
{
    // branch on carry clear
    printf("BCC\n");
}

void bcs()
{
    // branch on carry set
    printf("BSC\n");
}

void beq()
{
    // branch on result zero
    printf("BEQ\n");
}

void bit()
{
    // test bits in memory with accumulator
    printf("BIT\n");
}

void bmi()
{
    // branch on result minus
    printf("BMI\n");
}

void bne()
{
    // branch on result not zero
    printf("BNE\n");
}

void bpl()
{
    // branch on result plus
    printf("BPL\n");
}

void brk()
{
    // force break
    printf("BRK\n");
}

void bvc()
{
    // branch on overflow clear
    printf("BVC\n");
}

void bvs()
{
    // branch on overflow set
    printf("BVS\n");
}

void clc()
{
    // clear carry flag
    printf("CLC\n");
}

void cld()
{
    // clear decimal mode
    printf("CLD\n");
}

void cli()
{
    // clear interrupt disable bit
    printf("CLI\n");
}

void clv()
{
    // clear overflow flag
    printf("CLV\n");
}

void cmp()
{
    // compare memory with accumulator
    printf("CMP\n");
}

void cpx()
{
    // compare memory and index x
    printf("CPX\n");
}

void cpy()
{
    // compare memory and index y
    printf("CPY\n");
}

void dec()
{
    // decrement memory by one
    printf("DEC\n");
}

void dex()
{
    // decrement index x by one
    printf("DEX\n");
}

void dey()
{
    // decrement index y by one
    printf("DEY\n");
}

void eor()
{
    // exclusive-or memory with accumulator
    printf("EOR\n");
}

void inc()
{
    // increment memory by one
    printf("INC\n");
}

void inx()
{
    // increment index x by one
    printf("INX\n");
}

void iny()
{
    // increment index y by one
    printf("INY\n");
}

void jmp()
{
    // jump to new location
    printf("JMP\n");
}

void jsr()
{
    // jump to new location saving return address
    printf("JSR\n");
}

void lda()
{
    // load accumulator with memory
    printf("LDA\n");
}

void ldx()
{
    // load index x with memory
    printf("LDX\n");
}

void ldy()
{
    // load index y with memory
    printf("LDY\n");
}

void lsr()
{
    // shift one bit right (memory or accumulator)
    printf("LSR\n");
}

void nop()
{
    // no operation
    printf("NOP\n");
}

void ora()
{
    // or memory with accumulator
    printf("ORA\n");
}

void pha()
{
    // push accumulator on stack
    printf("PHA\n");
}

void php()
{
    // push processor status on stack
    printf("PHP\n");
}

void pla()
{
    // pull accumulator from stack
    printf("PLA\n");
}

void plp()
{
    // pull processor status from stack
    printf("PLP\n");
}

void rol()
{
    // rotate on bit left (memory or accumulator)
    printf("ROL\n");
}

void ror()
{
    // rotate on bit right (memory or accumulator)
    printf("ROR\n");
}

void rti()
{
    // return from interrupt
    printf("RTI\n");
}

void rts()
{
    // retrun from subroutine
    printf("RTS\n");
}

void sbc()
{
    // subtract memory from accumulator with borrow
    printf("SBC\n");
}

void sec()
{
    // set carry flag
    printf("SEC\n");
}

void sed()
{
    // set decimal flag
    printf("SED\n");
}

void sei()
{
    // set interrupt disable status
    printf("SEI\n");
}

void sta()
{
    // store accumulator in memory
    printf("STA\n");
}

void stx()
{
    // store index x in memory
    printf("STX\n");
}

void sty()
{
    // store index y in memory
    printf("STY\n");
}

void tax()
{
    // transfer accumulator to index x
    printf("TAX\n");
}

void tay()
{
    // transfer accumulator to index y
    printf("TAY\n");
}

void tsx()
{
    // transfer stack pointer to index x
    printf("TSX\n");
}

void txa()
{
    // transfer index x to accumulator
    printf("TXA\n");
}

void txs()
{
    // transfer index x to stack pointer
    printf("TXS\n");
}

void tya()
{
    // transfer index y to accumulator
    printf("TYA\n");
}
