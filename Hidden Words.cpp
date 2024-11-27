#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<pii> chk[30];
char a[15][15];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
string s;
int sum=0,n,m;
bool t=false;
bool vis[15][15];
unordered_map<string,int> mp;

void rec(int x,int y,int cnt){
  if(t) return;
  //cout << x << ' ' << y << "\n";
  if(cnt+1==s.size()){
    sum++;
    mp[s]=1;
    t=true;
    return;
  }
  
  for(int i=0;i<4;i++){
    int xx=x+dx[i];
    int yy=y+dy[i];
    if(xx<0 || yy<0 || xx>n || yy>m || vis[xx][yy]==true) continue;
    if(a[xx][yy]==s[cnt+1]){
      vis[xx][yy]=true;
      rec(xx,yy,cnt+1);
      vis[xx][yy]=false;
      //cout << "as";
    }
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin >> a[i][j];
      int x=a[i][j]-'A'+1;
      chk[x].push_back({i,j});
    }
  }
  int q;
  cin >> q;
  while(q--){
    cin >> s;
    for(auto e:s){
      if(chk[e-'A'+1].size()==0){
        mp[s]=-1;
        break;
      }
    }
    int x=s[0]-'A'+1;
    if(mp.find(s)!=mp.end()){
      if(mp[s]==1){
         sum++;       
      }
      continue;
    }
    
    for(auto e:chk[x]){
      vis[e.first][e.second]=true;
      rec(e.first,e.second,0);
      vis[e.first][e.second]=false;
    }
    if(mp.find(s)==mp.end()){
      mp[s]=-1;
    }
    t=false;
  }
  cout << sum;
}
