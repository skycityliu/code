#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
int f[5009][5009], g[5009][5009], peo[5009][5009], comp[5009][5009];
int main()
{
    int n, seed, solo = 0;
    cin >> n >> seed;

    srand(seed);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            f[i][j] = j;
        random_shuffle(f[i] + 1, f[i] + 1 + n);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            g[i][j] = j;
        random_shuffle(g[i] + 1, g[i] + 1 + n);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            peo[i][f[i][j]] = j;
            comp[i][g[i][j]] = j;
        }
    }
    while (solo<n){
        for (int i = 1; i <= n; i++) {
            
        }
    }

    system("pause");
    return 0;
}