

#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int near (int n) {
	int res = n;
	while ((res&(res-1)) != 0) {
		res--;
	}
	return res;
}

int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
    int n;
	cin >> n;
	if ((n%2==1) || (n<2)) {
		cout << -1 << endl;
		return 0;
	}
	if ((n&(n-1)) == 0) {
		cout << n << endl;
		return 0;
	}
	for (int i = near(n); n != 0; i/=2){
		if (n >= i) {
			n -= i;
			cout << i << ' ';
		}
	}
	cout << endl;
	
    return 0;
}
