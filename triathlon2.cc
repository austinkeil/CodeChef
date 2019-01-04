#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool f(pair<int, int> i, pair<int, int> j) {return i.second > j.second;}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int> > v(n);
    int a, b, c;
    for(int i = 0; i < n; ++i) {
        cin >> a >> b >> c;
        v[i] = make_pair(a, b+c);
    }
    sort(v.begin(), v.end(), f);

    int total = 0;
    for (int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            v[j].second = v[j].second - v[i].first;
        }
    }

    int longest = 0;
    for (int i = 0; i < n; ++i) {
        total += v[i].first;
        if (v[i].second > longest){
            longest = v[i].second;
        }
    }

    cout << total + longest;
}