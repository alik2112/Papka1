#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

class Life
{
private:
  std::vector<std::vector<int>> table;
  std::vector<std::vector<int>> count;
  
public:
  Life() : table(10, std::vector<int>(10, 0)), count(10, std::vector<int>(10, 0)) {
    std::srand(std::time(0));
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        table[i][j] = std::rand() % 2;
      }
    }
  }
  
  void countNeighbors() {
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        count[i][j] = 0;
      }
    }
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        if (table[i][j]) {
          // 8 направлений соседей
          if (i - 1 >= 0 && j - 1 >= 0) {          // сверху-слева
            count[i - 1][j - 1] += 1;
          }
          if (i - 1 >= 0) {                        // сверху
            count[i - 1][j] += 1;
          }
          if (i - 1 >= 0 && j + 1 < 10) {          // сверху-справа
            count[i - 1][j + 1] += 1;
          }
          if (j - 1 >= 0) {                        // слева
            count[i][j - 1] += 1;
          }
          if (j + 1 < 10) {                        // справа
            count[i][j + 1] += 1;
          }
          if (i + 1 < 10 && j - 1 >= 0) {          // снизу-слева
            count[i + 1][j - 1] += 1;
          }
          if (i + 1 < 10) {                        // снизу
            count[i + 1][j] += 1;
          }
          if (i + 1 < 10 && j + 1 < 10) {          // снизу-справа
            count[i + 1][j + 1] += 1;
          }
        }
      }
    }
  }
  void print(){
    system("clear");
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        std::cout << (table[i][j] ? "■ " : "□ ");
      }
      std::cout << '\n';
    }
  }
  void Gen() {
    countNeighbors();
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        if (table[i][j] == 1) {
          if (count[i][j] < 2 || count[i][j] > 3) {
            table[i][j] = 0;
          }
        } else if (table[i][j] == 0){
          if (count[i][j] == 3) {
            table[i][j] = 1;
          }
        }
      }
    }
    print();
  }
  void Many_Gens() {
    for (int i = 0; i < 100; ++i) {
      Gen();
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
  }
};

int main() {
  Life test;
  test.Many_Gens();
}