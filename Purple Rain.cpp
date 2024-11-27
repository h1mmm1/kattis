#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	int b=0,r=0,mx=0,bl=1,rl=1,ans1=0,ans2=0;
	for(int i=1;i<=s.size();i++){
		if(s[i-1]=='R'){
			++r;
			--b;
		}
		else if(s[i-1]=='B'){
			++b;
			--r;
		}
		if(r<0){
			rl=1+i;
			r=0;
		}
		if(b<0){
			bl=1+i; // map
			b=0;
		}
		if(r>mx){
			mx=r;
			ans1=rl;
			ans2=i;
		}
		if(b>mx){
			mx=b;
			ans1=bl;
			ans2=i;
		}
		//cout << mx << ' ' << ans1 << ' ' << ans2 << "\n";
	}
	cout << ans1 << ' ' << ans2;
}
