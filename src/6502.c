#include <stdio.h>

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
    
    addressing_mode = bbb;
    
    if (cc == 0b01)
    {
        // correct the addressing mode for '01' opcodetype
        if (bbb == 0b000)
        {
            addressing_mode = indirect_x;
        }
        if (bbb == 0b010)
        {
            addressing_mode = immediate;
        }
    }
    
    if (cc == 0b10)
    {
        // adjust the addressing mode for STX and LDX
        if ((opcode_decoded_1 == STX || opcode_decoded_1 == LDX) && addressing_mode == zero_page_x)
        {
            addressing_mode = zero_page_y;
        }
        if (opcode_decoded_1 == LDX && addressing_mode == absolute_x)
        {
            addressing_mode = absolute_y;
        }
    }
    
    // disable all incorrect opcodes
    if (((ir & 0x0F) == 0x02 && ir != 0xA2) ||
         (ir & 0x0F) == 0x03 || (ir & 0x0F) == 0x07 ||
         (ir & 0x0F) == 0x0B || (ir & 0x0F) == 0x0F)
    {
        opcode_decoded_1 = XXX;
        opcode_decoded_2 = XXX;
        addressing_mode  = XXX;
    }
    
    if (ir == 0x04 || ir == 0x0C || ir == 0x14 || ir == 0x1A || ir == 0x1C || ir == 0x34 || ir == 0x3A ||
        ir == 0x3C || ir == 0x44 || ir == 0x54 || ir == 0x5A || ir == 0x5C || ir == 0x64 || ir == 0x74 ||
        ir == 0x7A || ir == 0x7C || ir == 0x80 || ir == 0x89 || ir == 0x9C || ir == 0x9E ||
        ir == 0xD4 || ir == 0xDA || ir == 0xDC || ir == 0xF4 || ir == 0xFA || ir == 0xFC)
    {
        opcode_decoded_1 = XXX;
        opcode_decoded_2 = XXX;
        addressing_mode  = XXX;
    }
}

void execute()
{
    switch (opcode_decoded_2)
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
        case XXX:
            return xxx();
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
        case XXX:
            return xxx();
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
