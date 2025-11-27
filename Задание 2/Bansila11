#include <iostream>
#include <vector>
std::string to_roman(unsigned int value) {
  std::vector<std::pair<unsigned int, char const*>> roman {
    { 1000, "M" },{ 900, "CM" }, { 500, "D" },{ 400, "CD" },
    { 100, "C" },{ 90, "XC" }, { 50, "L" },{ 40, "XL" },
    { 10, "X" },{ 9, "IX" }, { 5, "V" },{ 4, "IV" },{ 1, "I" }};  // добавляем все уникальные значения
  std::string res;
  for (auto const & el : roman) { // нет копирования, защита от изменений, эффективнее
    while (value >= el.first) {
      res += el.second;
      value -= el.first; // уменьшаем и заполняем ответ насколько возможно
    }
  }
  return res;
}

int main() {
  for (int i = 1; i <= 100; ++i) {
    std::cout << i << "\t" << to_roman(i) << '\n';
  }
  int number = 0;
  std::cout << "number:";
  std::cin >> number;
  std::cout << to_roman(number) << '\n';
}
