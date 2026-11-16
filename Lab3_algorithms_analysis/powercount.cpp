#include <iostream>
using namespace std;


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

    mults = 0; 
    calls = 0;
    long long p1 = powerLinear(x, n);
    cout << "Linear: " << x << "^" << n << " = " << p1
    << ", multiplications = " << mults << ", calls = " << calls << endl;

    mults = 0; 
    calls = 0;
    long long p2 = powerFast(x, n);
    cout << "Fast: " << x << "^" << n << " = " << p2
    << ", multiplications = " << mults << ", calls = " << calls << endl;

    return 0; 
}