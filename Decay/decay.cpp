#include <iostream>
#include <type_traits>

template <typename T>
T add_value(T value) {
  return value + T{1};
}

template <typename T>
using decayed_type = std::decay_t<T>;

int main() {
  const int num = 5;
  volatile double pi = 3.14;
  int arr[3] = {1, 2, 3};
  auto lambda = [](int x) -> int { return x * 2; };

  std::cout << add_value(*num) << std::endl; // prints 6
  std::cout << add_value(pi) << std::endl; // prints 4.14
  std::cout << add_value(arr) << std::endl; // prints "0x7ffeefbff5f8", the address of the first element in arr
  std::cout << add_value(lambda) << std::endl; // prints "error: no matching function for call to 'add_value'
}

