#include<iostream>
#include<algorithm>
using namespace std;
struct Node{
	int s,e,w;
}a[200005];
int f[200005];
bool cmp(Node a,Node b){
	return a.w<b.w;
}
int find(int a){ 
	if(f[a]==a)
	return a;
	else return f[a]=find(f[a]);
}
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++) cin>>a[i].s>>a[i].e>>a[i].w;
	sort(a+1,a+1+m,cmp);
	int cnt=0,sum=0;
	for(int i=1;i<=m;i++){
		if(find(a[i].s)!=find(a[i].e)){
			f[find(a[i].s)]=find(a[i].e);
			sum+=a[i].w;
			cnt++;
		}
		if(cnt>=n-k)
		break;
	}
	if(cnt>=n-k) cout<<sum<<endl;
	else cout<<"No Answer\n";
	return 0;
} 
