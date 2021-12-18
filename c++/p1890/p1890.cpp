#include <cstdio>
#include <algorithm>
#define Mid ((l + r) >> 1)
#define lc p << 1
#define rc p << 1 | 1
using namespace std;
int n, m;
int a[1009];
int tree[1009 << 2];
void pushup(int p)
{
    tree[p] = __gcd(tree[lc], tree[rc]);
}
void build(int p, int l, int r)
{
    if (l == r)
    {
        tree[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushup(p);
}
int query(int p, int l, int r, int L, int R)
{
    if (L <= l && r <= R)
    {
        return tree[p];
    }
    else
    {
        int tmp = 0;
        if (L <= Mid)
            tmp = query(lc, l, Mid, L, R);
        if (R > Mid)
            tmp = __gcd(tmp, query(rc, Mid + 1, r, L, R));
        return tmp;
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", query(1, 1, n, x, y));
    }
    system("pause");

    return 0;
}