#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class data {
public:
    int a, b, c;
    int sum;
};

bool f(data i, data j) {
    return i.sum > j.sum;
}

int main()
{
    int n;
    cin >> n;

    vector<data> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i].a >> v[i].b >> v[i].c;
        v[i].sum = v[i].b + v[i].c;
    }

    sort(v.begin(), v.end(), f);

    int crucial = v[0].a;
    int other = v[0].sum;
    for (int i = 1; i < n; ++i) {
        crucial += v[i].a;
        other = max(other-v[i].a, v[i].sum);
    }
    cout << crucial + other;
}