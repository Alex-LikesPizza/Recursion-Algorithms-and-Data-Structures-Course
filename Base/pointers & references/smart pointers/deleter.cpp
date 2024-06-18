#include <iostream>
#include <memory>

using namespace std;

class Deleter{
  private:
    int data;
  public:
    Deleter(int data) : data(data){};
    ~Deleter(){
      cout << "Deleting " << data << endl;
    }
};

void deleterFunc(Deleter* ptr){
  cout << "Using custom deleter" << endl;
  delete ptr;
}

int main(){
  unique_ptr<Deleter, void(*)(Deleter*)> unq_ptr1 {new Deleter(1), deleterFunc};
  shared_ptr<Deleter> unq_ptr2 {new Deleter(2), deleterFunc};
}