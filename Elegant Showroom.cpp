#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ppi=pair<int,pii>;
priority_queue<ppi,vector<ppi>,greater<ppi>> q;
const int N=405;
bool vis[N][N];
int dis[N][N];
char a[N][N];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	for(int i=1;i<N;i++){
		for(int j=1;j<N;j++){
			dis[i][j]=INT_MAX;
		}
	}
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
			if(i==1 || j==1 || i==n || j==m){
				if(a[i][j]=='D'){
					q.push({0,{i,j}});
					dis[i][j]=0;
				}
			}
		}
	}
	int r,t,u=0;
	cin >> r >> t;
	while(!q.empty()){
		int l=q.top().first;
		int x=q.top().second.first;
		int y=q.top().second.second;
		q.pop();
		if(vis[x][y]==true) continue;
		vis[x][y]=true;
		//cout << x << ' ' << y << '\n';
		if(x==r && y==t){
			cout << dis[x][y];
			return 0;
		}
		for(int i=0;i<4;i++){
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1 || yy<1 || xx>n || yy>m || a[xx][yy]=='#' || vis[xx][yy]==true) continue;
			if(a[xx][yy]=='c') u=1;
			else u=0;
			if(dis[xx][yy]>dis[x][y]+u){
				dis[xx][yy]=dis[x][y]+u;
				q.push({dis[xx][yy],{xx,yy}});
			}
		}
	}
}
