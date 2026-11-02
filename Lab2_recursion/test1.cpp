#include <iostream>
#include <string>
using namespace std;

int sumTo(int n){
    cout<<"enter sumTo("<<n<<")"<<endl;
    if(n==0){
        cout<<"base case: return 0"<<endl;
        return 0;
    }
    int result = n+sumTo(n-1);
    cout << "sumTo("<<n<<") returns " <<result <<endl;
    return result;
}

int main(){
    int total=sumTo(100000);
    cout<<"total= "<<total<<endl;
    return 0;
}