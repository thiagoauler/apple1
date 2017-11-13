#include "inc/types.h"
#include "inc/memory.h"
#include "inc/opcodes.h"

ocl opcode_decoded_1;
oct opcode_decoded_2;

void init()
{
    // pc is set using 0xFFFC
    pc = read_word(0xFFFC);
}

void fetch()
{
    ir = read_byte(pc);
    pc = pc + 1;
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
    
    opcode_decoded_1 = ir;
    opcode_decoded_2 = aaacc;
    
    
    address_mode = bbb;
    
    if (cc == 0b01)
    {
        // correct the addressing mode for '01' opcodetype
        if (bbb == 0b000)
        {
            address_mode = indirect_x;
        }
        if (bbb == 0b010)
        {
            address_mode = immediate;
        }
    }
    
    if (cc == 0b10)
    {
        // adjust the addressing mode for STX and LDX
        if ((aaacc == STX || aaacc == LDX) && address_mode == zero_page_x)
        {
            address_mode = zero_page_y;
        }
        if (aaacc == LDX && address_mode == absolute_x)
        {
            address_mode = absolute_y;
        }
    }
    
    // disable all incorrect opcodes
    if (((ir & 0x0F) == 0x02 && ir != 0xA2) ||
         (ir & 0x0F) == 0x03 || (ir & 0x0F) == 0x07 ||
         (ir & 0x0F) == 0x0B || (ir & 0x0F) == 0x0F)
    {
        opcode_decoded_1 = XXX;
        opcode_decoded_2 = XXX;
        address_mode  = XXX;
    }
    
    if (ir == 0x04 || ir == 0x0C || ir == 0x14 || ir == 0x1A || ir == 0x1C || ir == 0x34 || ir == 0x3A ||
        ir == 0x3C || ir == 0x44 || ir == 0x54 || ir == 0x5A || ir == 0x5C || ir == 0x64 || ir == 0x74 ||
        ir == 0x7A || ir == 0x7C || ir == 0x80 || ir == 0x89 || ir == 0x9C || ir == 0x9E ||
        ir == 0xD4 || ir == 0xDA || ir == 0xDC || ir == 0xF4 || ir == 0xFA || ir == 0xFC)
    {
        opcode_decoded_1 = XXX;
        opcode_decoded_2 = XXX;
        address_mode  = XXX;
    }
}

void execute()
{
    switch (opcode_decoded_1)
    {
        case BCC: return bcc();
        case BCS: return bcs();
        case BEQ: return beq();
        case BMI: return bmi();
        case BNE: return bne();
        case BPL: return bpl();
        case BRK: return brk();
        case BVC: return bvc();
        case BVS: return bvs();
        case CLC: return clc();
        case CLD: return cld();
        case CLI: return cli();
        case CLV: return clv();
        case DEX: return dex();
        case DEY: return dey();
        case INX: return inx();
        case INY: return iny();
        case JSR: return jsr();
        case NOP: return nop();
        case PHA: return pha();
        case PHP: return php();
        case PLA: return pla();
        case PLP: return plp();
        case RTI: return rti();
        case RTS: return rts();
        case SEC: return sec();
        case SED: return sed();
        case SEI: return sei();
        case TAX: return tax();
        case TAY: return tay();
        case TSX: return tsx();
        case TXA: return txa();
        case TXS: return txs();
        case TYA: return tya();
        case XXX: return xxx();
    }
    
    switch (opcode_decoded_2)
    {
        case ADC: return adc();
        case AND: return and();
        case ASL: return asl();
        case BIT: return bit();
        case CMP: return cmp();
        case CPX: return cpx();
        case CPY: return cpy();
        case DEC: return dec();
        case EOR: return eor();
        case INC: return inc();
        case JMP: return jmp();
        case JPA: return jmp();
        case LDA: return lda();
        case LDX: return ldx();
        case LDY: return ldy();
        case LSR: return lsr();
        case ORA: return ora();
        case ROL: return rol();
        case ROR: return ror();
        case SBC: return sbc();
        case STA: return sta();
        case STX: return stx();
        case STY: return sty();
        case XXX: return xxx();
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
