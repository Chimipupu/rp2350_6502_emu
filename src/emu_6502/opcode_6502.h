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

#ifndef OPCODE_6502_H
#define OPCODE_6502_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "cpu_6502.h"

typedef enum {
    NOP = 0x01,
    KIL,    // 未定義命令
// #ifdef CPU_WDC_65C02
//     // [WDC W65C02の追加命令 16種類]
//     BBR,
//     BBS,
//     BRA,
//     PHX,
//     PHY,
//     PLX,
//     PLY,
//     RMB,
//     SMB,
//     STP,
//     STZ,
//     TRB,
//     TSB,
//     WAI,
// #endif // CPU_65C02
    ADC,
    AND,
    ASL,
    BCC,
    BCS,
    BEQ,
    BIT,
    BMI,
    BNE,
    BPL,
    BRK,
    BVC,
    BVS,
    CLC,
    CLD,
    CLI,
    CLV,
    CMP,
    CPX,
    CPY,
    DEC,
    DEX,
    DEY,
    EOR,
    INC,
    INX,
    INY,
    JSR,
    LDA,
    LDX,
    LDY,
    LSR,
    ORA,
    PHA,
    PHP,
    PLA,
    PLP,
    ROL,
    ROR,
    RTI,
    RTS,
    SEC,
    SED,
    SEI,
    STA,
    STX,
    STY,
    TAX,
    TAY,
    TSX,
    TXA,
    TXS,
    TYA
} e_6502_instr;

#endif // OPCODE_6502_H