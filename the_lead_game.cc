#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int n;
  cin >> n;

  int p1_total=0, p2_total=0, leader, max_lead = 0;
  for (int i = 0; i < n; ++i) {
    int s1, s2;
    cin >> s1 >> s2;
    p1_total += s1;
    p2_total += s2;
    int diff = p1_total - p2_total;
    if (abs(diff) > max_lead) {
      max_lead = abs(diff);
      if (diff >= 0){
        leader = 1;
      } else {
        leader = 2; 
      }
    }
  }
  cout << leader << " " << max_lead << endl;
}
