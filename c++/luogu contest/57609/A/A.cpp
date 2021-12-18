#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <bitset>
using namespace std;
#define ll long long
int one[39];
int two[39];
int res[39];
int now[39];
int lenRes;
int digit(ll x)
{
    if (x == 0)
        return 1;
    int ans = 0;
    while (x > 0)
    {
        ans++;
        x /= 10;
    }
    return ans;
}
void gen(ll x, int *a)
{
    for (int i = digit(x); i >= 1; i--)
    {
        a[i] = (int)(x % 10);
        x /= 10;
    }
}
void add(int a[], int b[], int lenOne, int lenTwo, int *ans)
{
    for (int i = 1; i <= max(lenOne, lenTwo); i++)
    {
        ans[lenRes] = a[i] + b[i];
        lenRes++;
    }

    for (int i = 1; i <= lenRes; i++)
    {
        if (ans[i] > 9)
        {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            if (i + 1 > lenRes - 1)
            {
                lenRes++;
            }
        }
    }
}
int cmp (int *a,int *b,int len) {

}
string binr(int *a)
{
    int solo = pow(2, lenRes);
    while (solo!=1){
        gen(solo,now);
    }
}
int main()
{
    ll T, x, y;
    cin >> T;
    while (T--)
    {
        memset(one, 0, sizeof(one));
        memset(two, 0, sizeof(two));
        cin >> x >> y;
        x *= 5;
        gen(x, one);
        gen(y, two);
        add(one, two, digit(x), digit(y), res);
        cout << binr(res) << endl;
    }

    system("pause");
    return 0;
}