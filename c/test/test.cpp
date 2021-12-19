#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=4e5+10;
const int maxm=2e5+10;
int n,m,k,now;
int t[maxn],f[maxn],ans[maxn];
struct edge{
	int u,v,time;
}e[maxm];
bool comp(edge x,edge y){
	return x.time<y.time;
}
int find(int k){
	return f[k]==k?k:f[k]=find(f[k]);
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++) cin >> e[i].u >> e[i].v;
    cin >> k;
    int a,b;
    for(int i=k;i>0;i--){
        cin >> a;
        t[a]=i;
    }
    for(int i=1;i<=m;i++) e[i].time=max(t[e[i].u],t[e[i].v]);
    sort(e+1,e+m+1,comp);
    now=n;
    for(int i=0,j=1;i<=k;i++){
        while(e[j].time<=i&&j<=m){
            a=find(e[j].u),b=find(e[j].v);
            if(a!=b){
                f[a]=b;
                now--;
            }
            j++;
        }
        ans[k-i]=now-k+i;
    }
    for(int i=0;i<=k;i++) cout << ans[i] << endl;
    return 0;
}