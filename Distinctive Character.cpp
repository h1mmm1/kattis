#include<bits/stdc++.h>
using namespace std;
const int N=(1<<21);
using pii=pair<int,int>;
vector<int> g[N];
queue<int> q;
int vis[N];
int p[21];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,k;
  cin >> n >> k;
  for(int i=0;i<(1<<k);i++){
    vis[i]=INT_MAX;
    for(int j=0;j<k;j++){
      g[i].push_back(i^(1<<j));
    }
  }
  for(int i=1;i<=n;i++){
    string s;
    cin >> s;
    int x=1,cnt=0;;
    for(int j=s.size()-1;j>=0;j--){
      cnt+=(s[j]-'0')*x;
      x*=2;
    }
    q.push(cnt);
    vis[cnt]=0;
  }
  while(!q.empty()){
    int x=q.front();
    q.pop();
    for(auto e:g[x]){
      int xx=e;
      if(vis[xx]>vis[x]+1){
        vis[xx]=vis[x]+1;
        q.push(xx);
      }
    }
  }
  int mx=INT_MIN,ans;
  for(int i=0;i<(1<<k);i++){
    if(mx<vis[i]){
      mx=vis[i];
      ans=i;
    }
  }
//  for(int i=0;i<(1<<k);i++) cout << i << ' ' << vis[i] << '\n';
//  cout << ans << ' ';
  int id=0;
  while(ans>0){
    if(ans%2==0) p[id]=0;
    else p[id]=1;
//    p.push_back(ans%2);
    ans/=2;
    id++;
  }
//  cout << p.size();
  for(int i=k-1;i>=0;i--){
    cout << p[i];
  }
}
