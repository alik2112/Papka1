#include <iostream>
#include <bitset>
unsigned int gray_encode(unsigned int val) {
  return (val ^ (val >> 1)); // ксорим все соседние биты, первый не меняется
}

unsigned int gray_decode(unsigned int val) {
  for (auto bit = 1U << 31; bit > 1; bit >>= 1) {
    if (bit & val) {
      val ^= (bit >> 1); // если бит равен 1, переключи следующий бит
    }
  }
  return val;
}
std::string to_binary(unsigned int value, int const digits) {
  return std::bitset<32>(value).to_string().substr(32-digits, digits); // переводим в двоичную
}
int main()
{
  std::cout << "Number\tBinary\tGray\tDecoded\n";
  std::cout << "------\t------\t----\t-------\n";  // \t tab
  for (unsigned int n = 0; n < 32; ++n) {
    auto encg = gray_encode(n);
    auto decg = gray_decode(encg);
    std::cout
      << n << "\t" << to_binary(n, 5) << "\t"
      << to_binary(encg, 5) << "\t" << decg << "\n";
  }
}