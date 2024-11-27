#include<bits/stdc++.h>
using namespace std;
using pi=pair<int,int>;
using pii=pair<int,pi>;
int dx[]={0,0,1,1,1,-1,-1,-1};
int dy[]={1,-1,0,1,-1,0,1,-1};
const int N=1005;
char a[N][N];
priority_queue<pii,vector<pii>,greater<pii>> q;
bool vis[N][N];
int dis[N][N];
int ans[30];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
			if(a[i][j]=='W'){
				q.push({0,{i,j}});
				dis[i][j]=0;
			}
		}
	}
	while(!q.empty()){
		int d=q.top().first;
		int x=q.top().second.first;
		int y=q.top().second.second;
		q.pop();
		if(vis[x][y]==true) continue;
		vis[x][y]=true;
		for(int i=0;i<8;i++){
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(vis[xx][yy]==false && dis[xx][yy]>dis[x][y]){
				if(a[xx][yy]!=a[x][y]) dis[xx][yy]=dis[x][y]+1;
				else dis[xx][yy]=dis[x][y];
				q.push({dis[xx][yy],{xx,yy}});
			}
		}
	}
	for(int i=0;i<30;i++){
		ans[i]=INT_MAX;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]!='W'){
				int r=a[i][j]-'A';
				ans[r]=min(ans[r],dis[i][j]);
			}
		}
	}
	for(int i=0;i<30;i++){
		if(ans[i]!=INT_MAX){
			cout << char(i+'A') << ' ' << ans[i]-1 << "\n";
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout << dis[i][j] << ' ';
//		}
//		cout << "\n";
//	}
}
