#include <iostream>
using namespace std;

int pattern(int n) {
  // 1
  // 2*2
  // 3*3*3
  // 4*4*4*4
  // 5*5*5*5*5
  // 5*5*5*5*5
  // 4*4*4*4
  // 3*3*3
  // 2*2
  // 1

  for (int row = 1; row <= n; row++) {
    for (int col = 1; col <= row; col++) {
      if (row == col)
        cout << row;
      else
        cout << row << "*";
    }

    cout << endl;
  }

  for (int row = n; row >= 1; row--) {
    for (int col = 1; col <= row; col++) {
      if (row == col)
        cout << row;
      else
        cout << row << "*";
    }

    cout << endl;
  }

  return 0;
}

int pattern1(int n) {
  // 1
  // 2*2
  // 3*3*3
  // 4*4*4*4
  // 5*5*5*5*5
  // 5*5*5*5*5
  // 4*4*4*4
  // 3*3*3
  // 2*2
  // 1

  for (int row = 1; row <= 2 * n; row++) {

    for (int col = 1; col <= n; col++) {

      if (row <= n) {
        if (col < row)
          cout << row << "*";
        else if (col == row)
          cout << row;
      } else {
        if (col < 2 * n - row + 1)
          cout << 2 * n - row + 1 << "*";
        else if (col == 2 * n - row + 1)
          cout << 2 * n - row + 1;
      }
    }

    cout << endl;
  }

  return 0;
}

int main() {

  int n;
  cin >> n;

  // pattern(n);
  pattern1(n);
}