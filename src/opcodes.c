#include "inc/opcodes.h"
#include "inc/memory.h"

db fetch_operand()
{
    db operand;

    switch (address_mode)
    {
        case immediate:
            operand = read_byte(pc);
            pc = pc + 1;
            break;
        case zero_page:
            operand = read_byte(pc);
            operand = read_byte(operand);
            pc = pc + 1;
            break;
        case zero_page_x:
            operand = read_byte(pc);
            operand = read_byte(operand + x);
            pc = pc + 1;
            break;
        case zero_page_y:
            operand = read_byte(pc);
            operand = read_byte(operand + y);
            pc = pc + 1;
            break;
        case accumulator:
            operand = ac;
            break;
    }
    
    return operand;
}

void xxx()
{
    // invalid opcode
    return nop();
}

void adc()
{
    // add memory to accumalator with carry
}

void and()
{
    // and memory with accumulator
}

void asl()
{
    // shift left one bit (memory on accumulator)
}

void bcc()
{
    // branch on carry clear
}

void bcs()
{
    // branch on carry set
}

void beq()
{
    // branch on result zero
}

void bit()
{
    // test bits in memory with accumulator
}

void bmi()
{
    // branch on result minus
}

void bne()
{
    // branch on result not zero
}

void bpl()
{
    // branch on result plus
}

void brk()
{
    // force break
}

void bvc()
{
    // branch on overflow clear
}

void bvs()
{
    // branch on overflow set
}

void clc()
{
    // clear carry flag
}

void cld()
{
    // clear decimal mode
}

void cli()
{
    // clear interrupt disable bit
}

void clv()
{
    // clear overflow flag
}

void cmp()
{
    // compare memory with accumulator
}

void cpx()
{
    // compare memory and index x
}

void cpy()
{
    // compare memory and index y
}

void dec()
{
    // decrement memory by one
}

void dex()
{
    // decrement index x by one
}

void dey()
{
    // decrement index y by one
}

void eor()
{
    // exclusive-or memory with accumulator
}

void inc()
{
    // increment memory by one
}

void inx()
{
    // increment index x by one
}

void iny()
{
    // increment index y by one
}

void jmp()
{
    // jump to new location
}

void jsr()
{
    // jump to new location saving return address
}

void lda()
{
    // load accumulator with memory
}

void ldx()
{
    // load index x with memory
}

void ldy()
{
    // load index y with memory
}

void lsr()
{
    // shift one bit right (memory or accumulator)
}

void nop()
{
    // no operation
}

void ora()
{
    // or memory with accumulator
}

void pha()
{
    // push accumulator on stack
}

void php()
{
    // push processor status on stack
}

void pla()
{
    // pull accumulator from stack
}

void plp()
{
    // pull processor status from stack
}

void rol()
{
    // rotate on bit left (memory or accumulator)
}

void ror()
{
    // rotate on bit right (memory or accumulator)
}

void rti()
{
    // return from interrupt
}

void rts()
{
    // retrun from subroutine
}

void sbc()
{
    // subtract memory from accumulator with borrow
}

void sec()
{
    // set carry flag
}

void sed()
{
    // set decimal flag
}

void sei()
{
    // set interrupt disable status
}

void sta()
{
    // store accumulator in memory
}

void stx()
{
    // store index x in memory
}

void sty()
{
    // store index y in memory
}

void tax()
{
    // transfer accumulator to index x
}

void tay()
{
    // transfer accumulator to index y
}

void tsx()
{
    // transfer stack pointer to index x
}

void txa()
{
    // transfer index x to accumulator
}

void txs()
{
    // transfer index x to stack pointer
}

void tya()
{
    // transfer index y to accumulator
}
