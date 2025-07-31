/**
 * @file opcode_6502.h
 * @author Chimipupu(https://github.com/Chimipupu)
 * @brief 6502の命令セット
 * @version 0.1
 * @date 2025-07-30
 * 
 * @copyright Copyright (c) 2025 Chimipupu All Rights Reserved.
 * 
 */

#include "opcode_6502.h"

void op_nop(cpu_6502_data_t *p_cpu)
{
    printf("[DEBUG] NOP\n");
    __asm __volatile("nop");
}

void op_brk(cpu_6502_data_t *p_cpu)
{
    printf("[DEBUG] BRK\n");
    p_cpu->p_reg->psr.bit.b = 1;
}

void op_ora_izx(cpu_6502_data_t *p_cpu)
{
    printf("[DEBUG] ORA izx\n");
}

void op_lda_imm(cpu_6502_data_t *p_cpu)
{
    uint8_t val;

    printf("[DEBUG] LDA imm\n");
    p_cpu->p_reg->pc += 1;
    val = mem_byte_read(p_cpu->p_reg->pc);
    p_cpu->p_reg->a = val;
}

void op_undef_kil(cpu_6502_data_t *p_cpu)
{
    // 未定義命令(KIL) 6502に忠実に従うとCPUをハングアップ
    printf("\x1b[31m[ERROR] Undefined OP\n");
}

const opcode_6502_t g_6502_opcode_tbl[] = {
    { BRK, 1, 7, op_brk },         // 0x00 BRK
    { ORA, 1, 6, op_ora_izx },     // 0x01 ORA izx
    { NOP, IMM, 1, op_nop},    // 0x02 
    { NOP, IMM, 1, op_nop},    // 0x03 
    { NOP, IMM, 1, op_nop},    // 0x04 
    { NOP, IMM, 1, op_nop},    // 0x05 
    { NOP, IMM, 1, op_nop},    // 0x06 
    { NOP, IMM, 1, op_nop},    // 0x07 
    { NOP, IMM, 1, op_nop},    // 0x08 
    { NOP, IMM, 1, op_nop},    // 0x09 
    { NOP, IMM, 1, op_nop},    // 0x0A 
    { NOP, IMM, 1, op_nop},    // 0x0B 
    { NOP, IMM, 1, op_nop},    // 0x0C 
    { NOP, IMM, 1, op_nop},    // 0x0D 
    { NOP, IMM, 1, op_nop},    // 0x0E 
    { NOP, IMM, 1, op_nop},    // 0x0F 

    { NOP, IMM, 1, op_nop},    // 0x10 
    { NOP, IMM, 1, op_nop},    // 0x11 
    { NOP, IMM, 1, op_nop},    // 0x12 
    { NOP, IMM, 1, op_nop},    // 0x13 
    { NOP, IMM, 1, op_nop},    // 0x14 
    { NOP, IMM, 1, op_nop},    // 0x15 
    { NOP, IMM, 1, op_nop},    // 0x16 
    { NOP, IMM, 1, op_nop},    // 0x17 
    { NOP, IMM, 1, op_nop},    // 0x18 
    { NOP, IMM, 1, op_nop},    // 0x19 
    { NOP, IMM, 1, op_nop},    // 0x1A 
    { NOP, IMM, 1, op_nop},    // 0x1B 
    { NOP, IMM, 1, op_nop},    // 0x1C 
    { NOP, IMM, 1, op_nop},    // 0x1D 
    { NOP, IMM, 1, op_nop},    // 0x1E 
    { NOP, IMM, 1, op_nop},    // 0x1F 

    { NOP, IMM, 1, op_nop},    // 0x20 
    { NOP, IMM, 1, op_nop},    // 0x21 
    { NOP, IMM, 1, op_nop},    // 0x22 
    { NOP, IMM, 1, op_nop},    // 0x23 
    { NOP, IMM, 1, op_nop},    // 0x24 
    { NOP, IMM, 1, op_nop},    // 0x25 
    { NOP, IMM, 1, op_nop},    // 0x26 
    { NOP, IMM, 1, op_nop},    // 0x27 
    { NOP, IMM, 1, op_nop},    // 0x28 
    { NOP, IMM, 1, op_nop},    // 0x29 
    { NOP, IMM, 1, op_nop},    // 0x2A 
    { NOP, IMM, 1, op_nop},    // 0x2B 
    { NOP, IMM, 1, op_nop},    // 0x2C 
    { NOP, IMM, 1, op_nop},    // 0x2D 
    { NOP, IMM, 1, op_nop},    // 0x2E 
    { NOP, IMM, 1, op_nop},    // 0x2F 

    { NOP, IMM, 1, op_nop},    // 0x30 
    { NOP, IMM, 1, op_nop},    // 0x31 
    { NOP, IMM, 1, op_nop},    // 0x32 
    { NOP, IMM, 1, op_nop},    // 0x33 
    { NOP, IMM, 1, op_nop},    // 0x34 
    { NOP, IMM, 1, op_nop},    // 0x35 
    { NOP, IMM, 1, op_nop},    // 0x36 
    { NOP, IMM, 1, op_nop},    // 0x37 
    { NOP, IMM, 1, op_nop},    // 0x38 
    { NOP, IMM, 1, op_nop},    // 0x39 
    { NOP, IMM, 1, op_nop},    // 0x3A 
    { NOP, IMM, 1, op_nop},    // 0x3B 
    { NOP, IMM, 1, op_nop},    // 0x3C 
    { NOP, IMM, 1, op_nop},    // 0x3D 
    { NOP, IMM, 1, op_nop},    // 0x3E 
    { NOP, IMM, 1, op_nop},    // 0x3F 

    { NOP, IMM, 1, op_nop},    // 0x40 
    { NOP, IMM, 1, op_nop},    // 0x41 
    { NOP, IMM, 1, op_nop},    // 0x42 
    { NOP, IMM, 1, op_nop},    // 0x43 
    { NOP, IMM, 1, op_nop},    // 0x44 
    { NOP, IMM, 1, op_nop},    // 0x45 
    { NOP, IMM, 1, op_nop},    // 0x46 
    { NOP, IMM, 1, op_nop},    // 0x47 
    { NOP, IMM, 1, op_nop},    // 0x48 
    { NOP, IMM, 1, op_nop},    // 0x49 
    { NOP, IMM, 1, op_nop},    // 0x4A 
    { NOP, IMM, 1, op_nop},    // 0x4B 
    { NOP, IMM, 1, op_nop},    // 0x4C 
    { NOP, IMM, 1, op_nop},    // 0x4D 
    { NOP, IMM, 1, op_nop},    // 0x4E 
    { NOP, IMM, 1, op_nop},    // 0x4F 

    { NOP, IMM, 1, op_nop},    // 0x50 
    { NOP, IMM, 1, op_nop},    // 0x51 
    { NOP, IMM, 1, op_nop},    // 0x52 
    { NOP, IMM, 1, op_nop},    // 0x53 
    { NOP, IMM, 1, op_nop},    // 0x54 
    { NOP, IMM, 1, op_nop},    // 0x55 
    { NOP, IMM, 1, op_nop},    // 0x56 
    { NOP, IMM, 1, op_nop},    // 0x57 
    { NOP, IMM, 1, op_nop},    // 0x58 
    { NOP, IMM, 1, op_nop},    // 0x59 
    { NOP, IMM, 1, op_nop},    // 0x5A 
    { NOP, IMM, 1, op_nop},    // 0x5B 
    { NOP, IMM, 1, op_nop},    // 0x5C 
    { NOP, IMM, 1, op_nop},    // 0x5D 
    { NOP, IMM, 1, op_nop},    // 0x5E 
    { NOP, IMM, 1, op_nop},    // 0x5F 

    { NOP, IMM, 1, op_nop},    // 0x60 
    { NOP, IMM, 1, op_nop},    // 0x61 
    { NOP, IMM, 1, op_nop},    // 0x62 
    { NOP, IMM, 1, op_nop},    // 0x63 
    { NOP, IMM, 1, op_nop},    // 0x64 
    { NOP, IMM, 1, op_nop},    // 0x65 
    { NOP, IMM, 1, op_nop},    // 0x66 
    { NOP, IMM, 1, op_nop},    // 0x67 
    { NOP, IMM, 1, op_nop},    // 0x68 
    { NOP, IMM, 1, op_nop},    // 0x69 
    { NOP, IMM, 1, op_nop},    // 0x6A 
    { NOP, IMM, 1, op_nop},    // 0x6B 
    { NOP, IMM, 1, op_nop},    // 0x6C 
    { NOP, IMM, 1, op_nop},    // 0x6D 
    { NOP, IMM, 1, op_nop},    // 0x6E 
    { NOP, IMM, 1, op_nop},    // 0x6F 

    { NOP, IMM, 1, op_nop},    // 0x70 
    { NOP, IMM, 1, op_nop},    // 0x71 
    { NOP, IMM, 1, op_nop},    // 0x72 
    { NOP, IMM, 1, op_nop},    // 0x73 
    { NOP, IMM, 1, op_nop},    // 0x74 
    { NOP, IMM, 1, op_nop},    // 0x75 
    { NOP, IMM, 1, op_nop},    // 0x76 
    { NOP, IMM, 1, op_nop},    // 0x77 
    { NOP, IMM, 1, op_nop},    // 0x78 
    { NOP, IMM, 1, op_nop},    // 0x79 
    { NOP, IMM, 1, op_nop},    // 0x7A 
    { NOP, IMM, 1, op_nop},    // 0x7B 
    { NOP, IMM, 1, op_nop},    // 0x7C 
    { NOP, IMM, 1, op_nop},    // 0x7D 
    { NOP, IMM, 1, op_nop},    // 0x7E 
    { NOP, IMM, 1, op_nop},    // 0x7F 

    { NOP, IMM, 1, op_nop},    // 0x80 
    { NOP, IMM, 1, op_nop},    // 0x81 
    { NOP, IMM, 1, op_nop},    // 0x82 
    { NOP, IMM, 1, op_nop},    // 0x83 
    { NOP, IMM, 1, op_nop},    // 0x84 
    { NOP, IMM, 1, op_nop},    // 0x85 
    { NOP, IMM, 1, op_nop},    // 0x86 
    { NOP, IMM, 1, op_nop},    // 0x87 
    { NOP, IMM, 1, op_nop},    // 0x88 
    { NOP, IMM, 1, op_nop},    // 0x89 
    { NOP, IMM, 1, op_nop},    // 0x8A 
    { NOP, IMM, 1, op_nop},    // 0x8B 
    { NOP, IMM, 1, op_nop},    // 0x8C 
    { NOP, IMM, 1, op_nop},    // 0x8D 
    { NOP, IMM, 1, op_nop},    // 0x8E 
    { NOP, IMM, 1, op_nop},    // 0x8F 

    { NOP, IMM, 1, op_nop},    // 0x90 
    { NOP, IMM, 1, op_nop},    // 0x91 
    { NOP, IMM, 1, op_nop},    // 0x92 
    { NOP, IMM, 1, op_nop},    // 0x93 
    { NOP, IMM, 1, op_nop},    // 0x94 
    { NOP, IMM, 1, op_nop},    // 0x95 
    { NOP, IMM, 1, op_nop},    // 0x96 
    { NOP, IMM, 1, op_nop},    // 0x97 
    { NOP, IMM, 1, op_nop},    // 0x98 
    { NOP, IMM, 1, op_nop},    // 0x99 
    { NOP, IMM, 1, op_nop},    // 0x9A 
    { NOP, IMM, 1, op_nop},    // 0x9B 
    { NOP, IMM, 1, op_nop},    // 0x9C 
    { NOP, IMM, 1, op_nop},    // 0x9D 
    { NOP, IMM, 1, op_nop},    // 0x9E 
    { NOP, IMM, 1, op_nop},    // 0x9F 

    { NOP, IMM, 1, op_nop},    // 0xA0 
    { NOP, IMM, 1, op_nop},    // 0xA1 
    { NOP, IMM, 1, op_nop},    // 0xA2 
    { NOP, IMM, 1, op_nop},    // 0xA3 
    { NOP, IMM, 1, op_nop},    // 0xA4 
    { NOP, IMM, 1, op_nop},    // 0xA5 
    { NOP, IMM, 1, op_nop},    // 0xA6 
    { NOP, IMM, 1, op_nop},    // 0xA7 
    { NOP, IMM, 1, op_nop},    // 0xA8 
    { NOP, IMM, 1, op_nop},    // 0xA9 
    { NOP, IMM, 1, op_nop},    // 0xAA 
    { NOP, IMM, 1, op_nop},    // 0xAB 
    { NOP, IMM, 1, op_nop},    // 0xAC 
    { NOP, IMM, 1, op_nop},    // 0xAD 
    { NOP, IMM, 1, op_nop},    // 0xAE 
    { NOP, IMM, 1, op_nop},    // 0xAF 

    { NOP, IMM, 1, op_nop},    // 0xB0 
    { NOP, IMM, 1, op_nop},    // 0xB1 
    { NOP, IMM, 1, op_nop},    // 0xB2 
    { NOP, IMM, 1, op_nop},    // 0xB3 
    { NOP, IMM, 1, op_nop},    // 0xB4 
    { NOP, IMM, 1, op_nop},    // 0xB5 
    { NOP, IMM, 1, op_nop},    // 0xB6 
    { NOP, IMM, 1, op_nop},    // 0xB7 
    { NOP, IMM, 1, op_nop},    // 0xB8 
    { NOP, IMM, 1, op_nop},    // 0xB9 
    { NOP, IMM, 1, op_nop},    // 0xBA 
    { NOP, IMM, 1, op_nop},    // 0xBB 
    { NOP, IMM, 1, op_nop},    // 0xBC 
    { NOP, IMM, 1, op_nop},    // 0xBD 
    { NOP, IMM, 1, op_nop},    // 0xBE 
    { NOP, IMM, 1, op_nop},    // 0xBF 

    { NOP, IMM, 1, op_nop},    // 0xC0 
    { NOP, IMM, 1, op_nop},    // 0xC1 
    { NOP, IMM, 1, op_nop},    // 0xC2 
    { NOP, IMM, 1, op_nop},    // 0xC3 
    { NOP, IMM, 1, op_nop},    // 0xC4 
    { NOP, IMM, 1, op_nop},    // 0xC5 
    { NOP, IMM, 1, op_nop},    // 0xC6 
    { NOP, IMM, 1, op_nop},    // 0xC7 
    { NOP, IMM, 1, op_nop},    // 0xC8 
    { NOP, IMM, 1, op_nop},    // 0xC9 
    { NOP, IMM, 1, op_nop},    // 0xCA 
    { NOP, IMM, 1, op_nop},    // 0xCB 
    { NOP, IMM, 1, op_nop},    // 0xCC 
    { NOP, IMM, 1, op_nop},    // 0xCD 
    { NOP, IMM, 1, op_nop},    // 0xCE 
    { NOP, IMM, 1, op_nop},    // 0xCF 

    { NOP, IMM, 1, op_nop},    // 0xD0 
    { NOP, IMM, 1, op_nop},    // 0xD1 
    { NOP, IMM, 1, op_nop},    // 0xD2 
    { NOP, IMM, 1, op_nop},    // 0xD3 
    { NOP, IMM, 1, op_nop},    // 0xD4 
    { NOP, IMM, 1, op_nop},    // 0xD5 
    { NOP, IMM, 1, op_nop},    // 0xD6 
    { NOP, IMM, 1, op_nop},    // 0xD7 
    { NOP, IMM, 1, op_nop},    // 0xD8 
    { NOP, IMM, 1, op_nop},    // 0xD9 
    { NOP, IMM, 1, op_nop},    // 0xDA 
    { NOP, IMM, 1, op_nop},    // 0xDB 
    { NOP, IMM, 1, op_nop},    // 0xDC 
    { NOP, IMM, 1, op_nop},    // 0xDD 
    { NOP, IMM, 1, op_nop},    // 0xDE 
    { NOP, IMM, 1, op_nop},    // 0xDF 

    { NOP, IMM, 1, op_nop},    // 0xE0 
    { NOP, IMM, 1, op_nop},    // 0xE1 
    { NOP, IMM, 1, op_nop},    // 0xE2 
    { NOP, IMM, 1, op_nop},    // 0xE3 
    { NOP, IMM, 1, op_nop},    // 0xE4 
    { NOP, IMM, 1, op_nop},    // 0xE5 
    { NOP, IMM, 1, op_nop},    // 0xE6 
    { NOP, IMM, 1, op_nop},    // 0xE7 
    { NOP, IMM, 1, op_nop},    // 0xE8 
    { NOP, IMM, 1, op_nop},    // 0xE9 
    { NOP, IMM, 1, op_nop},    // 0xEA 
    { NOP, IMM, 1, op_nop},    // 0xEB 
    { NOP, IMM, 1, op_nop},    // 0xEC 
    { NOP, IMM, 1, op_nop},    // 0xED 
    { NOP, IMM, 1, op_nop},    // 0xEE 
    { NOP, IMM, 1, op_nop},    // 0xEF 

    { NOP, IMM, 1, op_nop},    // 0xF0 
    { NOP, IMM, 1, op_nop},    // 0xF1 
    { NOP, IMM, 1, op_nop},    // 0xF2 
    { NOP, IMM, 1, op_nop},    // 0xF3 
    { NOP, IMM, 1, op_nop},    // 0xF4 
    { NOP, IMM, 1, op_nop},    // 0xF5 
    { NOP, IMM, 1, op_nop},    // 0xF6 
    { NOP, IMM, 1, op_nop},    // 0xF7 
    { NOP, IMM, 1, op_nop},    // 0xF8 
    { NOP, IMM, 1, op_nop},    // 0xF9 
    { NOP, IMM, 1, op_nop},    // 0xFA 
    { NOP, IMM, 1, op_nop},    // 0xFB 
    { NOP, IMM, 1, op_nop},    // 0xFC 
    { NOP, IMM, 1, op_nop},    // 0xFD 
    { NOP, IMM, 1, op_nop},    // 0xFE 
    { NOP, IMM, 1, op_nop},    // 0xFF 
};