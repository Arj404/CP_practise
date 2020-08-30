#include<iostream>
using namespace std;

float minu(float a, float b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}

float angle(int h,int m){
    if(h<0 || m<0 || h>12 || m>60){
        return -1;
    }
    if(h == 12){
        h = 0;
    }
    if(m == 60){
        m=0;
        h++;
        if(h>12){
            h=h-12;
        }
    }
    float min,hr,angle;
    min = m*6;
    hr = (h*60 + m)*0.5;
    angle = min-hr;
    if(angle<0){
        angle = angle*-1;
    }
    return minu(angle,360-angle);
}

int main(){
    int h,m;
    cin>>h>>m;
    cout<<angle(h,m)<<endl;
}