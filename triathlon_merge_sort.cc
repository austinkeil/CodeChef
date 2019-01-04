#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<pair<int, int> > &v, int p, int q, int r) {
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<pair<int, int> > L(v.begin(), v.begin() + n1);
    vector<pair<int, int> > R(v.begin() + n1, v.begin() + n2);

    i = j = 0;

    for (k = p; k < r; ++k) {
        if (L[i].second < R[j].second) {
            v[k] = L[i];
            RL[i].first
        }

    }

}

void mergesort(vector<pair<int, int> > &v, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergesort(v, p, q);
        mergesort(v, q+1, r);
        merge(v, p, q, r);
    }
}

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
        1 100
        10 10
    }
}