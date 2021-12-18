#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, ans;
int f[100009];
void init(int x)
{
    for (int i = 0; i <= x + 5; i++)
    {
        f[i] = i;
    }
}
int getf(int x)
{
    if (x == f[x])
    {
        return x;
    }
    return f[x] = getf(f[x]);
}
bool check(int x, int y)
{
    int one = getf(x), two = getf(y);
    return one != two;
}
void merge(int x, int y)
{
    if (check(x, y))
        f[y] = getf(x);
}
int main()
{
    int T, u, v, solo, mid, omax = 1, nmax = n, s, t;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        init(n);
        solo = 1;
        ans = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            merge(u, v);
        }
        if (!check(1, n))
        {
            cout << 0 << endl;
            return 0;
        }
        s = getf(1), t = getf(n);
        for (int i = 1; i <= n; i++)
        {
            if (getf(i) == s){
                omax = max(omax, i);
                cout << omax << ' ' << i << "s\n";
            }
            if (getf(i) == t){
                nmax = min(nmax, i);
                cout << nmax << ' ' << i << "t\n";
            }
        }
        mid=(omax+nmax)>>1;
        cout << omax << ' ' << mid << ' ' << nmax << endl;
        cout << (omax-mid)*(omax-mid) + (nmax-mid-1)*(nmax-mid-1) << endl;
    }

    system("pause");
    return 0;
}