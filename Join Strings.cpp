#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<string> w;
vector<int> g[1000005];
queue<int> q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,x=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		string s;
		cin >> s;
		w.push_back(s);
	}
	for(int i=1;i<n;i++){
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		x=a;
	}
	q.push(x);
	while(!q.empty()){
		int v=q.front();
		q.pop();
		cout << w[v];
		for(auto e:g[v]){
			q.push(e);
		}
	}
}
