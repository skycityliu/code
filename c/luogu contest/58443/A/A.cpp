#include <iostream>
#include <cstdio>
using namespace std;
int n, m, a[200009];
struct node
{
    int one, l, r, len;
    bool lazy;
} t[200009 << 2];
inline int lc(int p) { return p << 1; }
inline int rc(int p) { return p << 1 | 1; }
void build(int p, int l, int r)
{
    t[p].l = l, t[p].r = r;
    t[p].lazy = false;
    if (l == r)
    {
        t[p].one = a[l] ? 1 : 0;
        t[p].len = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(lc(p), l, mid);
    build(rc(p), mid + 1, r);
    t[p].one = t[lc(p)].one + t[rc(p)].one;
    t[p].len = t[lc(p)].len + t[rc(p)].len;
}
void spread(int p)
{
    if (!t[p].lazy)
        return;
    t[lc(p)].one = t[lc(p)].len - t[lc(p)].one;
    t[rc(p)].one = t[rc(p)].len - t[rc(p)].one;

    t[lc(p)].lazy = !t[lc(p)].lazy;
    t[rc(p)].lazy = !t[rc(p)].lazy;
    t[p].lazy = false;
}
void change(int p, int l, int r)
{
    if (t[p].l >= l && t[p].r <= r)
    {
        t[p].lazy = !t[p].lazy;
        t[p].one = t[p].len - t[p].one;
        return;
    }
    spread(p);
    t[p].one = t[p * 2].one + t[p * 2 + 1].one;
    int mid = (t[p].l + t[p].r) >> 1;
    if (l <= mid)
        change(lc(p), l, r);
    if (mid < r)
        change(rc(p), l, r);
    t[p].one = t[p * 2].one + t[p * 2 + 1].one;
}
int ask(int p, int l, int r)
{
    if (l <= t[p].l && t[p].r <= r)
    {
        return t[p].one;
    }
    spread(p);
    int ans = 0;
    int mid = (t[p].l + t[p].r) >> 1;
    if (l <= mid)
        ans = ans + ask(lc(p), l, r);
    if (mid < r)
        ans = ans + ask(rc(p), l, r);
    return ans;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        a[i] = c - '0';
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int op;
        scanf("%d", &op);
        if (op == 0)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            if (l <= r)
                change(1, l, r);
            else
            {
                change(1, l, n);
                change(1, 1, r);
            }
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            if (l <= r)
            {
                printf("%d\n", ask(1, l, r));
            }
            else
                printf("%d\n", ask(1, l, n) + ask(1, 1, r));
        }
    }

    system("pause");
    return 0;
}