#include <iostream>
using namespace std;

// pyramid
//     *
//    * *
//   * * *
//  * * * *
// * * * * *

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i; j++)
      cout << " "; // print spaces
    for (int j = 1; j <= i; j++)
      cout << "* "; // print starts with space
    cout << endl;
  }
  return 0;
}