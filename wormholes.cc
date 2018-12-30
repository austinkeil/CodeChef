#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<pair<int, int> > tests;
    vector<int> v, w;
    int t1, t2;
    for (int i = 0; i < n; ++i) {
        cin >> t1 >> t2;
        tests.push_back(make_pair(t1, t2));
    }

    string s;
    getline(cin, s);    // gets the leftover space
    getline(cin, s);    // gets the line

    // store v-times into vector v
    stringstream ss(s);
    string token;
    while (ss >> token) {
        v.push_back(stoi(token));
    }

    // store w-times into vector w
    getline(cin, s);
    ss.clear();
    ss.str(s);
    while(ss >> token) {
        w.push_back(stoi(token));
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
        int latestT1 = -1;
        for (int i = 0; v[i] <= tests[testNdx].first && i < v.size(); ++i) {
            latestT1 = v[i];
        }

        // if no v portals will get you there on time for this test, skip to next test
        if (latestT1 == -1)
            continue;

        // find the earliest t2 after test ends
        int earliestT2 = -1;
        int i = 0;
        while (w[i] < tests[testNdx].second && i < w.size()) {
            ++i;
        }

        // if no v portals will get you home after the test, skip to next test
        if (i == w.size())
            continue;

        earliestT2 = w[i];
        int diff = earliestT2 - latestT1;
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    cout << minDiff + 1;
}