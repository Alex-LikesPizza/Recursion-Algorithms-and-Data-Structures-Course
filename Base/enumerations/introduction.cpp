#include <iostream>

using namespace std;

int main(){

  // enum {Red, Green, Blue};
  // cout << Red << " " << Green << " " << Blue << endl; // 0, 1, 2

  // enum {Red = 1, Green, Blue = 9, Yellow};
  // cout << Red << " " << Green << " " << Blue << " " << Yellow << endl; // 1, 2, 9, 10

  // enum Color {Red, Green, Blue};
  // Color colors {Red};
  // colors = Green; // ok
  // // colors = 2; // Error. Color type accepts ony it's own values 

  enum class Colors {Red, Green, Yellow};
  enum class Favorite_Things{Lemons, Grapes, Yellow};
  // cout << boolalpha << (Colors::Yellow == Favorite_Things::Yellow) << endl; // Error
  return 0;
}