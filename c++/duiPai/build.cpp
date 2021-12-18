#include<bits/stdc++.h>
//#include<iostream>
//#include<cstdlib>
//#include<cstdio>
//#include<ctime>
using namespace std;
int main () {
	freopen("text.in","w",stdout);
	srand(time(NULL));
	switch(rand()%4) {
		case 0:
			cout << rand()%1000009 << ' ' << rand()%1000009 << endl;
			break;
		case 1:
			cout << -(rand()%1000009) << ' ' << rand()%1000009 << endl;
			break;
		case 2:
			cout << rand()%1000009 << ' ' << -(rand()%1000009) << endl;
			break;
		case 3:
			cout << -(rand()%1000009) << ' ' << -(rand()%1000009) << endl;
			break;
	}

	return 0;
}
