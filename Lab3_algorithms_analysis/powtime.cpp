#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

long long mults = 0;
long long calls = 0;

long long powerLinear(long long x, int n) {
    calls++;
    if (n == 0) return 1;
    mults++;
    return x * powerLinear(x, n - 1);
}

long long powerFast(long long x, int n) {
    calls++;
    if (n == 0) return 1;
    long long half = powerFast(x, n / 2);
    mults++;
    long long result = half * half;

    if (n % 2 == 1) {
        mults++;
        result = result * x;
    }
    return result;
}

int main() {
    long long x;
    int n;
    cout << "Enter x and n: ";
    cin >> x >> n;

    const int ITERATIONS = 1000000;
    volatile long long p1 = 0, p2 = 0;

    auto startLinear = steady_clock::now();
    for (int i = 0; i < ITERATIONS; i++) {
        mults = 0;
        calls = 0;
        p1 = powerLinear(x, n);
    }
    auto stopLinear = steady_clock::now();
    auto timeLinear = duration_cast<microseconds>(stopLinear - startLinear).count();

    cout << "Linear: " << x << "^" << n << " = " << p1
         << ", multiplications = " << mults << ", calls = " << calls
         << " | Total time (1M runs) = " << timeLinear << " us" << endl;

    auto startFast = steady_clock::now();
    for (int i = 0; i < ITERATIONS; i++) {
        mults = 0;
        calls = 0;
        p2 = powerFast(x, n);
    }
    auto stopFast = steady_clock::now();
    auto timeFast = duration_cast<microseconds>(stopFast - startFast).count();

    cout << "Fast: " << x << "^" << n << " = " << p2
         << ", multiplications = " << mults << ", calls = " << calls
         << " | Total time = " << timeFast << " us" << endl;

    return 0;
}