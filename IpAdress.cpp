#include <iostream>
#include <cstdint>
#include <cassert>

class IPv4
{
private:
  std::uint8_t arr[4];
public:
  IPv4() : arr{0, 0, 0, 0} {}
  IPv4(std::uint8_t a, std::uint8_t b, std::uint8_t c, std::uint8_t d) 
    : arr{a, b, c, d} {}
  IPv4& operator++() {  // ++ip
    for (int i = 3; i >= 0; --i) {
      if (arr[i] < 255) {
        ++arr[i];
        break;
      } else {
        arr[i] = 0;
      }
    }
    return *this;
  }
  
  IPv4 operator++(int) {  // ip++
    IPv4 old(*this);
    ++(*this);
    return old; 
  }
  
  IPv4& operator--() {  // --ip
    for (int i = 3; i >= 0; --i) {
      if (arr[i] > 0) {
        --arr[i];
        break;
      } else {
        arr[i] = 255;
      }
    }
    return *this;
  }
  
  IPv4 operator--(int) {  // ip--
    IPv4 old(*this);
    --(*this);
    return old;
  }

  friend bool operator==(const IPv4& lhs, const IPv4& rhs) {
    for (int i = 0; i < 4; ++i) {
      if (lhs.arr[i] != rhs.arr[i]){
        return false;
      }
    }
    return true;
  }

  friend bool operator<(const IPv4& lhs, const IPv4& rhs) {
    for (int i = 0; i < 4; ++i) {
      if (lhs.arr[i] != rhs.arr[i]) {
        return lhs.arr[i] < rhs.arr[i];
      }
    }
    return false;
  }
  
  friend bool operator!=(const IPv4& lhs, const IPv4& rhs) { return !(lhs == rhs); }
  friend bool operator>(const IPv4& lhs, const IPv4& rhs)  { return rhs < lhs; }
  friend bool operator<=(const IPv4& lhs, const IPv4& rhs) { return !(lhs > rhs); }
  friend bool operator>=(const IPv4& lhs, const IPv4& rhs) { return !(lhs < rhs); }
  
  friend std::ostream& operator<<(std::ostream& os, const IPv4& ip) {
    os << static_cast<int>(ip.arr[0]) << '.' 
       << static_cast<int>(ip.arr[1]) << '.' 
       << static_cast<int>(ip.arr[2]) << '.' 
       << static_cast<int>(ip.arr[3]);
    return os;
  }
  
  friend std::istream& operator>>(std::istream& is, IPv4& ip) {
    int a, b, c, d;
    char dot1, dot2, dot3;
    is >> a >> dot1 >> b >> dot2 >> c >> dot3 >> d;
    
    if (dot1 == '.' && dot2 == '.' && dot3 == '.' &&
        a >= 0 && a <= 255 && b >= 0 && b <= 255 &&
        c >= 0 && c <= 255 && d >= 0 && d <= 255) {
      ip.arr[0] = static_cast<std::uint8_t>(a);
      ip.arr[1] = static_cast<std::uint8_t>(b);
      ip.arr[2] = static_cast<std::uint8_t>(c);
      ip.arr[3] = static_cast<std::uint8_t>(d);
    }
    
    return is;
  }
};

int main() {
  IPv4 ip1;
  assert(ip1 == IPv4(0, 0, 0, 0));
  
  IPv4 ip2(192, 168, 1, 1);
  ++ip2;
  assert(ip2 == IPv4(192, 168, 1, 2));
  
  IPv4 ip3(192, 168, 1, 5);
  --ip3;
  assert(ip3 == IPv4(192, 168, 1, 4));
  
  IPv4 ip4(10, 0, 0, 1);
  IPv4 ip5(10, 0, 0, 2);
  assert(ip4 < ip5);
  assert(ip5 > ip4);
  assert(ip4 != ip5);
  
  IPv4 ip6(255, 255, 255, 255);
  ++ip6;
  assert(ip6 == IPv4(0, 0, 0, 0));
}