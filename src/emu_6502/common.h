/**
 * @file common.h
 * @author Chimipupu(https://github.com/Chimipupu)
 * @brief 共通ヘッダ
 * @version 0.1
 * @date 2025-07-31
 * 
 * @copyright Copyright (c) 2025 Chimipupu All Rights Reserved.
 * 
 */
#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

static inline void _NOP(void)
{
    __asm __volatile("nop");
}

#endif // COMMON_H