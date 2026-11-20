#include <iostream>
using namespace std;

long long mults = 0;
long long calls = 0;

long long factorialIter(long long n) {
    calls++;
    long long result = 1;

    for (long long i = 2; i <= n; i++) {
        result = result * i;
        mults++;
    }

    return result;
}
long long factorialRec(long long n) {
    calls++;

    if (n == 0) return 1; // base case
        mults++;

    return n * factorialRec(n - 1); // recursive case
}
long long main() {
    long long n;
    cout << "Enter n: ";
    cin >> n;

    mults = 0; calls = 0;
    long long f1 = factorialIter(n);
    cout << "Iterative: " << n << "! = " << f1
    << ", multiplications = " << mults << ", calls = " << calls << endl;

    mults = 0; calls = 0;
    long long f2 = factorialRec(n);
    cout << "Recursive: " << n << "! = " << f2
    << ", multiplications = " << mults << ", calls = " << calls << endl;
    
    return 0;
} 
