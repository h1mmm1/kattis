#include<bits/stdc++.h>
using namespace std;
vector<string> p;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		string s;
		cin >> s;
		p.push_back(s);
	}
	bool chk=false;
	for(int i=1;i<n;i++){
		if(p[i].size()==p[i-1].size()){
			if(p[i].size()==1 && p[i][0]=='9' && p[i-1][0]=='0') continue;
			if(p[i][0]-'0'+1<=9) p[i-1][0]=p[i][0]+1,chk=true;
			else if(p[i].size()!=1 && p[i-1][0]-'0'-1>0) p[i][0]=p[i-1][0]-1,chk=true; 
			else if(p[i].size()==1 && p[i-1][0]-'0'-1>=0) p[i][0]=p[i-1][0]-1,chk=true; 
		}
		if(chk==true) break;
	}
	if(chk==false) cout << "impossible";
	else{
		for(auto e:p) cout << e << ' ';
	}
}
