#include <iostream>
#include <cstddef>
template<typename T, std::size_t N>

class Array{
  friend std::ostream& operator<<(std::ostream& os, const Array<T, N>& arr){
    os << "[ ";
    for (std::size_t i = 0; i < N; ++i) {
      os << arr.arr[i] << " ";
    }
    os << "]" << std::endl;
    return os;
  }

  private:
    T arr[N] {};

  public:
    std::size_t size(){
      return N;
    }
    T& operator[](std::size_t i){
      return arr[i];
    }

    Array() = default;
};

int main(){
  Array<int, 5> prices;
  prices[0] = 10;
  prices[1] = 20;
  prices[2] = 15;

  std::cout << prices;

  return 0;
}