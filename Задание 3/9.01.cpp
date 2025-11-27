#include <iostream>
#include <source_location>

#ifdef NDEBUG
  #define trace() (void(0))
#else
  #define trace() Tracer tracer(std::source_location::current()) // только если включена отладка
#endif

class Tracer
{
private:
  std::string func_name;
public:
  Tracer(const std::source_location loc = std::source_location::current())
    : func_name(loc.function_name())
  {
    std::cout << "Старт функции " << func_name << '\n';
  }
  ~Tracer()
  {
    std::cout << "Конец функции " << func_name << '\n';
  }
};

void Test() {
  trace();
  std::cout << "SOME STUFF\n";
}

int main() {
  Test();
}