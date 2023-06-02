

    SECTION code_clib

    PUBLIC  generic_console_cls
    PUBLIC  generic_console_vpeek
    PUBLIC  generic_console_scrollup
    PUBLIC  generic_console_printc
    PUBLIC  generic_console_set_ink
    PUBLIC  generic_console_set_paper
    PUBLIC  generic_console_set_attribute

    EXTERN  __console_w
    EXTERN  CONSOLE_COLUMNS
    EXTERN  CONSOLE_ROWS
    EXTERN  __agon_putc

    INCLUDE "ioctl.def"
    INCLUDE "target/agon/def/mos_api.inc"
    PUBLIC  CLIB_GENCON_CAPS
    defc    CLIB_GENCON_CAPS = CAP_GENCON_CUSTOM_FONT | CAP_GENCON_UDGS | CAP_GENCON_FG_COLOUR | CAP_GENCON_BG_COLOUR


generic_console_set_attribute:
    ret

generic_console_set_ink:
    and     63
    jr      set_colour

generic_console_set_paper:
    and     63
    or      $80
set_colour:
    push    af
    ld      a,17
    call    __agon_putc
    pop     af
    call    __agon_putc
    ld      c,a
    ; Set graphics colours as well
    ld      a,18
    call    __agon_putc
    xor     a           ;graphic mode
    call    __agon_putc
    ld      a,c
    jp      __agon_putc
    
generic_console_cls:
    ld      a,12
    jp      __agon_putc

generic_console_scrollup:
    push    de
    push    bc
    ld      hl,scroll
    ld      b,5
    call    prstr
    pop     bc
    pop     de
    ret

; c = x
; b = y
; a = d = character to print
; e = raw
generic_console_printc:
    ld      (prbuf+3),a
    ld      a,b
    ld      (prbuf+2),a
    ld      a,c
    ld      (prbuf+1),a
    ld      hl,prbuf
    ld      b,4
prstr:
loop:
    ld      a,(hl)
    push    bc
    call    __agon_putc
    pop     bc
    inc     hl
    djnz    loop
    ret


;Entry: c = x,
;    b = y
;    e = rawmode
;Exit:  nc = success
;    a = character,
;    c = failure
generic_console_vpeek:
    ld      a,c
    ld      (vpeekbuf+3),a
    ld      a,b
    ld      (vpeekbuf+5),a
    push    ix
    MOSCALL(mos_sysvars)
    defb    $5b     ;LIL
    res     1,(ix+sysvar_vpd_pflags)

    ld      hl,vpeekbuf
    ld      b,7
    call    prstr
ck:
    defb    $5b     ;LIL
    bit     1,(ix+sysvar_vpd_pflags)
    jr      z,ck
    defb    $5b     ;LIL
    ld      a,(ix+ sysvar_scrchar)
    and     a
    pop     ix
    ret




    SECTION data_clib

prbuf:    
    defb    31
    defb    0    ;y
    defb    0    ;x
    defb    0    ;char

vpeekbuf:
    defb    23
    defb    0
    defb    vdp_scrchar
    defw    0           ;x
    defw    0           ;y

scroll:
    defb    23, 7, 1, 3, 8

    SECTION rodata_clib

init:
        db 22, 1 ;; Mode 1
        db 23, 1, 0 ;; Hide cursor


   SECTION code_crt_init

   ld      hl,init
   ld      b,5
   call    prstr
