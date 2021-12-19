#include <iostream>
#include <cstdio>
using namespace std;
int sa[100009];
int sb[100009];
int n, ans;
int main()
{
    char c;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c;
        if (c == 'a')
            sa[i] = 1 + sa[i - 1], sb[i] = sb[i - 1];
        else
            sb[i] = 1 + sb[i - 1], sa[i] = sa[i - 1];
    }
    for (int l = 1; l <= n; l++)
    {
        for (int r = l; r <= n; r++)
        {
            if ((sa[r] - sa[l - 1]) % 2 == 0 && (sb[r] - sb[l - 1]) % 3 == 0 && ((sa[r] - sa[l - 1]) - (sb[r] - sb[l - 1])) % 5 == 0)
            {
                ans += r - l + 1;
            }
        }
    }
    cout << ans << endl;

    system("pause");
    return 0;
}