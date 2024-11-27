#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int a,b,c;
		cin >> a >> b >> c;
		if(c%__gcd(a,b)==0) cout << "YES\n";
		else cout << "NO\n";
	}
}
