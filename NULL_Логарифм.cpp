#include <iostream>
#include <limits>
#include <cassert>
#include <cmath>

int FindHighestBit(unsigned int value) {
  if (value == 0) {
    return -1;
  }
  
  int position = 0;
  while (value > 1) {
    value >>= 1;
    position++;
  }
  return position;
}

int FloorLogInts(int val) {
  return FindHighestBit(static_cast<unsigned int>(val));
}

int FloorLogFloats(float val) {
  union {
    float num;
    unsigned int u;
  } converter;

  converter.num = val;
  unsigned int bits = converter.u;

  // экспонента (биты 23-30), справа налево, мантисса (биты 0-22)
  const unsigned int exp_pos = 23;
  unsigned int exponent = (bits >> exp_pos) & 0xFF;
  unsigned int mantissa = bits & 0x7FFFFF;
  if (exponent == 0xFF) {
    return std::numeric_limits<int>::max();
  }
  
  if (exponent == 0) {
    if (mantissa == 0) {
      return -1;
    }
    const int denorm_slip = 149;
    // Для денормализованных чисел: экспонента + мантисса = 126 + 23 = 149
    return FindHighestBit(mantissa) - denorm_slip;
  }
  const int  norm_slip = 127;
  // Для нормализованных чисел: log2 = экспонента - 127
  return static_cast<int>(exponent) - norm_slip;
}

void TestIntLog() {
  assert(FloorLogInts(0) == -1);
  assert(FloorLogInts(1) == 0);
  assert(FloorLogInts(2) == 1);
  assert(FloorLogInts(4) == 2);
  assert(FloorLogInts(8) == 3);
  assert(FloorLogInts(16) == 4);
  assert(FloorLogInts(255) == 7);
  assert(FloorLogInts(256) == 8);
  assert(FloorLogInts(1024) == 10);
}

void TestFloatNormLog() {
  assert(FloorLogFloats(0.0f) == -1);
  assert(FloorLogFloats(1.0f) == 0);
  assert(FloorLogFloats(2.0f) == 1);
  assert(FloorLogFloats(4.0f) == 2);
  assert(FloorLogFloats(8.0f) == 3);
  assert(FloorLogFloats(0.5f) == -1);
  assert(FloorLogFloats(0.25f) == -2);
  assert(FloorLogFloats(std::numeric_limits<float>::infinity()) == std::numeric_limits<int>::max());
  assert(FloorLogFloats(std::numeric_limits<float>::quiet_NaN()) == std::numeric_limits<int>::max());
}

void TestFloatDenormLog() {
  float denormal = std::numeric_limits<float>::denorm_min();
  assert(FloorLogFloats(denormal) == -149);
}

int main() {
  TestIntLog();
  TestFloatNormLog();
  TestFloatDenormLog();
}