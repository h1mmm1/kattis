#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long int;
const int N=1e6+5,P=53,MOD=1e9+7;
ll h[N],p[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  p[0]=1;
  for(int i=1;i<N;i++){
    p[i]=p[i-1]*P;
    p[i]%=MOD;
  }
  int n;
  while(cin >> n){
    vector<pii> v;
    // unordered_map<int> v;
    for(int i=1;i<=n;i++){
      ll sum=0;
      string s;
      getline(cin,s);
      int x=s.size();
      for(int j=1;j<=x;j++){
        sum+=s[j-1]*p[j];
        sum%=MOD;
      }
      // v[x]=sum;
      v.push_back({sum,x});
    }
    string str;
    getline(cin,str);
    int xx=str.size();
    for(int i=1;i<=xx;i++){
      h[i]=h[i-1]+str[i-1]*p[i];
      h[i]%=MOD;
    }
    for(auto e:v){
      ll cnt=e.first;
      int sub=e.second;
      for(int i=0;i<=xx-sub;i++){
        ll x=(h[i+sub]-h[i]+MOD)%MOD;
        if(x==cnt) cout << i << ' ';
        cnt*=P;
        cnt%=MOD;
      }
      cout << "\n";
    }
  }
}
