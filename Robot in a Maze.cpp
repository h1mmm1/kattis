#include<bits/stdc++.h>
using namespace std;
using ppi=pair<int,int>;
using pii=pair<ppi,ppi>;
const int N=1e3+5;
char a[N][N];
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
queue<pii> q;
int vis[N][N][4][2];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,m,lim=1;
		cin >> n >> m;
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin >> a[i][j];	
				if(a[i][j]=='R'){
					for(int k=0;k<4;k++){
						q.push({{i,j},{k,lim}});
						vis[i][j][k][lim]=1;
					}						
				}

			}
		}
		bool chk=false;
		while(!q.empty()){
			int x=q.front().first.first;
			int y=q.front().first.second;
			int d=q.front().second.first;
			int w=q.front().second.second;
			q.pop();
			//cout << x << ' ' << y << ' ' << d << ' ' << w << "\n" << '\n';
			if(a[x][y]=='D'){
				chk=true;
				cout << vis[x][y][d][w]-1 << "\n";
				break;
			}
			for(int i=0;i<4;i++){
				int xx=x+dx[i];
				int yy=y+dy[i];
				if(a[xx][yy]=='B') continue;
				if(xx<1 || yy<1 ||xx>n || yy>m) continue;
				if(i==(d+2)%4) continue;
				if(i!=d && vis[xx][yy][i][lim]==0){
					vis[xx][yy][i][lim]=vis[x][y][d][w]+1;
					q.push({{xx,yy},{i,lim}});
				}
				if(i==d && vis[xx][yy][i][w-1]==0 && w==1){
					vis[xx][yy][i][w-1]=vis[x][y][i][w]+1;
					q.push({{xx,yy},{i,w-1}});
				}
			}
		}
		while(!q.empty()) q.pop();
		if(chk==false) cout << "-1" << "\n";
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++){
//				for(int k=0;k<4;k++){
//					cout << vis[i][j][k][1] << ' ';
//				}
//				cout << '\n';
//			}
//			cout << '\n';
//		}		
	}

}
/*
4

5 6
....D.
.R.B..
...B..
......
......

5 6
....D.
.RBB..
...B..
......
......

4 5
R...D
BB.BB
.....
.....

3 4
...D
RBB.
..B.

*/

