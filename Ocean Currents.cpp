#include<bits/stdc++.h>
using namespace std;
using ppi=pair<int,int>;
using pii=pair<int,ppi>;
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};
priority_queue<pii,vector<pii>,greater<pii>> q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	int dis[n+5][m+5];
	bool vis[n+5][m+5];
	char a[n+5][m+5];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
		}
	}
	int t;
	cin >> t;
	while(t--){
		int stx,sty,edx,edy,cnt=0;
		cin >> stx >> sty >> edx >> edy;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				dis[i][j]=1e9;
				vis[i][j]=false;
			}
		}
		
		dis[stx][sty]=0;
		q.push({dis[stx][sty],{stx,sty}});
		while(!q.empty()){
			int l=q.top().first;
			int x=q.top().second.first;
			int y=q.top().second.second;
			q.pop();
//			cout << x << ' ' << y<< ' ' << dis[x][y] << ' ' << a[x][y]<< "\n";			
			if(x==edx && y==edy){
				cout << dis[x][y] << '\n';
				break;
			}

			if(vis[x][y]==true) continue;
			vis[x][y]=true;
			for(int i=0;i<8;i++){
				int xx=x+dx[i];
				int yy=y+dy[i];
				if(xx<1 || yy<1 || xx>n || yy>m) continue;
				if(i!=a[x][y]-'0') cnt=1;
				else cnt=0;
				if(vis[xx][yy]==false && dis[xx][yy]>dis[x][y]+cnt){
					dis[xx][yy]=dis[x][y]+cnt;
					q.push({dis[xx][yy],{xx,yy}});
				}
			}
		}
		while(!q.empty()) q.pop();
	}
}

