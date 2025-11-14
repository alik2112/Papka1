#include <iostream>
#include <limits>
#include <cassert>
#include <cmath>

int int_log2(int x) {
    // int в unsigned int для побитовых операций
    unsigned int ux = static_cast<unsigned int>(x);
    if (ux == 0) {  // ноль
        return -1;
    }
    
    int position = 0;
    unsigned int temp = ux;
    
    while (temp > 1) {
        temp >>= 1;
        position++;  // позиция старшего ненулевого бита

    }
    
    return position;
}

int float_log2(float x) {
    // union для доступа к битовому представлению
    union {
        float f;
        unsigned int u;
    } converter;
    
    converter.f = x;
    unsigned int bits = converter.u;
    
    // экспонента (биты 23-30), справа налево
    unsigned int exponent = (bits >> 23) & 0xFF;
    // мантисса (биты 0-22)
    unsigned int mantissa = bits & 0x7FFFFF;
    // проверка на специальные случаи
    if (exponent == 0xFF) { // бесконечность или NaN
      return std::numeric_limits<int>::max(); // большое значение как индикатор
    }
    
    if (exponent == 0) { // Денормализованное число или ноль
        if (mantissa == 0) { // Ноль
            return -1; // логарифм 0 не определен
        }
        
        // для денормализованных чисел ищем старший ненулевой бит в мантиссе
        int position = -1;
        unsigned int temp = mantissa;
        while (temp > 0) {
            temp >>= 1;
            position++;
        }
        // Для денормализованных чисел: экспонента + мантисса = 126 + 23 = 149
        return position - 149;
    }
    // Для нормализованных чисел: log2 = экспонента - 127
    return static_cast<int>(exponent) - 127;
}

int main() {
    // для целых
    assert(int_log2(0) == -1);
    assert(int_log2(1) == 0);
    assert(int_log2(2) == 1);
    assert(int_log2(4) == 2);
    assert(int_log2(8) == 3);
    assert(int_log2(16) == 4);
    assert(int_log2(255) == 7);
    assert(int_log2(256) == 8);
    assert(int_log2(1024) == 10);
    
    // для нормальных и специальных
    assert(float_log2(0.0f) == -1);
    assert(float_log2(1.0f) == 0);
    assert(float_log2(2.0f) == 1);
    assert(float_log2(4.0f) == 2);
    assert(float_log2(8.0f) == 3);
    assert(float_log2(0.5f) == -1);
    assert(float_log2(0.25f) == -2);
    assert(float_log2(std::numeric_limits<float>::infinity()) == std::numeric_limits<int>::max());
    assert(float_log2(std::numeric_limits<float>::quiet_NaN()) == std::numeric_limits<int>::max());

    // для денормализованных
    float denormal = std::numeric_limits<float>::denorm_min();
    assert(float_log2(denormal) == -149);
}