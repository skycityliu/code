#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int a[200009], tree[200009 << 2];
inline int lc(int p) { return p << 1; }
inline int rc(int p) { return p << 1 | 1; }
void pushup(int p)
{
    tree[p] = max(tree[lc(p)], tree[rc(p)]);
}
void build(int p, int l, int r)
{
    if (l == r)
    {
        tree[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lc(p), l, mid);
    build(rc(p), mid + 1, r);
    pushup(p);
}
void change(int p, int l, int r, int ql, int qr)
{
    if (l == r)
    {
        if (tree[p] < qr)
            tree[p] = qr;
        return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid)
        change(lc(p), l, mid, ql, qr);
    else
        change(rc(p), mid + 1, r, ql, qr);
    pushup(p);
}
int query(int p, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
        return tree[p];
    int mid = (l + r) >> 1, ans = -1e9;
    if (ql <= mid)
        ans = max(ans, query(lc(p), l, mid, ql, qr));
    if (qr > mid)
        ans = max(ans, query(rc(p), mid + 1, r, ql, qr));
    return ans;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        char ope[100];
        int ql, qr;
        scanf("%s%d%d", ope, &ql, &qr);
        if (ope[0] == 'Q')
            printf("%d\n", query(1, 1, n, ql, qr));
        else
            change(1, 1, n, ql, qr);
    }
    system("pause");

    return 0;
}