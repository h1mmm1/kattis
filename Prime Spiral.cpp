#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int N=10005;
int a[N][N];
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
pii id[N];
int dis[N][N];
bool p[N];

int main(){
    //ios::sync_with_stdio(0); cin.tie(0);
    p[1]=true;
    for(int i=2;i*i<N;i++){
    	if(p[i]==false){
    		for(int j=i*i;j<N;j+=i){
    			p[j]=true;
			}
		}
	}
	int x=200,y=200;
	int cnt=0,sum=0,xmx=x,ymx=y,xmn=x,ymn=y;
	for(int i=0;sum<N;i++){
		for(int k=0;k<2;k++){
			for(int j=0;j<=i && sum<N;j++){
				a[x][y]=++sum;
				id[sum]={x,y};
				xmx=max(x,xmx);
				ymx=max(y,ymx);
				xmn=min(x,xmn);
				ymn=min(y,ymn);
				x+=dx[cnt%4];
				y+=dy[cnt%4];
			}
			++cnt;
		}
	}
	int n,m,e=0;
//	for(int i=1;i<=10;i++) cout << p[i];
	while(cin >> n >> m){
		queue<pii> q;
		e++;
		for(int i=xmn;i<=xmx;i++){
			for(int j=ymn;j<=ymx;j++){
				dis[i][j]=0;
			}
		}
		bool chk=false;
		q.push({id[n]});
		dis[id[n].first][id[n].second]=1;
		while(!q.empty()){
			int x_=q.front().first;
			int y_=q.front().second;
			q.pop();
			if(x_==id[m].first && y_==id[m].second){
				chk=true;
				break;
			}
			for(int i=0;i<4;i++){
				int xx=x_+dx[i];
				int yy=y_+dy[i];
				if(dis[xx][yy] || xx<xmn || yy<ymn || xx>xmx || yy>ymx || p[a[xx][yy]]==false) continue;
				dis[xx][yy]=dis[x_][y_]+1;
				q.push({xx,yy});
				
			}
			
		}
		cout << "Case " << e << ": ";
		if(chk==true) cout << dis[id[m].first][id[m].second]-1 << "\n";
		else cout << "impossible\n";   
	}
//	for(int i=xmn;i<=xmx;i++){
//		for(int j=ymn;j<=ymx;j++){
//    		cout << a[i][j] << ' ';
//    	}
//    	cout << "\n";
//	}
}

