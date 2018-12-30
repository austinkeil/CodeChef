#include <iostream>
using namespace std;

int Collatz(int n) {
    if (n == 1)
        return 0;
    else if (n % 2 == 0)
        return 1 + Collatz(n / 2);
    else
        return 1 + Collatz(3 * n + 1);
}

int main() {
    int n;
    cout << "This program calculates Collatz(n).\n" << endl;
    cout << "Enter n or -1 to quit: ";
    cin >> n;
    while (n != -1) {
        cout << "Collatz(" << n << ") = " << Collatz(n) << endl;
        cout << "Enter n or -1 to quit: ";
        cin >> n;
    }
}