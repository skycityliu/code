#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
using namespace std;
const int N=1000100;
int n,m,i,t,t1,len,mp[N],z[N],res1,a[N],p,k;
string c;
struct Node {
	int z,y,res,fh;   
}jd[1000100];
void tree(int x){
	if (jd[x].fh==-1) mp[jd[x].z]=1;
    else{
     	if (jd[jd[x].z].res^jd[x].fh) tree(jd[x].y);
     	if (jd[jd[x].y].res^jd[x].fh) tree(jd[x].z);
	 }
    return;
} 
int sz(int x){
	int m=0;
	while (c[x]>='0'&&c[x]<='9') 
	 m=m*10+(c[x]-48),x=x+1;
	 return m;
}
 int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
    getline(cin,c);
    len=c.length();
    scanf("%d",&n);
    for (i=1;i<=n;i++) scanf("%d",&a[i]);
     t=0;
     t1=0;
     for (i=0;i<=len-1;i++)
     	if (c[i]=='x'){
        	k=sz(i+1);
        	jd[++t].res=a[k];
        	jd[t].fh=-1;
        	jd[t].z=k;
        	jd[t].y=k;
        	z[++t1]=t;
		}
		else if (c[i]=='&'){
	    	jd[++t].fh=0;
	    	jd[t].y=z[t1];
	    	jd[t].z=z[--t1];
	    	jd[t].res=(jd[jd[t].y].res)&&(jd[jd[t].z].res);
	    	z[t1]=t;
		}
		else if (c[i]=='|'){
	    	jd[++t].fh=1;
	    	jd[t].y=z[t1];
	    	jd[t].z=z[--t1];
	    	jd[t].res=(jd[jd[t].y].res)||(jd[jd[t].z].res);
	    	z[t1]=t;
		}
		else if (c[i]=='!')
	    	jd[z[t1]].res=!(jd[z[t1]].res);
	res1=jd[t].res;
	memset(mp,0,sizeof(mp)); 
	tree(t);
	scanf("%d",&m);
	for (i=1;i<=m;i++){
		scanf("%d",&p);
	    if (mp[p]==1) printf("%d\n",!res1);
	    else printf("%d\n",res1);
	}
    return 0;
  }
