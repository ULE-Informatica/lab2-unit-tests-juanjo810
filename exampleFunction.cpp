#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h>

/**
 * INT30-C. Ensure that unsigned integer operations do not wrap
*/
unsigned int wrapFunctionAdd(unsigned int ui_a, unsigned int ui_b) {
  if (ui_a > (UINT_MAX - ui_b)) {
    return 1;
  }
  unsigned int usum = ui_a + ui_b;
  return usum;
}

/**
 * INT30-C. Ensure that unsigned integer operations do not wrap
*/
unsigned int wrapFunctionMul(unsigned int ui_a, unsigned int ui_b) {
  unsigned umul = ui_a;
  if (ui_a != 0 && (UINT_MAX/ui_a) < ui_b) {
    return 1;
  }
  umul *= ui_b;
  return umul;
}

/**
 * INT30-C. Ensure that unsigned integer operations do not wrap
*/
uint32_t wrapFunctionShift(uint32_t ui_a, unsigned int ui_b) {
  uint32_t uShift = ui_a << ui_b | ui_a >> (32 - ui_b); 
  if (ui_b >= __builtin_popcount(UINT_MAX) - __builtin_popcount(ui_a)) {
    return 1;
  } 
  return uShift;
}
