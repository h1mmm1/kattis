#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int vis[N][N];
int vis_2[N][N];
queue<pair<int,int>> q;
char a[N][N];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		for(int i=1;i<=1000;i++){
			for(int j=1;j<=1000;j++){
				vis[i][j]=vis_2[i][j]=INT_MAX;
			}
		}
		int n,m,w,e;
		cin >> m >> n;
		bool chk=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin >> a[i][j];
				if(a[i][j]=='*'){
					q.push({i,j});
					vis[i][j]=0;
				}
				else if(a[i][j]=='@'){
					w=i;
					e=j;						
				}
			}
		}
		while(!q.empty()){
			int x=q.front().first;
			int y=q.front().second;
			q.pop();
			for(int k=0;k<4;k++){
				int xx=x+dx[k];
				int yy=y+dy[k];
				if(xx<1 || xx>n || yy<1 || yy>m) continue;
				if(a[xx][yy]=='@' || a[xx][yy]=='#') continue;
				if(vis[xx][yy]>vis[x][y]+1){
					vis[xx][yy]=vis[x][y]+1;
					q.push({xx,yy});
					
				}
			}
		}
		q.push({w,e});
		vis_2[w][e]=0;
		while(!q.empty()){
			int x=q.front().first;
			int y=q.front().second;
			q.pop();
			if(x==1 || x==n || y==1 || y==m){
				cout << vis_2[x][y]+1 << "\n";
				chk=false;
				break;
			}
			for(int k=0;k<4;k++){
				int xx=x+dx[k];
				int yy=y+dy[k];
				if(xx<1 || xx>n || yy<1 || yy>m) continue;
				if(vis[xx][yy]<=vis_2[x][y]+1 || a[xx][yy]=='#') continue;			
				if(vis_2[xx][yy]>vis_2[x][y]+1){
					vis_2[xx][yy]=vis_2[x][y]+1;
					q.push({xx,yy});
					
				}
			}
		}
		while(!q.empty()) q.pop();
		if(chk==true) cout << "IMPOSSIBLE" << "\n";
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++){
//				if(vis[i][j]==INT_MAX) vis[i][j]=0; 
//				cout << vis[i][j];
//			}
//			cout << "\n";
//		}
	}
}

