#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int N=36;
char a[N][N][N];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int vis[N][N][N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int l,n,m;
  while(cin >> l >> n >> m){
    queue<pair<pii,int>> q;
    memset(a,' ',sizeof a);
    if(l==0) return 0;
    for(int i=1;i<=35;i++){
      for(int j=1;j<=35;j++){
        for(int k=1;k<=35;k++){
          vis[i][j][k]=1e6;
        }
      }
    }		
    for(int i=1;i<=l;i++){
      for(int j=1;j<=n;j++){
        for(int k=1;k<=m;k++){
          cin >> a[i][j][k];
          if(a[i][j][k]=='S'){
            q.push({{j,k},i});
            vis[i][j][k]=0;
          }
        }
      }
    }
    bool chk=true;
    int ans;
    while(!q.empty()){
      int x=q.front().first.first;
      int y=q.front().first.second;
      int p=q.front().second;
      q.pop();
      if(a[p][x][y]=='E'){
        ans=vis[p][x][y];
        chk=false;
        break;
      }
      
      if(p+1<=l && a[p+1][x][y]!='#' && vis[p+1][x][y]>vis[p][x][y]+1){
        vis[p+1][x][y]=vis[p][x][y]+1;
        q.push({{x,y},p+1});
      }
      if(p-1>0 && a[p-1][x][y]!='#' && vis[p-1][x][y]>vis[p][x][y]+1){
        vis[p-1][x][y]=vis[p][x][y]+1;
        q.push({{x,y},p-1});
      }
      for(int k=0;k<4;k++){
        int xx=x+dx[k];
        int yy=y+dy[k];
        if(xx<1 || yy<1 || xx>n || yy>m) continue;
        if(a[p][xx][yy]!='#' && vis[p][xx][yy]>vis[p][x][y]+1){
          vis[p][xx][yy]=vis[p][x][y]+1;
          q.push({{xx,yy},p});
        }
      }
    }
//    for(int i=1;i<=l;i++){
//      for(int j=1;j<=n;j++){
//        for(int k=1;k<=m;k++){
//          cout << vis[i][j][k] << ' ';
//        }
//        cout << "\n";
//      }
//      cout << "\n";
//    }		
    if(chk==false){
      cout << "Escaped in " << ans << " minute(s)." << "\n";
    }
    else{
      cout << "Trapped!" << "\n";
    }
  }
}


