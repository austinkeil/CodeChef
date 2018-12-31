#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int bs(vector<int> &arr, int l, int r, int x, bool t1) {
    int mid = (l + r) / 2;
    if (x == arr[mid]) {
        return mid;
    }
    else if (x < arr[mid]) {
        if (l < mid) {
            return bs(arr, l, mid - 1, x, t1);
        }
        else {
            if (t1) {
                return mid - 1;
            } else {
                return mid;
            }
        }
    } else if (x > arr[mid]) {
        if (r > mid) {
            return bs(arr, mid + 1, r, x, t1);
        }
        else {
            if (t1) {
                return mid;
            } else {
                return mid + 1;
            }
        }
    }
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<pair<int, int> > tests(n);
    vector<int> v(x), w(y);
    int t1, t2;
    for (int i = 0; i < n; ++i) {
        cin >> t1 >> t2;
        tests[i].first = t1;
        tests[i].second = t2;
    }

    for (int i = 0; i < x; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < y; ++i) {
        cin >> w[i];
    }

    sort(v.begin(), v.end());
    sort(w.begin(), w.end());

    int minDiff = 999999999;
    // for each test period
    for (int testNdx = 0; testNdx < n; ++testNdx) {
        // skip if test is already longer than our best time
        if (minDiff < tests[testNdx].second - tests[testNdx].first)
            continue;

        // find the latest t1 before test begins
        int latestT1 = bs(v, 0, v.size() - 1, tests[testNdx].first, true);

        // if no v portals will get you there on time for this test, skip to next test
        if (latestT1 == -1) {
            continue;
        } else
            latestT1 = v[latestT1];

        // find the earliest t2 after test ends
        int earliestT2 = bs(w, 0, w.size() - 1, tests[testNdx].second, false);

        // if no v portals will get you home after the test, skip to next test
        if (earliestT2 == w.size()) {
            continue;
        }
        else
            earliestT2 = w[earliestT2];

        int diff = earliestT2 - latestT1;
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    cout << minDiff + 1;
}