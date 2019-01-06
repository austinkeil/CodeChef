#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;

    queue<ll> q1, q2;

    ll arr[n];
    for (int i=0; i<n; ++i) {
        cin >> arr[i];
    }

    sort(arr, arr+n);
    for (int i=n-1; i>=0; --i)
        q1.push(arr[i]);

    int x, count = 1;
    while (m--) {
        cin >> x;
        ll lastTop;
        for (; count<=x; ++count) {
            if (q1.front() >= q2.front()){
                lastTop = q1.front();
                q1.pop();
            } else {
                lastTop = q2.front();
                q2.pop();
            }
            q2.push(lastTop>>1);
        }
        cout << lastTop << endl;
    }
}