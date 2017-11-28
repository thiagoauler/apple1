#include "inc/types.h"
#include "inc/memory.h"
#include "inc/opcodes.h"
#include "inc/interface.h"

ocl opcode_in_list;
oct opcode_in_table;

void init()
{
    io_init();
    
    // pc is set using 0xFFFC
    pc = read_word(0xFFFC);
    sp = 0xFF;
    sr = 0x20;
    ac = 0x00;
    x  = 0x00;
    y  = 0x00;
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
    db bbbcc = (bbb << 2) | cc;
    
    opcode_in_list  = ir;
    opcode_in_table = aaacc;
    
    address_mode = bbb;
    
    if (cc == 0b01)
    {
        // correct the addressing mode for '01' opcode type
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
    
    if (bbbcc == 0b10000)
    {
        // adjust the addressing mode for branch intructions
        address_mode = relative;
    }
}

void execute()
{
    switch (opcode_in_list)
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
    }
    
    switch (opcode_in_table)
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
        case JPA: return jpa();
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
    }
}

void run()
{
    while (1)
    {
        fetch();
        decode();
        execute();
        
        input();
        output();
    }
    
}
