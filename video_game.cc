#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n, h;
  cin >> n >> h;

  vector<int> arr(n);

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  
  int x, cranePos;
  bool hasBox = false;
  cranePos = 0;
  cin >> x;
  while (x != 0) {
    if (x == 1 && cranePos > 0) {
      --cranePos;
    } else if (x == 2 && cranePos < n - 1) {
      ++cranePos;
    } else if (x == 3 && arr[cranePos] > 0 && !hasBox) {
      hasBox = true;
      --arr[cranePos];
    } else if (x == 4 && arr[cranePos] < h && hasBox) {
      hasBox = false;
      ++arr[cranePos];
    }
    cin >> x;
  }
  
  int i;
  for (i = 0; i < n - 1; ++i) {
    cout << arr[i] << " ";
  }
  cout << arr[i];
}
