#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int maxNestDepth = 0, maxNestStart = 0;
    int maxLength = 0, maxLengthStart = 0;

    int curNestDepth = 0, curNestStart = 0;
    int curLength = 0, curLengthStart = 0;

    int x;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (x == 1) {
            if (curLength == 0) {
                curLengthStart = i;
            }
            ++curNestDepth;
            curNestStart = i;
            if (curNestDepth > maxNestDepth) {
                maxNestDepth = curNestDepth;
                maxNestStart = curNestStart;
            }
            ++curLength;
        }
        if (x == 2) {
            --curNestDepth;
            ++curLength;
            if (!curNestDepth) {
                if (curLength > maxLength) {
                    maxLength = curLength;
                    maxLengthStart = curLengthStart;
                }
                curLength = 0;
            }
        }
    }

    cout << maxNestDepth << " " << maxNestStart << " " << maxLength << " " << maxLengthStart;
}