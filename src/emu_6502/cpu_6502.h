/**
 * @file cpu_6502.h
 * @author Chimipupu(https://github.com/Chimipupu)
 * @brief 6502のCPU関連
 * @version 0.1
 * @date 2025-07-30
 * 
 * @copyright Copyright (c) 2025 Chimipupu All Rights Reserved.
 * 
 */

#ifndef CPU_6502_H
#define CPU_6502_H

#include <stdint.h>
#include <string.h>

#define DEBUG_CPU_6502

#define MEM_ADDR_MAX                 65535
#define CPU_6502_ROM_SIZE            32768
#define CPU_6502_RAM_SIZE            32768

// =======================================================
// [メモリマップ]
// =======================================================
// RAM (0x0000 ~ 0x3FFF)
#define RAM_START_ADDR               0x0000
#define RAM_END_ADDR                 0x3FFF
// -------------------------------------------------------
// ゼロページ (0x0000 ~ 0x01FF)
#define ZERO_PAGE_START_ADDR         0x0000
#define ZERO_PAGE_END_ADDR           0x00FF
// -------------------------------------------------------
// スタック (0x0000 ~ 0x01FF)
#define STACK_START_ADDR             0x0100
#define STACK_END_ADDR               0x01FF
// -------------------------------------------------------
// I/O (0x0000 ~ 0x3FFF)
#define IO_START_ADDR                0x4000
#define IO_END_ADDR                  0x7FFF
// -------------------------------------------------------
// ROM (0x0000 ~ 0x3FFF)
#define ROM_START_ADDR               0x8000
#define ROM_END_ADDR                 0xFFFF
// =======================================================

// NMIの割り込みベクタアドレス
#define NMI_VECT_TBL_ADDR            0xFFFA
// リセットの割り込みベクタアドレス
#define RST_VECT_TBL_ADDR            0xFFFC
// IRQかBRKの割り込みベクタアドレス
#define IRQ_BRK_VECT_TBL_ADDR        0xFFFE

#define SP_INIT_VAL                  0xFD

// CPU 6502レジスタの構造体
typedef struct {
    uint8_t a;            // 8bit  アキュムレータ
    uint8_t x;            // 8bit  インデックスレジスタX
    uint8_t y;            // 8bit  インデックスレジスタY
    union {
        uint8_t byte;
        struct {
            uint8_t c : 1; // Bit1 キャリー
            uint8_t z : 1; // Bit2 ゼロ
            uint8_t i : 1; // Bit3 IRQ禁止
            uint8_t d : 1; // Bit4 デシマルモード
            uint8_t b : 1; // Bit5 ブレークモード
            uint8_t r : 1; // Bit6 Reserved (always set to 1)
            uint8_t v : 1; // Bit7 オーバーフロー
            uint8_t n : 1; // Bit8 ネガティブ
        }bit;
    }psr;                  // 8bit ステータスレジスタ
    uint8_t sp;            // 8bit  スタックポインタ
    uint16_t pc;           // 16bit プログラムカウンタ
} cpu_6502_reg_t;


// CPU 6502の構造体
typedef struct {
    cpu_6502_reg_t *p_reg;    // レジスタのポインタ
    uint8_t *p_rom;           // ROMのポインタ
    uint8_t *p_ram;           // RAMのポインタ
} cpu_6502_t;

void cpu_6502_init(void);
void cpu_6502_main(void);
#endif // CPU_6502_H