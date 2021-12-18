#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
struct Node
{
    int p, t;
} grass[200009];
ll eny[200009], ans;
int k, m, n;
bool cmp(Node x, Node y)
{
    return x.t > y.t;
}
int main()
{
    int solo;
    cin >> k >> n >> m;
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d", &grass[solo].p, &grass[solo].t);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &eny[i]);
    }
    sort(eny + 1, eny + n + 1);
    sort(grass, grass + k, cmp);
    for (double i = 0; i < k; i+=0.5)
    {  
        
    }

    system("pause");
    return 0;
}