
SECTION code_clib
SECTION code_fp_am9511

PUBLIC asm_sccz80_readl_callee
PUBLIC asm_sccz80_read1_callee

PUBLIC asm_sdcc_readr_callee
PUBLIC asm_sdcc_read1_callee

.asm_sccz80_readl_callee

    ; sccz80 float primitive
    ; Read right sccz80 float from the stack
    ;
    ; enter : stack = sccz80_float left, sccz80_float right, ret1, ret0
    ;
    ; exit  : sccz80_float right, ret1
    ;         DEHL = sccz80_float right
    ; 
    ; uses  : af, bc, de, hl, bc', de', hl'

.asm_sdcc_readr_callee

    ; sdcc float primitive
    ; Read right sdcc float from the stack
    ;
    ; enter : stack = sdcc_float right, sdcc_float left, ret1, ret0
    ;
    ; exit  : sdcc_float left, ret1
    ;         DEHL = sdcc_float right
    ; 
    ; uses  : af, bc, de, hl, bc', de', hl'
    
    pop af                      ; my return
    pop bc                      ; ret 1
    exx
    pop hl                      ; sccz80_float right
    pop de
    exx
    pop hl                      ; sccz80_float left
    pop de
    exx
    push de                     ; sccz80_float right
    push hl
    exx                         ; sccz80_float left
    push bc                     ; ret 1
    push af                     ; my return
    ret


.asm_sccz80_read1_callee

    ; sccz80 float primitive
    ; Read a single sccz80 float from the stack
    ;
    ; enter : stack = sccz80_float, ret1, ret0
    ;
    ; exit  : ret1
    ;         DEHL = sccz80_float 
    ;
    ; uses  : af, bc, de, hl

.asm_sdcc_read1_callee

    ; sdcc float primitive
    ; Read a single sdcc float from the stack
    ;
    ; enter : stack = sdcc_float, ret1, ret0
    ;
    ; exit  : ret1
    ;         DEHL = sdcc_float 
    ;
    ; uses  : af, bc, de, hl

    pop af                      ; my return
    pop bc                      ; ret 1
    pop hl                      ; sccz80_float or sdcc_float
    pop de
    push bc
    push af
    ret
