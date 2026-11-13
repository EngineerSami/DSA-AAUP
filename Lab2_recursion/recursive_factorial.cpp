#include <iostream>
#include <string>
using namespace std;

long long factiter(long long n) {
    long long result = 1;
    for (long long i = 2; i <= n; i++) {
        result = result * i;
    }
    return result;
}

long long factrec(long long n) {
    if (n == 0) return 1;
    return n * factrec(n - 1);
}

int main() {
    for (long long n = 0; n <= 15; n++) {
        cout << n << "! = " << factrec(n);
        cout << "loop: " << factiter(n) << " for n = " << n;
        cout << endl;
    }
    return 0;
}