#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int t[501],s[501],f[501][101];
const int inf=2139062143;
int main(){
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> t[i];
	sort(t+1,t+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+t[i];
	memset(f,0x7f,sizeof(f));
	t[0]=-inf;
	f[0][0]=0;
	for(int i=0;i<=n;i++){
		int MAX=min(m-1,t[i+1]-t[i]);
		for(int j=0;j<=MAX;j++)
			if(f[i][j]!=inf)
				for(int k=1;i+k<=n;k++){
					int tmp=max(t[i]+j+m-t[i+k],0);
					f[i+k][tmp]=min(f[i+k][tmp],f[i][j]+(tmp+t[i+k])*k-(s[i+k]-s[i]));
				}
	}
	int ans=inf;
	for(int i=0;i<m;i++)
		ans=min(ans,f[n][i]);
	cout << ans << endl;
	return 0;
}
