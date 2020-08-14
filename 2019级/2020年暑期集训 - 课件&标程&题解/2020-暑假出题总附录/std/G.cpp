#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <string>
#include <map>
#include <set> 
#include <queue> 
#define ll long long
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
ll t, n;
int main() 
{
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        if(n == 1) printf("26\n");
        else if(n == 2) printf("676\n");
        else if(n == 3) printf("17576\n");
        else printf("15600\n");
    }
    return 0;
}
