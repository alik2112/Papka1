#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

struct Rectangle {
  int left;
  int top;
  int right;
  int bottom;
  Rectangle(int l, int t, int r, int b) : left(l), top(t), right(r), bottom(b) {}
  bool IsEmpty() const {
    return left >= right || top >= bottom;
  }
  int width() const {
    return IsEmpty() ? 0 : right - left;
  }
  int height() const {
    return IsEmpty() ? 0 : bottom - top;
  }
  int area() const {
    return width() * height();
  }
};

Rectangle intersection(const Rectangle& a, const Rectangle& b) {
  int left = std::max(a.left, b.left);
  int top = std::max(a.top, b.top);
  int right = std::min(a.right, b.right);
  int bottom = std::min(a.bottom, b.bottom);
  if (left >= right || top >= bottom) {
    return Rectangle(left, top, left, top);
  }
  return Rectangle(left, top, right, bottom);
}

int IntersectionArea(const std::vector<Rectangle>& rects) {
  if (rects.empty()) return 0;
  Rectangle current = rects[0];
  for (auto i = 1uz; i < rects.size(); ++i) {
    current = intersection(current, rects[i]);  // последовательно пересекаем
    if (current.IsEmpty()) return 0;
  }
  return current.area();
}

Rectangle BigRectangle(const std::vector<Rectangle>& rects) {
  if (rects.empty()) return Rectangle(0, 0, 0, 0);
  int min_left = rects[0].left;
  int min_top = rects[0].top;
  int max_right = rects[0].right;
  int max_bottom = rects[0].bottom;
  for (auto i = 1uz; i < rects.size(); ++i) {
    min_left = std::min(min_left, rects[i].left);
    min_top = std::min(min_top, rects[i].top);
    max_right = std::max(max_right, rects[i].right);
    max_bottom = std::max(max_bottom, rects[i].bottom);
  }
  return Rectangle(min_left, min_top, max_right, max_bottom);
}

int main() {
  // пересекающиеся прямоугольники
  std::vector<Rectangle> rects1 = {
    Rectangle(10, 10, 50, 50),
    Rectangle(30, 30, 70, 70)
  };
  int area1 = IntersectionArea(rects1);
  assert(area1 == 400);
  Rectangle bbox1 = BigRectangle(rects1);
  assert(bbox1.left == 10 && bbox1.top == 10 && bbox1.right == 70 && bbox1.bottom == 70);

  // непересекающиеся прямоугольники
  std::vector<Rectangle> rects2 = {
    Rectangle(10, 10, 30, 30),
    Rectangle(50, 50, 70, 70)
  };
  int area2 = IntersectionArea(rects2);
  assert(area2 == 0);
  Rectangle bbox2 = BigRectangle(rects2);
  assert(bbox2.left == 10 && bbox2.top == 10 && bbox2.right == 70 && bbox2.bottom == 70);

  // пустой вектор
  std::vector<Rectangle> rects3;
  int area3 = IntersectionArea(rects3);
  assert(area3 == 0);
  Rectangle bbox3 = BigRectangle(rects3);
  assert(bbox3.IsEmpty());
}