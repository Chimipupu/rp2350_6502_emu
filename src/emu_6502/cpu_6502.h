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

#define MEM_MAP_MAX_ADDR     65535
#define CPU_6502_ROM_SIZE    32768
#define CPU_6502_RAM_SIZE    32768

typedef struct {
    uint8_t p;     // 8bit ステータスレジスタ
    uint8_t acc;   // 8bitアキュムレータ
    uint8_t x;     // 8bit インデックスレジスタX
    uint8_t y;     // 8bit インデックスレジスタY
    uint8_t sp;    // 8bit スタックポインタ
    uint16_t pc;   // 16bit プログラムカウンタ
} cpu_6502_reg_t;

typedef struct {
    cpu_6502_reg_t *p_reg;  // レジスタ
    uint8_t *p_rom;         // ROM
    uint8_t *p_ram;         // RAM
} cpu_6502_t;

void cpu_6502_reset(void);
void cpu_6502_fetch(void);
void cpu_6502_decode(void);
void cpu_6502_exec(void);
void cpu_6502_main(void);
#endif // CPU_6502_H