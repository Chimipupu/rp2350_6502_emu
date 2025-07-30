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
#include <stdio.h>

cpu_6502_reg_t s_cpu_6502_reg;
static cpu_6502_t s_cpu_6502;
static uint8_t s_rom[CPU_6502_ROM_SIZE];
static uint8_t s_ram[CPU_6502_RAM_SIZE];

#ifdef DEBUG_CPU_6502
static void dbg_6502_info_print(void);

static void dbg_6502_info_print(void)
{
    printf("\n[DEBUG] 6502 CPU REG info\n");
    printf("[DEBUG] REG A = 0x%02X\n", s_cpu_6502.p_reg->a);
    printf("[DEBUG] REG X = 0x%02X\n", s_cpu_6502.p_reg->x);
    printf("[DEBUG] REG Y = 0x%02X\n", s_cpu_6502.p_reg->y);
    printf("[DEBUG] REG P = 0x%02X\n", s_cpu_6502.p_reg->p_reg.byte);
    printf("[DEBUG] REG SP = 0x%02X\n", s_cpu_6502.p_reg->sp);
    printf("[DEBUG] REG PC = 0x%04X\n", s_cpu_6502.p_reg->pc);
}
#endif // DEBUG_CPU_6502

static void cpu_6502_reset(void);
static void cpu_6502_fetch(void);
static void cpu_6502_decode(void);
static void cpu_6502_exec(void);
static void cpu_6502_addr_proc(uint16_t addr);

/**
 * @brief アドレス特有処理
 * 
 * @param addr 
 */
static void cpu_6502_addr_proc(uint16_t addr)
{
    switch(addr)
    {
        case IRQ_VECT_ADDR_NMI:
            // TODO : NMI割り込み処理
            printf("\n[DEBUG] NMI (PC = 0x%04X)\n", s_cpu_6502.p_reg->pc);
            break;

        case IRQ_VECT_ADDR_RST:
            // リセット割り込み処理
            printf("\n[DEBUG] Reset (PC = 0x%04X)\n", s_cpu_6502.p_reg->pc);
            cpu_6502_reset();
            break;

        case IRQ_VECT_ADDR_IRQ_BRK:
            // TODO : IRQ/BRK割り込み処理
            printf("\n[DEBUG] IRQ/BRK (PC = 0x%04X)\n", s_cpu_6502.p_reg->pc);
            break;

        default:
            break;
    }
}

/**
 * @brief 6502のCPUリセット
 * 
 */
static void cpu_6502_reset(void)
{
    // レジスタ初期化
    s_cpu_6502.p_reg = &s_cpu_6502_reg;
    s_cpu_6502.p_reg->p_reg.byte = 0;
    s_cpu_6502.p_reg->p_reg.bit.r = 1;
    s_cpu_6502.p_reg->p_reg.bit.i = 1;
    s_cpu_6502.p_reg->a = 0x00;
    s_cpu_6502.p_reg->x = 0x00;
    s_cpu_6502.p_reg->y = 0x00;
    s_cpu_6502.p_reg->sp = 0xFD;
    s_cpu_6502.p_reg->pc = IRQ_VECT_ADDR_RST;
}

/**
 * @brief 6502の命令フェッチ
 * 
 */
static void cpu_6502_fetch(void)
{
    // TODO:
}

/**
 * @brief 6502の命令デコード
 * 
 */
static void cpu_6502_decode(void)
{
    // TODO:
}

/**
 * @brief 6502の命令実行
 * 
 */
static void cpu_6502_exec(void)
{
    // TODO:
}

/**
 * @brief 6502のCPU初期化
 * 
 */
void cpu_6502_init(void)
{
    // リセットベクタ処理
    cpu_6502_reset();

    // ROM/RAM初期化
    memset(&s_rom[0], 0x00, CPU_6502_ROM_SIZE);
    memset(&s_ram[0], 0x00, CPU_6502_RAM_SIZE);
    s_cpu_6502.p_rom = &s_rom[0];
    s_cpu_6502.p_ram = &s_ram[0];
}

/**
 * @brief 6502のCPUメイン
 * 
 */
void cpu_6502_main(void)
{
#ifdef DEBUG_CPU_6502
    dbg_6502_info_print();
#endif // DEBUG_CPU_6502
    cpu_6502_addr_proc(s_cpu_6502.p_reg->pc);
    cpu_6502_fetch();   // 命令フェッチ
    cpu_6502_decode();  // 命令デコード
    cpu_6502_exec();    // 命令実行
}