#include <iostream>
using namespace std;

// 1
// 2*2
// 3*3*3
// 4*4*4*4
// 5*5*5*5*5

int main() {

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 2 * i; j++) {
      if (j % 2 == 0)
        cout << i + 1;
      else
        cout << "*";
    }

    cout << endl;
  }
}