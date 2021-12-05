//input,WA,AC等均可改为原题文件名
#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
int main () {
	int cc=0;
	while (true){
		system("./build");
		system("./AC");
		system("./WA");
		if (system("diff AC.out WA.out")) {
			freopen("text.in","r",stdin);
			int a,b;
			cin >> a >> b;
			cout << a << ' ' << b << endl;
			return 0;
		}
		cc++;
		cout << "AC: " << cc << endl;
	}
	
	return 0;
}
