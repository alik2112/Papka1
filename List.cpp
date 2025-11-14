#include <iostream>
#include <cassert>
class List {
private:
  struct Node {
    int value;
    Node* next;
    Node(int x) : value(x), next(nullptr) {}
  };
  Node* tail;
  Node* head;
public:
  List(): tail(nullptr), head(nullptr) {}
  ~List() {
    while (!empty()) {
      pop_front();
    }
  }
  bool empty() const {
    return (head == nullptr);
  }
  void show() const {
    Node* ptr = head;
    while (ptr != nullptr) {
      std::cout << ptr->value << " ";
      ptr = ptr->next;
    }
    std::cout << '\n';
  }
  void push_back(int val) {
    Node* k = new Node(val);
    if (empty()) {
      head = k;
      tail = k;
    } else {
      tail->next = k;
      tail = k;
    }
  }
  void pop_back() {
    if (empty()) {
      return;
    }
    if (head == tail){
      delete head;
      head = nullptr;
      tail = nullptr;
    } else {
      Node* curr = head;
      while (curr->next != tail){
        curr = curr->next;
      }
      curr->next = nullptr;
      delete tail;
      tail = curr;
    }
  } 
  void push_front(int val) {
    Node* k = new Node(val);
    if (empty()) {
      head = k;
      tail = k;
    } else {
      k->next = head;
      head = k;
    }
  }
  void pop_front() {
    if (empty()) {
      return;
    }
    if (head == tail) {
      delete head;
      head = nullptr;
      tail = nullptr;
    } else {
      Node* k = head->next;
      delete head;
      head = k;
    }
  }
  int get() const {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr){
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow->value;
  }
};

int main() {
  List list1;
  assert(list1.empty() == true);
  ////////////////////
  List list2;
  list2.push_back(1);
  list2.push_back(2);
  list2.push_back(3);
  list2.push_back(4);
  list2.push_back(5);
  assert(list2.get() == 3);
  ////////////////////
  List list3;
  list3.push_back(10);
  list3.push_back(20);
  list3.push_back(30);
  list3.push_back(40);
  assert(list3.get() == 30);
  //////////////////////
  List list4;
  list4.push_front(3);
  list4.push_front(2);
  list4.push_front(1);
  list4.push_back(4);
  list4.push_back(5);
  // 1 2 3 4 5
  assert(list4.get() == 3);
  list4.pop_front();
  list4.pop_back();
  // 2 3 4
  assert(list4.get() == 3);
}