#include<iostream>
using namespace std;
int f[1000001],ans=0;
int find(int k){ 
	if(f[k]==k) return k;
	else return f[k]=find(f[k]);
}
void merge(int x,int y){ 
	f[find(x)]=find(y);
}
int main(){
	int a,b;
	while(true){
		ans=0; 
		cin>>a;
		if(a==0) return 0; 
		cin>>b;
		for(int i=1;i<=a;i++) f[i]=i; 
		for(int i=1;i<=b;i++){
			int x,y;
			cin>>x>>y;
			merge(x,y); 
		}
		for(int i=1;i<a;i++){
			if(find(f[i])==find(f[i+1])){
				continue;
			}else{
				merge(i,i+1); 
				ans++; 
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
