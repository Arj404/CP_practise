#include <iostream>
using namespace std;

int hcf(int a, int b)
{
    if(a==b){
        return a;
    }
    else{
        if(a>b){
            return hcf(a-b,b);
        }
        else{
            return hcf(a,b-a);
        }
    }
}

int lcm(int a, int b){
    return (a*b)/hcf(a,b);
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<"LCM  : "<<lcm(a,b)<<endl;
    cout<<"HCF  : "<<hcf(a,b)<<endl;
    return 0;
}