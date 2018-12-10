;
;       Z88 Graphics Functions - Small C+ stubs
;
;       Written around the Interlogic Standard Library
;
;       Stubs Written by D Morris - 30/9/98
;
;       Wide resolution (int type parameters) version by Stefano Bodrato
;

;
;	$Id: undrawr_callee.asm $
;

;
; CALLER LINKAGE FOR FUNCTION POINTERS
; ----- void  undrawr(int x2, int y2)


SECTION smc_clib

PUBLIC     undrawr_callee
PUBLIC    _undrawr_callee

	EXTERN    undrawr

.undrawr_callee
._undrawr_callee
	pop af	; ret addr
	pop	bc
	pop	de
	push af	; ret addr
	push de
	push bc
	
	call undrawr
	pop bc
	pop bc
	ret
