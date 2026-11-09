#include <iostream>
#include <string>
using namespace std;

long long ops = 0;

long long sumToRec(int n){
    if (n==0) return 1;
    ops++;
    return n * sumToRec(n-1);
    
}

long long sumToIter(int n){
    long long total = 1;
    for (int i = 1; i <= n; i++)
    {
        total=total*i;
        ops++;
    }
    return total;
    
}

int main() {
    int n;
    cout<<"Enter N = ";
    cin>>n;
    cout<<endl;

    ops=0;
    long long s1=sumToRec(n);
    cout<<s1<<" "<<n<<endl;

    ops=0;
    long long s2=sumToIter(n);
    cout<<s2<<" "<<n<<endl;
    return 0;
}