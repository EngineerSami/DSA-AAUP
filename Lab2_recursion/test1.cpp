#include <iostream>
#include <string>
using namespace std;

Long Long sumTo(Long Long n){
    cout<<"enter sumTo("<<n<<")"<<endl;
    if(n==0){
        cout<<"base case: return 0"<<endl;
        return 0;
    }
    Long Long result = n+sumTo(n-1);
    cout << "sumTo("<<n<<") returns " <<result <<endl;
    return result;
}

Long Long main(){
    Long Long total=sumTo(100000);
    cout<<"total= "<<total<<endl;
    return 0;
}