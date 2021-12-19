#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int MAXN = 100005;
ll n, m;
ll a[MAXN];
ll sum[MAXN * 4];
ll tag[MAXN * 4];
inline ll lc(ll p) { return p << 1; }
inline ll rc(ll p) { return p << 1 | 1; }
void pushUp(ll p)
{
    sum[p] = sum[lc(p)] + sum[rc(p)];
}
void buildTree(ll p, ll l, ll r)
{
    if (l == r)
    {
        sum[p] = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    buildTree(lc(p), l, mid);
    buildTree(rc(p), mid + 1, r);
    pushUp(p);
}
void moveTag(ll p, ll l, ll r, ll t)
{
    sum[p] += t * (r - l + 1);
    tag[p] += t;
}
void pushDown(ll p, ll l, ll r)
{
    ll mid = (l + r) >> 1;
    moveTag(lc(p), l, mid, tag[p]);
    moveTag(rc(p), mid + 1, r, tag[p]);
    tag[p] = 0;
}
void update(ll p, ll l, ll r, ll ql, ll qr, ll d)
{
    if (ql <= l && r <= qr)
    {
        sum[p] += d * (r - l + 1);
        tag[p] += d;
        return;
    }
    pushDown(p, l, r);
    ll mid = (l + r) >> 1;
    if (ql <= mid)
    {
        update(lc(p), l, mid, ql, qr, d);
    }
    if (mid < qr)
    {
        update(rc(p), mid + 1, r, ql, qr, d);
    }
    pushUp(p);
}
ll query(ll p, ll l, ll r, ll ql, ll qr)
{
    if (ql <= l && r <= qr)
    {
        return sum[p];
    }
    pushDown(p, l, r);
    ll mid = (l + r) >> 1;
    ll result = 0;
    if (ql <= mid)
    {
        result += query(lc(p), l, mid, ql, qr);
    }
    if (mid < qr)
    {
        result += query(rc(p), mid + 1, r, ql, qr);
    }
    return result;
}

int main () {


    system("pause");
    return 0;
}