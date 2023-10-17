

;
; Entry: EHL=far pointer
; Exit: a=byte

SECTION code_clib
SECTION code_l_sccz80

.ASSUME ADL = 0        ; use the 16 bit address, with MBASE

lp_gchar:
    push.l    hl       ; push 3 bytes (HLU is undefined in Z80 MEMORY Mode)
    ld.lil    hl,2     ; point to pushed HLU by loading 16 bit 0x0002 to HL, HLU is written to 0x00.
    add.l     hl,sp    ; by adding the 24 bit SPL to 24 bit HL
    ld.l      (hl),e   ; store the E register at the HLU location in stack
    pop.l     hl       ; get a correct (far pointer) long address into 24 bit HL
    ld.l      a,(hl)   ; get a byte from that location into A.
    ret.l              ; return correctly from a long call
