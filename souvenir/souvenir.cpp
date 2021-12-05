#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
int f[20005],g[20005],p[105][105],n,m,t;
    cin>>t>>n>>m;
    for(int i=1;i<=t;i++) {
        for(int j=1;j<=n;j++) {
            cin>>p[i][j];
        }
    }
    for(int i=1;i<=t;i++) {
        if(i>1) m=*max_element(f,f+10001);
        memset(f,-0x3f,sizeof f);
        f[m]=m;
        for(int j=1;j<=n;j++) {
            for(int k=1e4;k>=0;k--) {
                f[k]=max(f[k],f[k+p[i][j]]+p[i+1][j]-p[i][j]);
            }
        }
    }
    cout << *max_element(f,f+10001) << endl;
    
    return 0;
}
