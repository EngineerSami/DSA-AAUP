#include <iostream>
#include <string>
using namespace std;
int Sum(int count){
    int sum=0;
    for (int i = 0; i <= count; i++)
    {
        sum+=i;
    }
    return sum;
}

int main()
{

    
    int count;
        while (count != 0){
    
    cout<<"enter Count :";
    cin>>count;
    int sum = Sum(count);
    double average=double(sum)/count;

    cout<<"Sum= "<<sum<<endl;
    cout<<"Average= "<<average<<endl;
    }
    return 0;
}