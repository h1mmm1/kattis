#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int N=2005;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
queue<pii> q;
int vis[N][N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  while(cin >> n){
    if(n==0) return 0;
    for(int i=1;i<=N;i++){
      for(int j=1;j<=N;j++){
        
      }
    }
    for(int i=1;i<=n;i++){
      int x,y;
      cin >> x >> y;
      q.push({x,y});
      vis[x][y]=0;
    }
    cin >> m;
    for(int i=1;i<=m;i++){
      int x,y;
      cin >> x >> y;
      vis[x][y]=-1;
    }
    bool chk-false;
    while(!q.empty()){
      int x=q.front().first;
      int y=q.front().second;
      q.pop();
      for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(vis[xx][yy]>vis[x][y]+1){
          vis[xx][yy]=vis[x][y]=1;
        }
        else if(vis[xx][yy]==-1){
          cout << vis[x][y]+1;
          chk=true;
        }
      }
      if(chk==true) break;
    }
    while(!q.empty()) q.pop();
    
  }
} 
