#include <vector>
using namespace std;

int gcdExtended(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

int modInverse(int a, int m) {
    int x, y;
    int g = gcdExtended(a, m, x, y);
    if (g != 1)
        return -1;
    return (x % m + m) % m;
}

int chineseRemainderTheorem(const vector<int>& a, const vector<int>& m) {
    int k = a.size();
    int M = 1;
    for (int i = 0; i < k; ++i) {
        M *= m[i];
    }

    int result = 0;
    for (int i = 0; i < k; ++i) {
        int Mi = M / m[i];
        int inv = modInverse(Mi, m[i]);
        if (inv == -1)
            return -1;
        result += a[i] * Mi * inv;
    }

    return (result % M + M) % M;
}
