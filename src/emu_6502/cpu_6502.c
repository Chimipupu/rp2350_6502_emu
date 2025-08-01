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
#include "ansi_esc.h"
#include <stdio.h>
#include "opcode_6502.h"

extern const opcode_6502_t g_6502_opcode_tbl[];
cpu_6502_reg_t s_reg;

static cpu_6502_data_t s_cpu_6502;
static uint8_t s_rom[CPU_6502_ROM_SIZE];
static uint8_t s_ram[CPU_6502_RAM_SIZE];

static uint8_t* mem_map_ctrl(uint16_t addr);
static void cpu_reset(void);
static void vect_tbl_proc(uint16_t addr);

#ifdef DEBUG_CPU_6502
static void dbg_6502_info_print(void);

static void dbg_6502_info_print(void)
{
    printf("\n[DEBUG] 6502 CPU REG info\n");

    printf("[DEBUG] A:0x%02X X:0x%02X Y:0x%02X SP = 0x%02X PC = 0x%04X\n",
            s_cpu_6502.p_reg->a, s_cpu_6502.p_reg->x, s_cpu_6502.p_reg->y, s_cpu_6502.p_reg->sp, s_cpu_6502.p_reg->pc);

    printf("[DEBUG] PSR = 0x%02X "
            "(N:%d V:%d B:%d D:%d i:%d Z:%d C:%d )\n",
            s_cpu_6502.p_reg->psr.byte,
            s_cpu_6502.p_reg->psr.bit.n,
            s_cpu_6502.p_reg->psr.bit.v,
            s_cpu_6502.p_reg->psr.bit.b,
            s_cpu_6502.p_reg->psr.bit.d,
            s_cpu_6502.p_reg->psr.bit.i,
            s_cpu_6502.p_reg->psr.bit.z,
            s_cpu_6502.p_reg->psr.bit.c
            );
}
#endif // DEBUG_CPU_6502

/**
 * @brief メモリマップ処理
 * 
 * @param addr 16bitアドレス
 * @return uint8_t* メモリのポインタ
 */
static uint8_t* mem_map_ctrl(uint16_t addr)
{
    if (addr >= RAM_START_ADDR && addr <= RAM_END_ADDR) {
        // RAM領域
        return &s_ram[addr - RAM_START_ADDR];
    } else if (addr >= ROM_START_ADDR && addr <= ROM_END_ADDR) {
        // ROM領域
        return &s_rom[addr - ROM_START_ADDR];
    } else if (addr >= IO_START_ADDR && addr <= IO_END_ADDR) {
        // TODO : I/O領域（未実装）
        return NULL;
    }

    // 範囲外
    return NULL;
}

/**
 * @brief 8bitメモリ読み出し
 * 
 * @param addr 16bitアドレス
 * @return uint8_t メモリ値
 */
uint8_t mem_byte_read(uint16_t addr)
{
    uint8_t* p = mem_map_ctrl(addr);
    if (p != NULL) {
        return *p;
    }
    // TODO : I/Oや範囲外は0返却
    return 0;
}

/**
 * @brief 8bitメモリ書き込み
 * 
 * @param addr 16bitアドレス
 * @param val 書き込み値
 */
void mem_byte_write(uint16_t addr, uint8_t val)
{
    uint8_t* p = mem_map_ctrl(addr);
    // ROM領域は書き込み禁止
    if (p != NULL && !(addr >= ROM_START_ADDR && addr <= ROM_END_ADDR)) {
        *p = val;
    }
    // TODO : I/O領域は未実装
}

/**
 * @brief ベクタテーブル処理
 * 
 * @param addr 16bitアドレス
 */
static void vect_tbl_proc(uint16_t addr)
{
    switch(addr)
    {
        case NMI_VECT_TBL_ADDR:
            // TODO : NMI割り込み処理
            printf("\n[DEBUG] NMI (PC = 0x%04X)\n", s_cpu_6502.p_reg->pc);
            break;

        case RST_VECT_TBL_ADDR:
            // リセット割り込み処理
            printf("\n[DEBUG] Reset (PC = 0x%04X)\n", s_cpu_6502.p_reg->pc);
            cpu_reset();
            break;

        case IRQ_BRK_VECT_TBL_ADDR:
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
static void cpu_reset(void)
{
    // レジスタ初期化
    s_cpu_6502.p_reg = &s_reg;
    s_cpu_6502.p_reg->psr.byte = 0;
    s_cpu_6502.p_reg->psr.bit.i = 1;
    s_cpu_6502.p_reg->psr.bit.b = 1;
    s_cpu_6502.p_reg->psr.bit.r = 1;
    s_cpu_6502.p_reg->a = 0x00;
    s_cpu_6502.p_reg->x = 0x00;
    s_cpu_6502.p_reg->y = 0x00;
    s_cpu_6502.p_reg->sp = SP_INIT_VAL;
    s_cpu_6502.p_reg->pc = RST_VECT_TBL_ADDR;

    // RAM初期化
    memset(&s_ram[0], 0x00, CPU_6502_RAM_SIZE);
    s_cpu_6502.p_ram = &s_ram[0];
}

/**
 * @brief 6502のCPU初期化
 * 
 */
void cpu_6502_init(void)
{
    // リセットベクタ処理
    cpu_reset();

    // ROM初期化
    memset(&s_rom[0], 0x00, CPU_6502_ROM_SIZE);
    s_cpu_6502.p_rom = &s_rom[0];

    // RAM初期化
    memset(&s_ram[0], 0x00, CPU_6502_RAM_SIZE);
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

    // 命令フェッチ
    uint8_t op = mem_byte_read(s_cpu_6502.p_reg->pc);

    // 命令デコード、実行
    if (g_6502_opcode_tbl[op].p_func != NULL) {
        g_6502_opcode_tbl[op].p_func(&s_cpu_6502, g_6502_opcode_tbl[op].addrsig);
    }

    s_cpu_6502.p_reg->pc += 1;
}