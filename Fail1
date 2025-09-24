#include <iostream>
#include <vector>

int main() {
    std::vector<int> cache(1000, 0);  //кэш для чисел
    cache[1] = 1;
    std::size_t max_value = 1;
    std::size_t value_start = 1;
    for (int start = 2; start <= 100; ++start){
        std::size_t length = 0;
        unsigned long long int n = start;
        while (n != 1){
            if (n < cache.size() && cache[n] != 0){
                length += cache[n];
                break;
            }   
            if (n % 2 == 0){
                n = n / 2;
            } else {
                n = 3 * n + 1;
            }
            ++length;
        }
        ++length; // технически надо добавить
        if (max_value < length){
            max_value = length;
            value_start = start;
        }
    }
    std::cout << value_start << " " << max_value << '\n';
}
