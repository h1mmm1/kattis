#include<bits/stdc++.h>
using namespace std;
using ppi=pair<int,int>;
using pii=pair<ppi,int>;
queue<pii> q;

int a[505][505];
bool vis[505][505];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      char c;
      cin >> c;
      a[i][j]=c-'0';
    }
  }
  bool chk=false;
  q.push({{1,1},0});
  vis[1][1]=true;
  while(!q.empty()){
    int x=q.front().first.first;
    int y=q.front().first.second;
    int cnt=q.front().second;
    q.pop();
    //cout << x << ' ' << y << ' ' << cnt << "\n";
    if(x==n && y==m){
      cout << cnt;
      chk=true;
      break;
    }
    if(a[x][y]==0) continue;		
    cnt+=1;
    if(x+a[x][y]<=n && vis[x+a[x][y]][y]==false){
      q.push({{x+a[x][y],y},cnt});
      vis[x+a[x][y]][y]=true;
    }
    if(x-a[x][y]>=1 && vis[x-a[x][y]][y]==false){
      q.push({{x-a[x][y],y},cnt});
      vis[x-a[x][y]][y]=true;
    }
    if(y+a[x][y]<=m && vis[x][y+a[x][y]]==false){
      q.push({{x,y+a[x][y]},cnt});
      vis[x][y+a[x][y]]=true;
    }
    if(y-a[x][y]>=1 && vis[x][y-a[x][y]]==false){
      q.push({{x,y-a[x][y]},cnt});
      vis[x][y-a[x][y]]=true;
    }
  }
  if(chk==false){
    cout << "-1";
  }
}

