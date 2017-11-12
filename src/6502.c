#include "inc/types.h"
#include "inc/memory.h"
#include "inc/opcodes.h"

oc1 opcode_decoded_1;
oc2 opcode_decoded_2;

void init()
{
    // pc is set using 0xFFFC-0xFFFD
    mem.mar = 0xFFFD;
    mem_read();
    pc = mem.mdr << 8;
    mem.mar = 0xFFFC;
    mem_read();
    pc = mem.mdr + pc;
}

void fetch()
{
    mem.mar = pc;
    mem_read();
    ir = mem.mdr;
    pc++;
}

void decode()
{
    // instruction pattern is "aaabbbccc" where:
    // aaa cc determines the opcode
    // bbb determines the addressing mode
    
    db aaa = (ir & 0b11100000) >> 5;
    db bbb = (ir & 0b00011100) >> 2;
    db  cc = (ir & 0b00000011);
    
    db aaacc = (aaa << 2) | cc;
    
    opcode_decoded_1 = aaacc;
    opcode_decoded_2 = ir;
}

void execute()
{
    switch(opcode_decoded_2)
    {
        case BRK:
            return brk();
        case BPL:
            return bpl();
        case JSR:
            return jsr();
        case BMI:
            return bmi();
        case RTI:
            return rti();
        case BVC:
            return bvc();
        case RTS:
            return rts();
        case BVS:
            return bvs();
        case BCC:
            return bcc();
        case BCS:
            return bcs();
        case BNE:
            return bne();
        case BEQ:
            return beq();
        case PHP:
            return php();
        case CLC:
            return clc();
        case PLP:
            return plp();
        case SEC:
            return sec();
        case PHA:
            return pha();
        case CLI:
            return cli();
        case PLA:
            return pla();
        case SEI:
            return sei();
        case DEY:
            return dey();
        case TYA:
            return tya();
        case TAY:
            return tay();
        case CLV:
            return clv();
        case INY:
            return iny();
        case CLD:
            return cld();
        case INX:
            return inx();
        case SED:
            return sed();
        case TXA:
            return txa();
        case TXS:
            return txs();
        case TAX:
            return tax();
        case TSX:
            return tsx();
        case DEX:
            return dex();
        case NOP:
            return nop();
    }
    
    switch (opcode_decoded_1)
    {
        case BIT:
            return bit();
        case JMP:
            return jmp();
        case JPA: // JMP (absolute)
            return jmp();
        case STY:
            return sty();
        case LDY:
            return ldy();
        case CPY:
            return cpy();
        case CPX:
            return cpx();
        case ORA:
            return ora();
        case AND:
            return and();
        case EOR:
            return eor();
        case ADC:
            return adc();
        case STA:
            return sta();
        case LDA:
            return lda();
        case CMP:
            return cmp();
        case SBC:
            return sbc();
        case ASL:
            return asl();
        case ROL:
            return rol();
        case LSR:
            return lsr();
        case ROR:
            return ror();
        case STX:
            return stx();
        case LDX:
            return ldx();
        case DEC:
            return dec();
        case INC:
            return inc();
    }
}

void run()
{
    while (pc != 0)
    {
        fetch();
        decode();
        execute();
    }
}
