#include <iostream>
#include <string>
using namespace std;

long long sumTo(long long n){
    cout<<"enter sumTo("<<n<<")"<<endl;
    if(n==0){
        cout<<"base case: return 0"<<endl;
        return 0;
    }
    long long result = n+sumTo(n-1);
    cout << "sumTo("<<n<<") returns " <<result <<endl;
    return result;
}

int main(){
    long long total=sumTo(3);
    cout<<"total= "<<total<<endl;
    return 0;
}