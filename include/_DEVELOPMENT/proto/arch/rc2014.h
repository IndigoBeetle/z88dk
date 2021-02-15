include(__link__.m4)

#ifndef __ARCH_RC2014_H__
#define __ARCH_RC2014_H__

#include <arch.h>

// GLOBAL VARIABLES


// IO MAPPED REGISTERS

#ifdef __CLANG

extern unsigned char io_dio;

extern unsigned char io_acia_control;
extern unsigned char io_acia_status;
extern unsigned char io_acia_data;

extern unsigned char io_sioa_control;
extern unsigned char io_sioa_data;
extern unsigned char io_siob_control;
extern unsigned char io_siob_data;

extern unsigned char io_pio_port_a;
extern unsigned char io_pio_port_b;
extern unsigned char io_pio_port_c;
extern unsigned char io_pio_control;

extern unsigned char io_pio_ide_lsb;
extern unsigned char io_pio_ide_msb;
extern unsigned char io_pio_ide_ctl;
extern unsigned char io_pio_ide_config;

extern unsigned char io_ram_toggle;
extern unsigned char io_rom_toggle;

#else

__sfr __at __IO_DIO_PORT       io_dio;

__sfr __at __IO_ACIA_CONTROL_REGISTER   io_acia_control;
__sfr __at __IO_ACIA_STATUS_REGISTER    io_acia_status;
__sfr __at __IO_ACIA_DATA_REGISTER      io_acia_data;

__sfr __at __IO_SIOA_CONTROL_REGISTER   io_sioa_control;
__sfr __at __IO_SIOA_DATA_REGISTER      io_sioa_data;
__sfr __at __IO_SIOB_CONTROL_REGISTER   io_siob_control;
__sfr __at __IO_SIOB_DATA_REGISTER      io_siob_data;

__sfr __at __IO_PIO_PORT_A      io_pio_port_a;
__sfr __at __IO_PIO_PORT_B      io_pio_port_b;
__sfr __at __IO_PIO_PORT_C      io_pio_port_c;
__sfr __at __IO_PIO_CONTROL     io_pio_control;

__sfr __at __IO_PIO_IDE_LSB     io_pio_ide_lsb;
__sfr __at __IO_PIO_IDE_MSB     io_pio_ide_msb;
__sfr __at __IO_PIO_IDE_CTL     io_pio_ide_ctl;
__sfr __at __IO_PIO_IDE_CONFIG  io_pio_ide_config;

__sfr __at __IO_RAM_TOGGLE      io_ram_toggle;
__sfr __at __IO_ROM_TOGGLE      io_rom_toggle;

__sfr __at __IO_LUT_OPERAND_LATCH   io_lut_operand_latch;
__sfr __at __IO_LUT_RESULT_MSB      io_lut_result_msb;
__sfr __at __IO_LUT_RESULT_LSB      io_lut_result_lsb;

#endif

// SYSTEM FUNCTIONS

// provide shadow RAM copy function for SC114, Wesley, and feilipu Memory Modules

__DPROTO(,,void,*,shadowwrite,void *dst,const void *src,size_t n)
__DPROTO(,,void,*,shadowread,void *dst,const void *src,size_t n)

// provide lut functions

__DPROTO(`d,e,iyh,iyl',`d,e,iyh,iyl',uint16_t,,lut_read,uint16_t location)

#ifdef __SCCZ80

#define lut_mulu(a,b) lut_read((uint8_t)(a)<<8|(uint8_t)(b))

#endif

#ifdef __SDCC

#define lut_mulu(a,b) lut_read_fastcall((uint8_t)(a)<<8|(uint8_t)(b))

#endif
#endif
