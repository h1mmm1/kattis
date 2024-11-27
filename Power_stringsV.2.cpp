#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	while(cin >> s){
		if(s==".") return 0;
		int x=s.size();
		queue<char> q1,q2;
		for(auto e:s){
			q1.push(e);
		}
		q2=q1;
		for(int i=1;i<=x;i++){
			q1.push(q1.front());
			q1.pop();
			if(x%i==0){
				if(q1==q2){
					cout << x/i << "\n";
					break;
				}
			}
		}
	}
}
