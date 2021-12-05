#include<iostream>
using namespace std;
int f[1009];
int n,m;
void init(){
	for(int i=0;i<1005;i++) f[i]=i;
}
int getf(int x){
    if(f[x]!=x)
        f[x]=getf(f[x]);
    return f[x];
}
void merge(int x,int y){
    int a=getf(x),b=getf(y);
    if(a!=b) f[b]=a;
    else return;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        int a,b,res;
        cin >> n >> m;
        init();
        for(int i=1;i<=m;i++){
            cin >> a >> b;
            merge(a,b);
        }
        for(int i=1;i<=n;i++){
            if(f[i]==i) res++;
        }
        cout << res << endl;
    }
    return 0;
}
