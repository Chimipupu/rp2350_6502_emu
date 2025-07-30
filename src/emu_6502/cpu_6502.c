/**
 * @file cpu_6502.c
 * @author Chimipupu(https://github.com/Chimipupu)
 * @brief 6502のCPU関連
 * @version 0.1
 * @date 2025-07-30
 * 
 * @copyright Copyright (c) 2025 Chimipupu All Rights Reserved.
 * 
 */

#include "cpu_6502.h"

cpu_6502_reg_t s_cpu_6502_reg;
static cpu_6502_t s_cpu_6502;
static uint8_t s_rom[CPU_6502_ROM_SIZE];
static uint8_t s_ram[CPU_6502_RAM_SIZE];

/**
 * @brief 6502のCPUリセット
 * 
 */
void cpu_6502_reset(void)
{
    // レジスタ初期化
    s_cpu_6502.p_reg = &s_cpu_6502_reg;
    s_cpu_6502.p_reg->acc = 0x00;
    s_cpu_6502.p_reg->x = 0x00;
    s_cpu_6502.p_reg->y = 0x00;
    s_cpu_6502.p_reg->sp = 0xFD;
    s_cpu_6502.p_reg->pc = 0x0000;

    // ROM/RAM初期化
    memset(&s_rom[0], 0x00, CPU_6502_ROM_SIZE);
    memset(&s_ram[0], 0x00, CPU_6502_RAM_SIZE);
    s_cpu_6502.p_rom = &s_rom[0];
    s_cpu_6502.p_ram = &s_ram[0];
}

/**
 * @brief 6502の命令フェッチ
 * 
 */
void cpu_6502_fetch(void)
{
    // TODO:
}

/**
 * @brief 6502の命令デコード
 * 
 */
void cpu_6502_decode(void)
{
    // TODO:
}

/**
 * @brief 6502の命令実行
 * 
 */
void cpu_6502_exec(void)
{
    // TODO:
}

/**
 * @brief 6502のCPUメイン
 * 
 */
void cpu_6502_main(void)
{
    cpu_6502_fetch();   // 命令フェッチ
    cpu_6502_decode();  // 命令デコード
    cpu_6502_exec();    // 命令実行
}