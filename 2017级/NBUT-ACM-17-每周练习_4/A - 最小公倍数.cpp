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

//a*b/gcd(a,b)  ���ܻᷢ�� a*b �������ݷ�Χ������runtime error 
