#include <iostream>
#include <string>
using namespace std;

void reverse(string &s,int st,int end){
    char ch[end - st + 1];
    int len = end - st + 1;
    for(int i=0;i<len;i++){
        ch[i] = s[end - i];
    }
    for(int i=0;i<len;i++){
        s[st + i] = ch[i];
    }
    return;
}

void reverseWord(string &s){
    int pt=0,i=0;
    for(i=0;i<=s.length();i++){
        if(s[i]==' ' || s[i]=='\0'){
            reverse(s,pt,i-1);
            pt = i+1;
        }
    }
}

int main(){
    string s;
    getline(cin,s);
    reverseWord(s);
    cout<<s<<endl;
}