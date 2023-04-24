#ifndef REMU_MACHINE_H_
#define REMU_MACHINE_H_

/*
 * utilities
 */

#include <stdbool.h>
#include <stdint.h>

typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

/*
 * elf
 */

#include <stdio.h>
#include <elf.h>

int load_elf(char *buf);

/*
 * xlen
 */

enum xlen {
  x32,
  x64
};

/*
 * modes
 */

enum mode {
  user        = 0,
  supervisor  = 1,
  hypervisor  = 2,
  machine     = 3
};

/*
 * remu virtual machine
 */

struct machine {
  u64 pc;
  bool wfi;
  enum xlen xlen;
  enum mode mode;
  i64 x[32];
  float f[32];
};

#endif // REMU_MACHINE_H_
