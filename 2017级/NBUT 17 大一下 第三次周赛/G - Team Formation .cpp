/*
有n个数，从这n个数中任选两个数a,b，问有多少组数满足a^b > max(a, b)。

思路
1.异或运算，使用^会爆，想到二进制；
2.我们可以试着从前往后模拟一位一位的^那么只要当前位结果变大便是；
3.一般我们如何利用二进制呢？既然要爆那我们就存1的位置；
4.问题是怎么存，如何用？
5.我之前想的是每个数的每位1都存，但是那样造成的重复计算还没想出怎么避免。看了一下别人的博客，再尝试把每位数的最高位1存起来。
6.想想为什么是存最高位呢； 
7.那好，现在是不是把所有的高1都存好了，然后我们up(1,n)把原本要和剩余数做异或的步骤变为和bin[]运算。
我们要的是变得比max{A,B}大。那么先看变大，那就要找大一点的那个数，这个时候我们不是和数比较，而是和剩余数的最高位比较。
注意我们要能想到，是以暴力的方法推移过去，做的优化，也就是说每次只要加上可以和这个队伍完成的数目就好了。
注意这样不会有重复（类似A and B,B and A),不会这样。因为有没有发现，每次都是一遍历的这个数为max{A,B}。
注意我们是一位一位往后移，直到吧0->1。 
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <algorithm>

using namespace std;

#define N 100010

typedef long long ll;

// mp[i], number >= 2^i && < 2^(i+1)
ll num[N], mp[40];

ll get2(ll n)
{
    int res = 0;
    while (n) {
        n >>= 1;
        ++res;
    }
    return res - 1;
}

int main(void)
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &num[i]);
        }
        sort(num, num + n);
        memset(mp, 0, sizeof(mp));
        for (int i = 0; i < n; ++i) {
            int idx = get2(num[i]);
            mp[idx]++;
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            int a = num[i];
            int m = 0;
            while (a) {
                if ((a & 1) == 0) {
                    ans += mp[m];
                    //printf("%d...\n", mp[m]);
                }
                a >>= 1;
                ++m;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}