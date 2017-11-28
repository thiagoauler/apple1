#include "inc/opcodes.h"
#include "inc/memory.h"

dw pc; // program counter
db ac; // accumulator
db x;  // x register
db y;  // y register
db sp; // stack pointer
db sr; // status register
db ir; // instruction register

am address_mode;

dw address;
db operand;

void fetch_operand()
{
    switch (address_mode)
    {
        case immediate:
            address = pc;
            operand = read_byte(address);
            pc = pc + 1;
            break;
        case zero_page:
            address = read_byte(pc);
            operand = read_byte(address);
            pc = pc + 1;
            break;
        case zero_page_x:
            address = read_byte(pc);
            address = address + x;
            operand = read_byte(address);
            pc = pc + 1;
            break;
        case zero_page_y:
            address = read_byte(pc);
            address = address + y;
            operand = read_byte(address);
            pc = pc + 1;
            break;
        case accumulator:
            address = pc;
            operand = ac;
            break;
        case absolute:
            address = read_word(pc);
            operand = read_byte(address);
            pc = pc + 2;
            break;
        case absolute_x:
            address = read_word(pc);
            address = address + x;
            operand = read_byte(address);
            pc = pc + 2;
            break;
        case absolute_y:
            address = read_word(pc);
            address = address + y;
            operand = read_byte(address);
            pc = pc + 2;
            break;
        case indirect_x:
            address = read_byte(pc);
            address = address + x;
            address = read_word(address);
            operand = read_byte(address);
            pc = pc + 1;
            break;
        case indirect_y:
            address = read_byte(pc);
            address = read_word(address);
            address = address + y;
            operand = read_byte(address);
            pc = pc + 1;
            break;
        case relative:
            operand = read_byte(pc);
            pc = pc + 1;
            if ((operand >> 7) == 0)
            {
                address = pc + operand;
            }
            else
            {
                // negate b operand using 2's complement
                operand = operand ^ 0xFF;
                operand = operand + 1;
                address = pc - operand;
            }
            break;
    }
}

void adjustNZ(db r)
{
    if (r == 0) { Z_SET; } else { Z_UNSET; }
    r = r >> 7;
    if (r == 1) { N_SET; } else { N_UNSET; } 
}

db adder(db a, db b)
{
    db r =  a + b + C_IS_SET;
    db c = (a + b + C_IS_SET) >> 8;
    
    a = a & 0x7F;
    b = b & 0x7F;
    db z = (a + b + C_IS_SET) >> 7;
    db v =  c ^ z;
    
    if (c == 1) { C_SET; } else { C_UNSET; }
    if (v == 1) { V_SET; } else { V_UNSET; } 
        
    adjustNZ(r);
    
    return r;
}

void push_byte(db data)
{
    write_mem(0x0100 + sp, data);
    sp = sp - 1;
}

void push_word(dw data)
{
    db low  = data &  0xFF;
    db high = data >> 8;
    
    push_byte(low);
    push_byte(high);
}

db pull_byte()
{
    sp = sp + 1;
    return read_byte(0x0100 + sp);
}

dw pull_word()
{
    db high = pull_byte();
    db low  = pull_byte();
    dw data = high << 8 | low;
    
    return data;
}

void adc()
{
    // add memory to accumulator with carry
    fetch_operand();
    ac = adder(ac, operand);
}

void and()
{
    // and memory with accumulator
    fetch_operand();
    ac = ac & operand;
    adjustNZ(ac);
}

void asl()
{
    // shift left one bit (memory or accumulator)
    fetch_operand();
    
    if (operand >> 7) { C_SET; } else { C_UNSET; }
    operand = operand << 1;
    
    if (address_mode == accumulator)
    {
        ac = operand;
    }
    else
    {
        write_mem(address, operand);
    }
    
    adjustNZ(operand);
}

void bcc()
{
    // branch on carry clear
    fetch_operand();
    if(!C_IS_SET)
    {
        pc = address;
	}
}

void bcs()
{
    // branch on carry set
    fetch_operand();
    if(C_IS_SET)
    {
        pc = address;
    }
}

void beq()
{
    // branch on result zero
    fetch_operand();
    if(Z_IS_SET)
    {
        pc = address;
    }
}

void bit()
{
    // test bits in memory with accumulator
    fetch_operand();
    if (operand & 0b10000000) { N_SET; } else { N_UNSET; }
    if (operand & 0b01000000) { V_SET; } else { V_UNSET; }
    if (operand & ac)         { Z_SET; } else { Z_UNSET; }
}

void bmi()
{
    // branch on result minus
    fetch_operand();
    if(N_IS_SET)
    {
        pc = address;
    }
}

void bne()
{
    // branch on result not zero
    fetch_operand();
    if(!Z_IS_SET)
    {
        pc = address;
    }
}

void bpl()
{
    // branch on result plus
    fetch_operand();
    if(!N_IS_SET)
    {
        pc = address;
    }
}

void brk()
{
    // force break
    I_SET;
    push_word(pc);
    push_byte(sr);
}

void bvc()
{
    // branch on overflow clear
    fetch_operand();
    if(!V_IS_SET)
    {
        pc = address;
    }
}

void bvs()
{
    // branch on overflow set
    fetch_operand();
    if(V_IS_SET)
    {
        pc = address;
    }
}

void clc()
{
    // clear carry flag
    C_UNSET;
}

void cld()
{
    // clear decimal mode
    D_UNSET;
}

void cli()
{
    // clear interrupt disable bit
    I_UNSET;
}

void clv()
{
    // clear overflow flag
    V_UNSET;
}

void cmp()
{
    // compare memory with accumulator
    C_SET;
    fetch_operand();
    operand = operand ^ 0xFF;
    adder(ac, operand);
}

void cpx()
{
    // compare memory and index x
    C_SET;
    fetch_operand();
    operand = operand ^ 0xFF;
    adder(x, operand);
}

void cpy()
{
    // compare memory and index y
    C_SET;
    fetch_operand();
    operand = operand ^ 0xFF;
    adder(y, operand);
}

void dec()
{
    // decrement memory by one
    fetch_operand();
    operand = operand - 1;
    write_mem(address, operand);
    adjustNZ(operand);
}

void dex()
{
    // decrement index x by one
    x = x - 1;
    adjustNZ(x);
}

void dey()
{
    // decrement index y by one
    y = y - 1;
    adjustNZ(y);
}

void eor()
{
    // exclusive-or memory with accumulator
    fetch_operand();
    ac = ac ^ operand;
    adjustNZ(ac);
}

void inc()
{
    // increment memory by one
    fetch_operand();
    operand = operand + 1;
    write_mem(address, operand);
    adjustNZ(operand);
}

void inx()
{
    // increment index x by one
    x = x + 1;
    adjustNZ(x);
}

void iny()
{
    // increment index y by one
    y = y + 1;
    adjustNZ(y);
}

void jmp()
{
    // jump to new location (indirect)
    address = read_word(pc);
    address = read_word(address);
    pc = address;
}

void jpa()
{
    // jump to new location (absolute)
    address = read_word(pc);
    pc = address;
}

void jsr()
{
    // jump to new location saving return address
    address = read_word(pc);
    pc = pc + 2;
    
    push_word(pc);
    pc = address;
}

void lda()
{
    // load accumulator with memory
    fetch_operand();
    ac = operand;
    adjustNZ(ac);
}

void ldx()
{
    // load index x with memory
    fetch_operand();
    x = operand;
    adjustNZ(x);
}

void ldy()
{
    // load index y with memory
    fetch_operand();
    y = operand;
    adjustNZ(y);
}

void lsr()
{
    // shift one bit right (memory or accumulator)
    fetch_operand();
    
    if (operand & 1) { C_SET; } else { C_UNSET; }
    operand = operand >> 1;
    
    if (address_mode == accumulator)
    {
        ac = operand;
    }
    else
    {
        write_mem(address, operand);
    }
    
    adjustNZ(operand);
}

void nop()
{
    // no operation
}

void ora()
{
    // or memory with accumulator
    fetch_operand();
    ac = ac | operand;
    adjustNZ(ac);
}

void pha()
{
    // push accumulator on stack
    push_byte(ac);
}

void php()
{
    // push processor status on stack
    push_byte(sr);
}

void pla()
{
    // pull accumulator from stack
    ac = pull_byte();
}

void plp()
{
    // pull processor status from stack
    sr = pull_byte();
}

void rol()
{
    // rotate on bit left (memory or accumulator)
    db carry = C_IS_SET;
    
    fetch_operand();
    
    if (operand >> 7) { C_SET; } else { C_UNSET; }
    operand = operand << 1;
    operand = operand | carry;
    
    if (address_mode == accumulator)
    {
        ac = operand;
    }
    else
    {
        write_mem(address, operand);
    }
    
    adjustNZ(operand);
}

void ror()
{
    // rotate on bit right (memory or accumulator)
    db carry = C_IS_SET << 7;
    
    fetch_operand();
    
    if (operand & 1) { C_SET; } else { C_UNSET; }
    operand = operand >> 1;
    operand = operand | carry;
    
    if (address_mode == accumulator)
    {
        ac = operand;
    }
    else
    {
        write_mem(address, operand);
    }
    
    adjustNZ(operand);
}

void rti()
{
    // return from interrupt
    sr = pull_byte();
    pc = pull_word();
}

void rts()
{
    // retrun from subroutine
    pc = pull_word();
}

void sbc()
{
    // subtract memory from accumulator with borrow
    fetch_operand();
    operand = operand ^ 0xFF;
    ac = adder(ac, operand);
}

void sec()
{
    // set carry flag
    C_SET;
}

void sed()
{
    // set decimal flag
    D_SET;
}

void sei()
{
    // set interrupt disable status
    I_SET;
}

void sta()
{
    // store accumulator in memory
    fetch_operand();
    write_mem(address, ac);
}

void stx()
{
    // store index x in memory
    fetch_operand();
    write_mem(address, x);
}

void sty()
{
    // store index y in memory
    fetch_operand();
    write_mem(address, y);
}

void tax()
{
    // transfer accumulator to index x
    x = ac;
    adjustNZ(x);
}

void tay()
{
    // transfer accumulator to index y
    y = ac;
    adjustNZ(y);
}

void tsx()
{
    // transfer stack pointer to index x
    x = sp;
    adjustNZ(x);
}

void txa()
{
    // transfer index x to accumulator
    ac = x;
    adjustNZ(x);
}

void txs()
{
    // transfer index x to stack pointer
    sp = x;
    adjustNZ(x);
}

void tya()
{
    // transfer index y to accumulator
    ac = y;
    adjustNZ(y);
}
