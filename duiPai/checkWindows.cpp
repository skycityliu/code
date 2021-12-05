#include<bits/stdc++.h>
using namespace std;
int main () {
	while (true) {
		system("build > input.in");
		system("WA < input.in > WA.out");
		system("AC < input.in > AC.out");
		if (system("fc AC.out WA.out")) {
			freopen("input.in","r",stdin);
			int a,b;
			cin >> a >> b;
			cout << "khsabkvjhsadbv WA  " << a << ' ' << b << endl;
			return 0;
		}
	}
	
	return 0;
}
