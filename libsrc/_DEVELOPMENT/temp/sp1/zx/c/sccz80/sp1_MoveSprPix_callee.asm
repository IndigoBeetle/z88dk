; void __CALLEE__ sp1_MoveSprPix_callee(struct sp1_ss *s, struct sp1_Rect *clip, uchar *frame, uint x, uint y)
; 03.2006 aralbrec, Sprite Pack v3.0
; sinclair zx version

SECTION code_clib
SECTION code_temp_sp1

PUBLIC sp1_MoveSprPix_callee

EXTERN asm_sp1_MoveSprPix

sp1_MoveSprPix_callee:

   pop af
   pop bc
   pop de
   pop hl
   pop iy
   pop ix
   push af

   jp asm_sp1_MoveSprPix

; SDCC bridge for Classic
IF __CLASSIC
PUBLIC _sp1_MoveSprPix_callee
defc _sp1_MoveSprPix_callee = sp1_MoveSprPix_callee
ENDIF

