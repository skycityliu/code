#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
const int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
const int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
struct Node
{
    int x, y;
} din[69];
int top;
bool vis[9][9],flag;
char a[9][9];
int sx, sy, tx, ty, ans;
void dfs(int x, int y, Node arr[])
{
    int nx, ny;
    for (int i = 0; i < 8; i++)
    {
        nx=x+dx[i];
        ny=y+dy[i];

    }
}
int main()
{
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            scanf("%s", a[i][j]);
            if (a[i][j] == 'A')
                tx = i, ty = j;
            if (a[i][j] == 'M')
                sx = i, sy = j;
            if (a[i][j] == 'S')
            {
                din[top].x = i, din[top].y = j;
            }
        }
    }
    vis[sx][sy] = true;
    dfs(sx, sy, din);
    if (flag) printf("WIN");
    else printf("LOSE");

    system("pause");
    return 0;
}