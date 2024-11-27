#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<pii> p;
vector<int> v;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    int n,st1,st2,tp1,tp2;
    cin >> n >> st1 >> st2 >> tp1 >> tp2;
    if(st1>tp1) swap(st1,tp1),swap(st2,tp2);
    int xmx=max(st1,tp1),ymx=max(tp2,st2),xmn=min(tp1,st1),ymn=min(st2,tp2);
//    cout << xmx << ' ' << xmn << ' ' << ymx << ' ' << ymn << "\n";
    for(int i=1;i<=n;i++){
    	int x,y;
    	cin >> x >> y;
    	if(x>xmx || y>ymx || x<xmn || y<ymn) continue;
    	p.push_back({x,y});
//    	cout << x << ' ' << y << "\n";
	}
	if(st1==tp1 || st2==tp2){
		cout << p.size();
		return 0;
	}
	if(st2<=tp2){
		sort(p.begin(),p.end());
		for(auto e:p){
			auto u=upper_bound(v.begin(),v.end(),e.second)-v.begin();
			if(u==v.size()) v.push_back(e.second);
			else v[u]=e.second;
//			cout << u << ' ';
		}
		cout << v.size();
//		for(auto e:p) cout << e.first << ' ' << e.second << '\n';
		
	}
	else{
		sort(p.begin(),p.end(), [](const pii &a,const pii&b){
			if(a.first==b.first) return a.second<b.second;
			return a.first>b.first; 
		});
		for(auto e:p){
			auto u=upper_bound(v.begin(),v.end(),e.second)-v.begin();
			if(u==v.size()) v.push_back(e.second);
			else v[u]=e.second;
//			cout << u << ' ';
		}
		cout << v.size();
//		for(auto e:p) cout << e.first << ' ' << e.second << '\n';
	}
}

