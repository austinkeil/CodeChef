#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int count = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n-1; ++i) {
        int j;
        for (j = i+1; j < n; ++j) {
            if (abs(arr[i] - arr[j]) >= k) {
                count += (n-j);
                break;
            }
        }
        if (j == n) {
            break;
        }
    }
    cout << count;
}