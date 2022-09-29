#include <bits/stdc++.h>
using namespace std;

#define MAXN 89
#define int1 __int128
int n, m;
int num[MAXN];
int1 ans, p[MAXN], f[MAXN][MAXN];

int1 dp(int L, int R)
{
    if (f[L][R] != -1)
        return f[L][R];
    if (R - L >= 1)
        f[L][R] = max(num[L] * p[m - (R - L)] + dp(L + 1, R), dp(L, R - 1) + num[R] * p[m - (R - L)]);
    else
        f[L][R] = num[L] * p[m - (R - L)];
    return f[L][R];
}

void print(int1 x)
{
    if (!x)
    {
        cout << endl;
        return;
    }
    if (x)
        print(x / 10);
    putchar(x % 10 + '0');
}

int main()
{
    cin >> n >> m;
    p[0] = 1;
    for (int i = 1; i <= m; i++)
        p[i] = p[i - 1] * 2;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> num[j];
        memset(f, 0, sizeof(f));
        ans += dp(1, m);
    }
    if (!ans)
        cout << 0 << endl;
    else
        print(ans), cout << endl;

    return 0;
}
