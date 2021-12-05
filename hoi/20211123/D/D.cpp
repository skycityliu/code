#include<iostream>
#include<algorithm>
using namespace std;
int ab,ac,bc;
struct Node{
	string str;
	int len;
}a[9];
bool cmp (Node x,Node y){
	return x.len>y.len;
}
int main () {
	for (int i = 1; i <= 6; i++) {
		cin >> a[i].str;
		a[i].len=a[i].str.length();
	}
	sort(a+1,a+7,cmp);
	if (!(a[1]==a[3]+a[4]-1&&a[2]==a[5]+a[6]-1 || a[1]==a[3]+a[5]-1&&a[2]==a[4]+a[6]-1 || a[1]==a[3]+a[6]-1&&a[2]==a[2]+a[5]-1 || a[1]==a[5]+a[4]-1&&a[2]==a[3]+a[6]-1 || a[1]==a[6]+a[4]-1&&a[2]==a[5]+a[3]-1 || a[1]==a[5]+a[6]-1&&a[2]==a[3]+a[4]-1)){
		cout << "Impossible" << endl;
		return 0;
	}
	
	
	ab=ac=bc=-1;
	char a,op,b;
	for (int i = 0; i < 3; i++) {
		cin >> a >> op >> b;
		
		if (a=='A'&&b=='B'){
			if (ab!=-1) {
				cout << "Impossible" << endl;
				return 0;
			}
			if (op=='>') ab=1;
			else ab=0;
		}
		if (a=='B'&&b=='A'){
			if (ab!=-1) {
				cout << "Impossible" << endl;
				return 0;
			}
			if (op=='>') ab=0;
			else ab=1;
		}
		
		
		if (a=='A'&&b=='C'){
			if (ac!=-1) {
				cout << "Impossible" << endl;
				return 0;
			}
			if (op=='>') ac=1;
			else ac=0;
		}
		if (a=='C'&&b=='A'){
			if (ac!=-1) {
				cout << "Impossible" << endl;
				return 0;
			}
			if (op=='>') ac=0;
			else ac=1;
		}
		
		
		if (a=='B'&&b=='C'){
			if (bc!=-1) {
				cout << "Impossible" << endl;
				return 0;
			}
			if (op=='>') bc=1;
			else bc=0;
		}
		if (a=='C'&&b=='B'){
			if (bc!=-1) {
				cout << "Impossible" << endl;
				return 0;
			}
			if (op=='>') bc=0;
			else bc=1;
		}
	}
	
	if (ab==1&&ac==1&&bc==1){
		cout << "CBA" << endl;
	}
	if (ab==1&&ac==0&&bc==1){
		cout << "Impossible" << endl;
	}
	if (ab==1&&ac==1&&bc==0){
		cout << "BCA" << endl;
	}
	if (ab==0&&ac==1&&bc==1){
		cout << "CAB" << endl;
	}
	if (ab==0&&ac==0&&bc==1){
		cout << "ACB" << endl;
	}
	if (ab==0&&ac==1&&bc==0){
		cout << "Impossible" << endl;
	}
	if (ab==1&&ac==0&&bc==0){
		cout << "BAC" << endl;
	}
	if (ab==0&&ac==0&&bc==0){
		cout << "ABC" << endl;
	}
	
	return 0;
}
