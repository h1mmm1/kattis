#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	while(cin >> s){
		if(s==".") return 0;
		queue<char> q1,q2;
		for(auto e:s){
			q1.push(e);
		}
		q2=q1;
		int n=s.size();
		for(int i=1;i<=n;i++){
			q2.push(q2.front());
			q2.pop();
			if(n%i==0){
				if(q2==q1){
					cout << n/i << "\n";
					break;
				}
			}
		}
	}
}
