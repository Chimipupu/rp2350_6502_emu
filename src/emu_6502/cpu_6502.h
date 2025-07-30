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

#define MEM_MAP_MAX_ADDR             65535
#define CPU_6502_ROM_SIZE            32768
#define CPU_6502_RAM_SIZE            32768

#define IRQ_VECT_ADDR_NMI            0xFFFA // NMIの割り込みベクタアドレス
#define IRQ_VECT_ADDR_RST            0xFFFC // リセットの割り込みベクタアドレス
#define IRQ_VECT_ADDR_IRQ_BRK        0xFFFE // IRQかBRKの割り込みベクタアドレス

typedef struct {
    uint8_t a;      // 8bit  アキュムレータ
    uint8_t x;      // 8bit  インデックスレジスタX
    uint8_t y;      // 8bit  インデックスレジスタY
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
    }p_reg;         // 8bit ステータスレジスタ
    uint8_t sp;     // 8bit  スタックポインタ
    uint16_t pc;    // 16bit プログラムカウンタ
} cpu_6502_reg_t;

typedef struct {
    cpu_6502_reg_t *p_reg;  // レジスタ
    uint8_t *p_rom;         // ROM
    uint8_t *p_ram;         // RAM
} cpu_6502_t;

void cpu_6502_init(void);
void cpu_6502_main(void);
#endif // CPU_6502_H