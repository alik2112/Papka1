#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std::string_literals;

std::string FindPalindrome(std::string s)
{
  size_t n = s.size();
  size_t MaxInd = 0;
  size_t MaxLen = 1;
  std::vector<std::vector<bool>> ans(n, std::vector<bool>(n, false));
  for (auto i = 0uz; i < n; ++i)
  {
    ans[i][i] = true;
  }
  for (auto i = 0uz; i < n - 1; ++i)
  {
    if (s[i] == s[i + 1])
    {
      ans[i][i + 1] = true;
      MaxLen = 2;
      MaxInd = i;
    }
  }
  for (auto k = 3uz; k <= n; k++)
  {
    for (auto i = 0uz; i < n - k + 1; i++)
    {
      size_t j = i + k - 1;
      if (s[i] == s[j] && ans[i + 1][j - 1])
      {
        ans[i][j] = true;
        if (MaxLen < k)
        {
          MaxInd = i;
          MaxLen = k;
        }
      }
    }
  }
  return std::string(s.substr(MaxInd, MaxLen));
}

int main()
{
  assert(FindPalindrome("sahararahnide") == "hararah");
  assert(FindPalindrome("level") == "level");
  assert(FindPalindrome("s") == "s");
}