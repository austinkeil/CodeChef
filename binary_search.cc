#include <vector>
#include <iostream>

using namespace std;

// returns position of x in sorted container arr, otherwise -1
template <class T, class U>
int binary_search(T arr, U l, U r, U x) {
    U mid = (l + r) / 2;
    if (x == arr[mid])
        return mid;
    else if (x < arr[mid] && l < mid)
        return binary_search(arr, l, mid-1, x);
    else if (x > arr[mid] && r > mid)
        return binary_search(arr, mid + 1, r, x);
    else
        return -1;
}

// tests the binary_search template function
int main()
{
    vector<int> a = {1, 3, 7, 13, 20, 31, 40};
    int b[7] = {1, 4, 8, 19, 23, 31, 50};
    cout << binary_search(a, 0, int(a.size()-1), 40) << endl;
    cout << binary_search(b, 0, 6, 3) << endl;

}