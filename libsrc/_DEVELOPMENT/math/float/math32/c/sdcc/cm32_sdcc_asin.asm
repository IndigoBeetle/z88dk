

SECTION code_fp_math32
PUBLIC cm32_sdcc_asin

EXTERN _m32_asinf

cm32_sdcc_asin:
        pop     bc
        pop     hl
        pop     de
        push    de
        push    hl
        push    bc
        jp      _m32_asinf
