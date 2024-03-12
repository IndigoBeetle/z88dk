;
;	Startup for the DAI
;


    module dai_crt0


;--------
; Include zcc_opt.def to find out some info
;--------

    defc    crt0 = 1
    INCLUDE "zcc_opt.def"

;--------
; Some scope definitions
;--------

    EXTERN    _main           ;main() is always external to crt0 code
    EXTERN    asm_im1_handler
    EXTERN    asm_load_palette

    PUBLIC    __Exit         ;jp'd to by exit()
    PUBLIC    l_dcal          ;jp(hl)

    IFNDEF CLIB_FGETC_CONS_DELAY
            defc CLIB_FGETC_CONS_DELAY = 150
    ENDIF

    defc    TAR__fputc_cons_generic = 0
    defc    TAR__clib_exit_stack_size = 32
    defc    TAR__register_sp = -1
    defc    CRT_KEY_DEL = 8
    defc    __CPU_CLOCK = 2000000
    defc    CONSOLE_ROWS = 32
    defc    CONSOLE_COLUMNS = 32
    INCLUDE "crt/classic/crt_rules.inc"

    defc    CRT_ORG_CODE = 0x0800

    org     CRT_ORG_CODE



program:
    INCLUDE "crt/classic/crt_init_sp.inc"
    call    crt0_init
    INCLUDE "crt/classic/crt_init_atexit.inc"


    INCLUDE "crt/classic/crt_init_heap.inc"
    INCLUDE "crt/classic/crt_init_eidi.inc"

    ld      hl,0
    push    hl
    push    hl
    call    _main
    pop     bc
    pop     bc
__Exit:
    push    hl
    call    crt0_exit
    pop     hl
    INCLUDE "crt/classic/crt_exit_eidi.inc"
    ret

l_dcal: jp      (hl)            ;Used for function pointer calls

    INCLUDE "crt/classic/crt_runtime_selection.inc" 

    INCLUDE	"crt/classic/crt_section.inc"
