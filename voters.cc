#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;
int main()
{
  int n1, n2, n3;
  cin >> n1 >> n2 >> n3;

  map<int, int> m;

  int x;
  for (int i = 0; i < n1; ++i) {
    cin >> x;
    m[x]++;
  }


  for (int i = 0; i < n2; ++i) {
    cin >> x;
    m[x]++;
  }

  for (int i = 0; i < n3; ++i) {
    cin >> x;
    m[x]++;
  }
  
  int count = 0;
  stringstream s;
  map<int, int>::iterator it;
  for (it = m.begin(); it != m.end(); ++it){
    if (it->second > 1) {
      s << it->first << endl;
      ++count;
    }
  }
  cout << count << "\n" << s.str();
}
