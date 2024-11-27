#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using piii=pair<pii,int>;
int a[1005];
priority_queue<piii,vector<piii>,greater<piii>> q;
int dis[1005][105];
bool vis[1005][105];
vector<pii> g[1005];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=m;i++){
		int a_,b,c;
		cin >> a_ >> b >> c;
		g[a_].push_back({b,c});
		g[b].push_back({a_,c});
	}
	int t;
	cin >> t;
	while(t--){
		int s,u,v;
		cin >> s >> u >> v;
		for(int i=0;i<1005;i++){
			for(int j=0;j<105;j++){
				vis[i][j]=false;
				dis[i][j]=1e6;
			}
		}
		dis[u][0]=0;
		q.push({{dis[u][0],u},0});
		int ans=INT_MAX;
		while(!q.empty()){
			int l=q.top().first.first;
			int x=q.top().first.second;
			int oil=q.top().second;
			q.pop();
			if(x==v){
				ans=min(ans,l);
			}
			if(vis[x][oil]==true) continue;
			vis[x][oil]=true;
			if(oil!=s && dis[x][oil+1]>dis[x][oil]+a[x]){
				dis[x][oil+1]=dis[x][oil]+a[x];
				q.push({{dis[x][oil+1],x},oil+1});
			}
			for(auto e:g[x]){
				int xx=e.first;
				int ll=e.second;
				if(oil-ll<0) continue;
				if(vis[xx][oil-ll]==false && dis[xx][oil-ll]>dis[x][oil]){
					dis[xx][oil-ll]=dis[x][oil];
					q.push({{dis[xx][oil-ll],xx},oil-ll});
				}
			}
		}
		if(ans==INT_MAX) cout << "impossible\n";
		else cout << ans << "\n";
	}
}
