#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int N = 100009;
int n, m, head[N], cnt, ans[N];
struct node
{
    int nxt, to;
} e[N];
void add(int x, int y)
{
    e[++cnt].nxt = head[x];
    e[cnt].to = y;
    head[x] = cnt;
}
void dfs(int x, int fa)
{
    ans[x] = fa;
    for (int i = head[x]; i; i = e[i].nxt)
        if (!ans[e[i].to])
            dfs(e[i].to, fa);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(y, x);
    }
    for (int i = n; i >= 1; i--)
    {
        if (ans[i])
            continue;
        dfs(i, i);
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    printf("\n");

    system("pause");
    return 0;
}