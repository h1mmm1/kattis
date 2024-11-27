#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
using pii=pair<ll,ll>;
const int N=2e5+5,P=313,MOD=1e9+7;
ll h[N],p[N];
vector<int> ans[N];
unordered_map<ll,vector<int>> mp[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  p[0]=1;
  for(int i=1;i<N;i++){
    p[i]=p[i-1]*P;
    p[i]%=MOD;
  }
  int n;
  while(cin >> n){
  	cin.ignore();
    vector<pii> u;
    set<int> q; 
    for(int i=1;i<=n;i++){
      ll sum=0;
      string s;
      getline(cin,s);
      int x=s.size();
      q.insert(x);
      for(int j=1;j<=x;j++){
        sum+=1ll*s[j-1]*p[j];
        sum%=MOD;
      }
      u.push_back({x,sum});
      // v[x][sum]=i;
    }
    string str;
    getline(cin,str);
    int xx=str.size();
    for(int i=1;i<=n;i++){
      int x=u[i-1].first;
      if(x>xx) continue;
      ll sum=(u[i-1].second*p[xx-x])%MOD;
      mp[x][sum].push_back(i);
    }
    
    for(int i=1;i<=xx;i++){
      h[i]=h[i-1]+1ll*str[i-1]*p[i];
      h[i]%=MOD;
    }
    for(auto e:q){
      for(int i=0;i<=xx-e;i++){
        ll cnt=(h[i+e]-h[i]+MOD)%MOD;
        cnt*=p[xx-i-e];
        cnt%=MOD;
        if(mp[e].find(cnt)!=mp[e].end()){
          for(auto r:mp[e][cnt]){
          	ans[r].push_back(i);
		  }   
        }
      }
      mp[e].clear();
    }
    for(int i=1;i<=n;i++){
      for(auto e:ans[i]){
        cout << e << ' ';
      }
      ans[i].clear();
      cout << "\n";
    }
  }
}

