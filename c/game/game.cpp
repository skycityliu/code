#include <iostream>
#include <cstring>
#define max(x,y) x>y?x:y
#define get(i,j) ((j-i)%n+n)%n
using namespace std;
const int N=1010;
int n,m,p;
int f[N][N],cost[N],q[N][N],loc[N][N],l[N],r[N],add[N],dp[N];
int main(){
    cin >> n >> m >> p;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin >> f[j][i];
            f[j][i]+=f[j-1][i-1];
        }
    for(int i=0;i<n;i++){
        cin >> cost[i];
        q[i][++r[i]]=-cost[i];
        l[i]++;
    }
    memset(dp,-0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++){
            int id=get(i,j);
            while(l[id]<=r[id]&&loc[id][l[id]]+p<i) l[id]++;
            if(!j) add[id]+=f[i][n];
            if(l[id]<=r[id])
                dp[i]=max(dp[i],q[id][l[id]]+add[id]+f[i][j]);
        }
        for(int j=0;j<n;j++){
            int id=get(i,j);
            int tmp=dp[i]-add[id]-f[i][j]-cost[j];
            while(l[id]<=r[id]&&q[id][r[id]]<=tmp)
                r[id]--;
            loc[id][++r[id]]=i;
            q[id][r[id]]=tmp;
        }
    }
    cout << dp[m] << endl;
    return 0;
}
