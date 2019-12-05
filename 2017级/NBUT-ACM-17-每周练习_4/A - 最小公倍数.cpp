#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main(){
    int a,b;
    while(cin>>a>>b){
        cout<<a/gcd(a,b)*b<<endl;
    }
    return 0;
}

//a*b/gcd(a,b)  可能会发生 a*b 超出数据范围而导致runtime error 
