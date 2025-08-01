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
#include "ansi_esc.h"

// 6502 NOP命令
void op_nop(cpu_6502_data_t *p_cpu, uint8_t addressing)
{
    printf("[DEBUG] NOP\n");
    __asm __volatile("nop");
}

// 6502 ASL命令
void op_asl(cpu_6502_data_t *p_cpu, uint8_t addressing)
{
    printf("[DEBUG] ASL\n");
}

// 6502 BRK命令
void op_brk(cpu_6502_data_t *p_cpu, uint8_t addressing)
{
    printf("[DEBUG] BRK\n");
    p_cpu->p_reg->psr.bit.b = 1;
}

// 6502 ORA命令
void op_ora(cpu_6502_data_t *p_cpu, uint8_t addressing)
{
    printf("[DEBUG] ORA\n");
}

// 6502 LDA命令
void op_lda(cpu_6502_data_t *p_cpu, uint8_t addressing)
{
    uint8_t val;

    printf("[DEBUG] LDA\n");
    p_cpu->p_reg->pc += 1;
    val = mem_byte_read(p_cpu->p_reg->pc);
    p_cpu->p_reg->a = val;
}

// 6502 PHP命令
void op_php(cpu_6502_data_t *p_cpu, uint8_t addressing)
{
    printf("[DEBUG] PHP\n");
}

// 6502 未定義命令(KIL)
void op_kil(cpu_6502_data_t *p_cpu, uint8_t addressing)
{
    // TODO : (TBD)6502に忠実に従うと未定義命令(KIL) CPUをハングアップ
    printf(  "[ERROR] Undefined OP KIL\n");
}

// 6502 命令セット(OPCode)テーブル
const opcode_6502_t g_6502_opcode_tbl[] = {
    { BRK, S, 7, op_brk },      // 0x00 BRK S
    { ORA, IZX, 6, op_ora },      // 0x01 ORA izx
    { KIL, NONE, 1, op_kil},    // 0x02 未定義命令
    { KIL, NONE, 1, op_kil},    // 0x03 未定義命令
    { KIL, NONE, 1, op_kil},    // 0x04 未定義命令
    { ORA, ZP, 1, op_ora},      // 0x05 ORA zp
    { ASL, ZP, 1, op_asl},      // 0x06 ASL zp
    { KIL, NONE, 1, op_kil},    // 0x07 未定義命令
    { PHP, S, 1, op_php},       // 0x08 PHP Stack S
    { ORA, IMM, 1, op_ora},     // 0x09 ORA #
    { ASL, A, 1, op_asl},       // 0x0A ASL A
    { KIL, NONE, 1, op_kil},    // 0x0B 未定義命令
    { KIL, NONE, 1, op_kil},    // 0x0C 未定義命令
    { ORA, A, 1, op_ora},       // 0x0D ORA A
    { ASL, A, 1, op_asl},       // 0x0E ASL A
    { KIL, NONE, 1, op_kil},    // 0x0F 未定義命令

    { KIL, NONE, 1, op_kil},    // 0x10 
    { KIL, NONE, 1, op_kil},    // 0x11 
    { KIL, NONE, 1, op_kil},    // 0x12 
    { KIL, NONE, 1, op_kil},    // 0x13 
    { KIL, NONE, 1, op_kil},    // 0x14 
    { KIL, NONE, 1, op_kil},    // 0x15 
    { KIL, NONE, 1, op_kil},    // 0x16 
    { KIL, NONE, 1, op_kil},    // 0x17 
    { KIL, NONE, 1, op_kil},    // 0x18 
    { KIL, NONE, 1, op_kil},    // 0x19 
    { KIL, NONE, 1, op_kil},    // 0x1A 
    { KIL, NONE, 1, op_kil},    // 0x1B 
    { KIL, NONE, 1, op_kil},    // 0x1C 
    { KIL, NONE, 1, op_kil},    // 0x1D 
    { KIL, NONE, 1, op_kil},    // 0x1E 
    { KIL, NONE, 1, op_kil},    // 0x1F 

    { KIL, NONE, 1, op_kil},    // 0x20 
    { KIL, NONE, 1, op_kil},    // 0x21 
    { KIL, NONE, 1, op_kil},    // 0x22 
    { KIL, NONE, 1, op_kil},    // 0x23 
    { KIL, NONE, 1, op_kil},    // 0x24 
    { KIL, NONE, 1, op_kil},    // 0x25 
    { KIL, NONE, 1, op_kil},    // 0x26 
    { KIL, NONE, 1, op_kil},    // 0x27 
    { KIL, NONE, 1, op_kil},    // 0x28 
    { KIL, NONE, 1, op_kil},    // 0x29 
    { KIL, NONE, 1, op_kil},    // 0x2A 
    { KIL, NONE, 1, op_kil},    // 0x2B 
    { KIL, NONE, 1, op_kil},    // 0x2C 
    { KIL, NONE, 1, op_kil},    // 0x2D 
    { KIL, NONE, 1, op_kil},    // 0x2E 
    { KIL, NONE, 1, op_kil},    // 0x2F 

    { KIL, NONE, 1, op_kil},    // 0x30 
    { KIL, NONE, 1, op_kil},    // 0x31 
    { KIL, NONE, 1, op_kil},    // 0x32 
    { KIL, NONE, 1, op_kil},    // 0x33 
    { KIL, NONE, 1, op_kil},    // 0x34 
    { KIL, NONE, 1, op_kil},    // 0x35 
    { KIL, NONE, 1, op_kil},    // 0x36 
    { KIL, NONE, 1, op_kil},    // 0x37 
    { KIL, NONE, 1, op_kil},    // 0x38 
    { KIL, NONE, 1, op_kil},    // 0x39 
    { KIL, NONE, 1, op_kil},    // 0x3A 
    { KIL, NONE, 1, op_kil},    // 0x3B 
    { KIL, NONE, 1, op_kil},    // 0x3C 
    { KIL, NONE, 1, op_kil},    // 0x3D 
    { KIL, NONE, 1, op_kil},    // 0x3E 
    { KIL, NONE, 1, op_kil},    // 0x3F 

    { KIL, NONE, 1, op_kil},    // 0x40 
    { KIL, NONE, 1, op_kil},    // 0x41 
    { KIL, NONE, 1, op_kil},    // 0x42 
    { KIL, NONE, 1, op_kil},    // 0x43 
    { KIL, NONE, 1, op_kil},    // 0x44 
    { KIL, NONE, 1, op_kil},    // 0x45 
    { KIL, NONE, 1, op_kil},    // 0x46 
    { KIL, NONE, 1, op_kil},    // 0x47 
    { KIL, NONE, 1, op_kil},    // 0x48 
    { KIL, NONE, 1, op_kil},    // 0x49 
    { KIL, NONE, 1, op_kil},    // 0x4A 
    { KIL, NONE, 1, op_kil},    // 0x4B 
    { KIL, NONE, 1, op_kil},    // 0x4C 
    { KIL, NONE, 1, op_kil},    // 0x4D 
    { KIL, NONE, 1, op_kil},    // 0x4E 
    { KIL, NONE, 1, op_kil},    // 0x4F 

    { KIL, NONE, 1, op_kil},    // 0x50 
    { KIL, NONE, 1, op_kil},    // 0x51 
    { KIL, NONE, 1, op_kil},    // 0x52 
    { KIL, NONE, 1, op_kil},    // 0x53 
    { KIL, NONE, 1, op_kil},    // 0x54 
    { KIL, NONE, 1, op_kil},    // 0x55 
    { KIL, NONE, 1, op_kil},    // 0x56 
    { KIL, NONE, 1, op_kil},    // 0x57 
    { KIL, NONE, 1, op_kil},    // 0x58 
    { KIL, NONE, 1, op_kil},    // 0x59 
    { KIL, NONE, 1, op_kil},    // 0x5A 
    { KIL, NONE, 1, op_kil},    // 0x5B 
    { KIL, NONE, 1, op_kil},    // 0x5C 
    { KIL, NONE, 1, op_kil},    // 0x5D 
    { KIL, NONE, 1, op_kil},    // 0x5E 
    { KIL, NONE, 1, op_kil},    // 0x5F 

    { KIL, NONE, 1, op_kil},    // 0x60 
    { KIL, NONE, 1, op_kil},    // 0x61 
    { KIL, NONE, 1, op_kil},    // 0x62 
    { KIL, NONE, 1, op_kil},    // 0x63 
    { KIL, NONE, 1, op_kil},    // 0x64 
    { KIL, NONE, 1, op_kil},    // 0x65 
    { KIL, NONE, 1, op_kil},    // 0x66 
    { KIL, NONE, 1, op_kil},    // 0x67 
    { KIL, NONE, 1, op_kil},    // 0x68 
    { KIL, NONE, 1, op_kil},    // 0x69 
    { KIL, NONE, 1, op_kil},    // 0x6A 
    { KIL, NONE, 1, op_kil},    // 0x6B 
    { KIL, NONE, 1, op_kil},    // 0x6C 
    { KIL, NONE, 1, op_kil},    // 0x6D 
    { KIL, NONE, 1, op_kil},    // 0x6E 
    { KIL, NONE, 1, op_kil},    // 0x6F 

    { KIL, NONE, 1, op_kil},    // 0x70 
    { KIL, NONE, 1, op_kil},    // 0x71 
    { KIL, NONE, 1, op_kil},    // 0x72 
    { KIL, NONE, 1, op_kil},    // 0x73 
    { KIL, NONE, 1, op_kil},    // 0x74 
    { KIL, NONE, 1, op_kil},    // 0x75 
    { KIL, NONE, 1, op_kil},    // 0x76 
    { KIL, NONE, 1, op_kil},    // 0x77 
    { KIL, NONE, 1, op_kil},    // 0x78 
    { KIL, NONE, 1, op_kil},    // 0x79 
    { KIL, NONE, 1, op_kil},    // 0x7A 
    { KIL, NONE, 1, op_kil},    // 0x7B 
    { KIL, NONE, 1, op_kil},    // 0x7C 
    { KIL, NONE, 1, op_kil},    // 0x7D 
    { KIL, NONE, 1, op_kil},    // 0x7E 
    { KIL, NONE, 1, op_kil},    // 0x7F 

    { KIL, NONE, 1, op_kil},    // 0x80 
    { KIL, NONE, 1, op_kil},    // 0x81 
    { KIL, NONE, 1, op_kil},    // 0x82 
    { KIL, NONE, 1, op_kil},    // 0x83 
    { KIL, NONE, 1, op_kil},    // 0x84 
    { KIL, NONE, 1, op_kil},    // 0x85 
    { KIL, NONE, 1, op_kil},    // 0x86 
    { KIL, NONE, 1, op_kil},    // 0x87 
    { KIL, NONE, 1, op_kil},    // 0x88 
    { KIL, NONE, 1, op_kil},    // 0x89 
    { KIL, NONE, 1, op_kil},    // 0x8A 
    { KIL, NONE, 1, op_kil},    // 0x8B 
    { KIL, NONE, 1, op_kil},    // 0x8C 
    { KIL, NONE, 1, op_kil},    // 0x8D 
    { KIL, NONE, 1, op_kil},    // 0x8E 
    { KIL, NONE, 1, op_kil},    // 0x8F 

    { KIL, NONE, 1, op_kil},    // 0x90 
    { KIL, NONE, 1, op_kil},    // 0x91 
    { KIL, NONE, 1, op_kil},    // 0x92 
    { KIL, NONE, 1, op_kil},    // 0x93 
    { KIL, NONE, 1, op_kil},    // 0x94 
    { KIL, NONE, 1, op_kil},    // 0x95 
    { KIL, NONE, 1, op_kil},    // 0x96 
    { KIL, NONE, 1, op_kil},    // 0x97 
    { KIL, NONE, 1, op_kil},    // 0x98 
    { KIL, NONE, 1, op_kil},    // 0x99 
    { KIL, NONE, 1, op_kil},    // 0x9A 
    { KIL, NONE, 1, op_kil},    // 0x9B 
    { KIL, NONE, 1, op_kil},    // 0x9C 
    { KIL, NONE, 1, op_kil},    // 0x9D 
    { KIL, NONE, 1, op_kil},    // 0x9E 
    { KIL, NONE, 1, op_kil},    // 0x9F 

    { KIL, NONE, 1, op_kil},    // 0xA0 
    { KIL, NONE, 1, op_kil},    // 0xA1 
    { KIL, NONE, 1, op_kil},    // 0xA2 
    { KIL, NONE, 1, op_kil},    // 0xA3 
    { KIL, NONE, 1, op_kil},    // 0xA4 
    { KIL, NONE, 1, op_kil},    // 0xA5 
    { KIL, NONE, 1, op_kil},    // 0xA6 
    { KIL, NONE, 1, op_kil},    // 0xA7 
    { KIL, NONE, 1, op_kil},    // 0xA8 
    { KIL, NONE, 1, op_kil},    // 0xA9 
    { KIL, NONE, 1, op_kil},    // 0xAA 
    { KIL, NONE, 1, op_kil},    // 0xAB 
    { KIL, NONE, 1, op_kil},    // 0xAC 
    { KIL, NONE, 1, op_kil},    // 0xAD 
    { KIL, NONE, 1, op_kil},    // 0xAE 
    { KIL, NONE, 1, op_kil},    // 0xAF 

    { KIL, NONE, 1, op_kil},    // 0xB0 
    { KIL, NONE, 1, op_kil},    // 0xB1 
    { KIL, NONE, 1, op_kil},    // 0xB2 
    { KIL, NONE, 1, op_kil},    // 0xB3 
    { KIL, NONE, 1, op_kil},    // 0xB4 
    { KIL, NONE, 1, op_kil},    // 0xB5 
    { KIL, NONE, 1, op_kil},    // 0xB6 
    { KIL, NONE, 1, op_kil},    // 0xB7 
    { KIL, NONE, 1, op_kil},    // 0xB8 
    { KIL, NONE, 1, op_kil},    // 0xB9 
    { KIL, NONE, 1, op_kil},    // 0xBA 
    { KIL, NONE, 1, op_kil},    // 0xBB 
    { KIL, NONE, 1, op_kil},    // 0xBC 
    { KIL, NONE, 1, op_kil},    // 0xBD 
    { KIL, NONE, 1, op_kil},    // 0xBE 
    { KIL, NONE, 1, op_kil},    // 0xBF 

    { KIL, NONE, 1, op_kil},    // 0xC0 
    { KIL, NONE, 1, op_kil},    // 0xC1 
    { KIL, NONE, 1, op_kil},    // 0xC2 
    { KIL, NONE, 1, op_kil},    // 0xC3 
    { KIL, NONE, 1, op_kil},    // 0xC4 
    { KIL, NONE, 1, op_kil},    // 0xC5 
    { KIL, NONE, 1, op_kil},    // 0xC6 
    { KIL, NONE, 1, op_kil},    // 0xC7 
    { KIL, NONE, 1, op_kil},    // 0xC8 
    { KIL, NONE, 1, op_kil},    // 0xC9 
    { KIL, NONE, 1, op_kil},    // 0xCA 
    { KIL, NONE, 1, op_kil},    // 0xCB 
    { KIL, NONE, 1, op_kil},    // 0xCC 
    { KIL, NONE, 1, op_kil},    // 0xCD 
    { KIL, NONE, 1, op_kil},    // 0xCE 
    { KIL, NONE, 1, op_kil},    // 0xCF 

    { KIL, NONE, 1, op_kil},    // 0xD0 
    { KIL, NONE, 1, op_kil},    // 0xD1 
    { KIL, NONE, 1, op_kil},    // 0xD2 
    { KIL, NONE, 1, op_kil},    // 0xD3 
    { KIL, NONE, 1, op_kil},    // 0xD4 
    { KIL, NONE, 1, op_kil},    // 0xD5 
    { KIL, NONE, 1, op_kil},    // 0xD6 
    { KIL, NONE, 1, op_kil},    // 0xD7 
    { KIL, NONE, 1, op_kil},    // 0xD8 
    { KIL, NONE, 1, op_kil},    // 0xD9 
    { KIL, NONE, 1, op_kil},    // 0xDA 
    { KIL, NONE, 1, op_kil},    // 0xDB 
    { KIL, NONE, 1, op_kil},    // 0xDC 
    { KIL, NONE, 1, op_kil},    // 0xDD 
    { KIL, NONE, 1, op_kil},    // 0xDE 
    { KIL, NONE, 1, op_kil},    // 0xDF 

    { KIL, NONE, 1, op_kil},    // 0xE0 
    { KIL, NONE, 1, op_kil},    // 0xE1 
    { KIL, NONE, 1, op_kil},    // 0xE2 
    { KIL, NONE, 1, op_kil},    // 0xE3 
    { KIL, NONE, 1, op_kil},    // 0xE4 
    { KIL, NONE, 1, op_kil},    // 0xE5 
    { KIL, NONE, 1, op_kil},    // 0xE6 
    { KIL, NONE, 1, op_kil},    // 0xE7 
    { KIL, NONE, 1, op_kil},    // 0xE8 
    { KIL, NONE, 1, op_kil},    // 0xE9 
    { KIL, NONE, 1, op_kil},    // 0xEA 
    { KIL, NONE, 1, op_kil},    // 0xEB 
    { KIL, NONE, 1, op_kil},    // 0xEC 
    { KIL, NONE, 1, op_kil},    // 0xED 
    { KIL, NONE, 1, op_kil},    // 0xEE 
    { KIL, NONE, 1, op_kil},    // 0xEF 

    { KIL, NONE, 1, op_kil},    // 0xF0 
    { KIL, NONE, 1, op_kil},    // 0xF1 
    { KIL, NONE, 1, op_kil},    // 0xF2 
    { KIL, NONE, 1, op_kil},    // 0xF3 
    { KIL, NONE, 1, op_kil},    // 0xF4 
    { KIL, NONE, 1, op_kil},    // 0xF5 
    { KIL, NONE, 1, op_kil},    // 0xF6 
    { KIL, NONE, 1, op_kil},    // 0xF7 
    { KIL, NONE, 1, op_kil},    // 0xF8 
    { KIL, NONE, 1, op_kil},    // 0xF9 
    { KIL, NONE, 1, op_kil},    // 0xFA 
    { KIL, NONE, 1, op_kil},    // 0xFB 
    { KIL, NONE, 1, op_kil},    // 0xFC 
    { KIL, NONE, 1, op_kil},    // 0xFD 
    { KIL, NONE, 1, op_kil},    // 0xFE 
    { KIL, NONE, 1, op_kil},    // 0xFF 
};