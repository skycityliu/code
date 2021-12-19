#include<iostream>
#include<algorithm>
#define inf -1e17
using namespace std;
long long dp[1009][1009][3];
long long a[1009][1009];
int n,m;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            dp[i][j][0] = inf;
            dp[i][j][1] = inf;
            dp[i][j][2] = inf;
        }
    }
    dp[1][1][0]=dp[1][1][1]=dp[1][1][2]=a[1][1];
    for(int i=2;i<=n;i++){
        dp[i][1][1] = dp[i-1][1][1] + a[i][1];
    }
    for(int j=2;j<=m;j++){
        for(int i=1;i<=n;i++){
            dp[i][j][0]=max(dp[i][j-1][1],max(dp[i][j-1][0],dp[i][j-1][2]))+a[i][j];
            if(i>=2) dp[i][j][1]=max(dp[i-1][j][0],dp[i-1][j][1])+a[i][j];
        }
        for(int i=n-1;i>=1;i--){
            dp[i][j][2]=max(dp[i+1][j][0],dp[i+1][j][2])+a[i][j];
        }
    }
	cout<<max(dp[n][m][0],max(dp[n][m][1],dp[n][m][2])) << endl;
    
	return 0;
}
