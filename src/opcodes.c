#include <stdio.h>

#include "inc/opcodes.h"

int zz = 0;

void decode_addressing_mode()
{
    switch (opcode_decoded_2)
    {
        case XXX:
            printf("/---]  ");
            break;
        case JSR:
            printf("/abs]  ");
            break;
        case BPL: case BMI: case BVC: case BVS:
        case BCC: case BCS: case BNE: case BEQ:
            printf("/rel]  ");
            break;
        case TXA: case TXS: case TAX: case TSX: case DEX:
        case NOP: case CLC: case SEC: case CLI: case SEI:
        case TYA: case CLV: case CLD: case SED: case PHP:
        case PLP: case PHA: case PLA: case DEY: case TAY:
        case INY: case INX: case BRK: case RTI: case RTS:
            printf("/imp]  ");
            break;
        default:
            switch (addressing_mode)
            {
                case immediate:
                    printf("/imm]  ");
                    break;
                case zero_page:
                    printf("/zpg]  ");
                    break;
                case accumulator:
                    printf("/acc]  ");
                    break;
                case absolute:
                    printf("/abs]  ");
                    break;
                case indirect_y:
                    printf("/iny]  ");
                    break;
                case zero_page_x:
                    printf("/zpx]  ");
                    break;
                case absolute_y:
                    printf("/aby]  ");
                    break;
                case absolute_x:
                    printf("/abx]  ");
                    break;
                case indirect_x:
                    printf("/inx]  ");
                    break;
                case zero_page_y:
                    printf("/zpy]  ");
                    break;
            }
            break;
    }
    
    if (++zz % 8 == 0) { printf("\n"); }
}

void xxx()
{
    // invalid opcode
    printf("%02X:[---", ir);
    decode_addressing_mode();
}

void adc()
{
    // add memory to accumalator with carry
    printf("%02X:[ADC", ir);
    decode_addressing_mode();
}

void and()
{
    // and memory with accumulator
    printf("%02X:[AND", ir);
    decode_addressing_mode();
}

void asl()
{
    // shift left one bit (memory on accumulator)
    printf("%02X:[ASL", ir);
    decode_addressing_mode();
}

void bcc()
{
    // branch on carry clear
    printf("%02X:[BCC", ir);
    decode_addressing_mode();
}

void bcs()
{
    // branch on carry set
    printf("%02X:[BSC", ir);
    decode_addressing_mode();
}

void beq()
{
    // branch on result zero
    printf("%02X:[BEQ", ir);
    decode_addressing_mode();
}

void bit()
{
    // test bits in memory with accumulator
    printf("%02X:[BIT", ir);
    decode_addressing_mode();
}

void bmi()
{
    // branch on result minus
    printf("%02X:[BMI", ir);
    decode_addressing_mode();
}

void bne()
{
    // branch on result not zero
    printf("%02X:[BNE", ir);
    decode_addressing_mode();
}

void bpl()
{
    // branch on result plus
    printf("%02X:[BPL", ir);
    decode_addressing_mode();
}

void brk()
{
    // force break
    printf("%02X:[BRK", ir);
    decode_addressing_mode();
}

void bvc()
{
    // branch on overflow clear
    printf("%02X:[BVC", ir);
    decode_addressing_mode();
}

void bvs()
{
    // branch on overflow set
    printf("%02X:[BVS", ir);
    decode_addressing_mode();
}

void clc()
{
    // clear carry flag
    printf("%02X:[CLC", ir);
    decode_addressing_mode();
}

void cld()
{
    // clear decimal mode
    printf("%02X:[CLD", ir);
    decode_addressing_mode();
}

void cli()
{
    // clear interrupt disable bit
    printf("%02X:[CLI", ir);
    decode_addressing_mode();
}

void clv()
{
    // clear overflow flag
    printf("%02X:[CLV", ir);
    decode_addressing_mode();
}

void cmp()
{
    // compare memory with accumulator
    printf("%02X:[CMP", ir);
    decode_addressing_mode();
}

void cpx()
{
    // compare memory and index x
    printf("%02X:[CPX", ir);
    decode_addressing_mode();
}

void cpy()
{
    // compare memory and index y
    printf("%02X:[CPY", ir);
    decode_addressing_mode();
}

void dec()
{
    // decrement memory by one
    printf("%02X:[DEC", ir);
    decode_addressing_mode();
}

void dex()
{
    // decrement index x by one
    printf("%02X:[DEX", ir);
    decode_addressing_mode();
}

void dey()
{
    // decrement index y by one
    printf("%02X:[DEY", ir);
    decode_addressing_mode();
}

void eor()
{
    // exclusive-or memory with accumulator
    printf("%02X:[EOR", ir);
    decode_addressing_mode();
}

void inc()
{
    // increment memory by one
    printf("%02X:[INC", ir);
    decode_addressing_mode();
}

void inx()
{
    // increment index x by one
    printf("%02X:[INX", ir);
    decode_addressing_mode();
}

void iny()
{
    // increment index y by one
    printf("%02X:[INY", ir);
    decode_addressing_mode();
}

void jmp()
{
    // jump to new location
    printf("%02X:[JMP", ir);
    decode_addressing_mode();
}

void jsr()
{
    // jump to new location saving return address
    printf("%02X:[JSR", ir);
    decode_addressing_mode();
}

void lda()
{
    // load accumulator with memory
    printf("%02X:[LDA", ir);
    decode_addressing_mode();
}

void ldx()
{
    // load index x with memory
    printf("%02X:[LDX", ir);
    decode_addressing_mode();
}

void ldy()
{
    // load index y with memory
    printf("%02X:[LDY", ir);
    decode_addressing_mode();
}

void lsr()
{
    // shift one bit right (memory or accumulator)
    printf("%02X:[LSR", ir);
    decode_addressing_mode();
}

void nop()
{
    // no operation
    printf("%02X:[NOP", ir);
    decode_addressing_mode();
}

void ora()
{
    // or memory with accumulator
    printf("%02X:[ORA", ir);
    decode_addressing_mode();
}

void pha()
{
    // push accumulator on stack
    printf("%02X:[PHA", ir);
    decode_addressing_mode();
}

void php()
{
    // push processor status on stack
    printf("%02X:[PHP", ir);
    decode_addressing_mode();
}

void pla()
{
    // pull accumulator from stack
    printf("%02X:[PLA", ir);
    decode_addressing_mode();
}

void plp()
{
    // pull processor status from stack
    printf("%02X:[PLP", ir);
    decode_addressing_mode();
}

void rol()
{
    // rotate on bit left (memory or accumulator)
    printf("%02X:[ROL", ir);
    decode_addressing_mode();
}

void ror()
{
    // rotate on bit right (memory or accumulator)
    printf("%02X:[ROR", ir);
    decode_addressing_mode();
}

void rti()
{
    // return from interrupt
    printf("%02X:[RTI", ir);
    decode_addressing_mode();
}

void rts()
{
    // retrun from subroutine
    printf("%02X:[RTS", ir);
    decode_addressing_mode();
}

void sbc()
{
    // subtract memory from accumulator with borrow
    printf("%02X:[SBC", ir);
    decode_addressing_mode();
}

void sec()
{
    // set carry flag
    printf("%02X:[SEC", ir);
    decode_addressing_mode();
}

void sed()
{
    // set decimal flag
    printf("%02X:[SED", ir);
    decode_addressing_mode();
}

void sei()
{
    // set interrupt disable status
    printf("%02X:[SEI", ir);
    decode_addressing_mode();
}

void sta()
{
    // store accumulator in memory
    printf("%02X:[STA", ir);
    decode_addressing_mode();
}

void stx()
{
    // store index x in memory
    printf("%02X:[STX", ir);
    decode_addressing_mode();
}

void sty()
{
    // store index y in memory
    printf("%02X:[STY", ir);
    decode_addressing_mode();
}

void tax()
{
    // transfer accumulator to index x
    printf("%02X:[TAX", ir);
    decode_addressing_mode();
}

void tay()
{
    // transfer accumulator to index y
    printf("%02X:[TAY", ir);
    decode_addressing_mode();
}

void tsx()
{
    // transfer stack pointer to index x
    printf("%02X:[TSX", ir);
    decode_addressing_mode();
}

void txa()
{
    // transfer index x to accumulator
    printf("%02X:[TXA", ir);
    decode_addressing_mode();
}

void txs()
{
    // transfer index x to stack pointer
    printf("%02X:[TXS", ir);
    decode_addressing_mode();
}

void tya()
{
    // transfer index y to accumulator
    printf("%02X:[TYA", ir);
    decode_addressing_mode();
}
