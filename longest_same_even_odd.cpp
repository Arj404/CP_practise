#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n<=2){
        cout<<n<<endl;
    }
    else{
        int max,ans;
        ans=2;
        max=2;
        for(int i=2;i<n;i++){
            if(a[i]==a[i-2]){
                max++;
            }
            else{
                max=2;
            }
            if(max>ans){
                ans = max;
            }
        }
        cout<<ans<<endl;
    }
}