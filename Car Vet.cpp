#include<bits/stdc++.h>
using namespace std;
const int N=255;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int endx,endy,mn=INT_MAX,n,m;
bool vis[N][N];
int a[N][N];
vector<int> p;
vector<vector<int>> ans;

void rec(int x,int y){
	vis[x][y]=true;
	//cout << x << ' ' << y << "\n";
	if(x==endx && y==endy){
		if(mn>p.size()){
			mn=p.size();
			ans.clear();
			ans.push_back(p);
		}
		else if(mn==p.size()){
			ans.push_back(p);
		}
		return;
	}
	for(int i=0;i<4;i++){
		int xx=x+dx[i];
		int yy=y+dy[i]; // xx befor
		
		int xv=xx+dx[i];
		int yv=yy+dy[i]; //xv after

		if(xv<1 || yv<1 || xv>n || yv>m || a[xv][yv]==-2 || vis[xv][yv]==true) continue;
		if(a[xx][yy]!=a[xv][yv]) continue;
		//cout << xx << ' ' << yy <<  " " << xv << ' ' << yv << "\n";		
		swap(a[xv][yv],a[x][y]);
		p.push_back(a[x][y]);
		rec(xv,yv);
		p.pop_back();
		swap(a[xv][yv],a[x][y]);
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int r,t;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
			if(a[i][j]==-1){
				r=i;
				t=j;
			}
		}
	}
	cin >> endx >> endy;
	rec(r,t);
	sort(ans.begin(),ans.end());
	if(!ans.empty()){
		for(auto e:*ans.begin()){
			cout << e << ' ';
		}		
	}
	else cout << "impossible";

}
