//https://open.kattis.com/problems/dvaput
#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int P=53,P2=101,MOD=1e9+7,MOD2=98765431,N=2e5;
ll p[N],p2[N],h[N],h2[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  p[0]=p2[0]=1;
  for(int i=1;i<N;i++){
    p[i]=p[i-1]*P;
    p[i]%=MOD;
    p2[i]=p2[i-1]*P2;
    p2[i]%=MOD2;
  }
  int n;
  string s;
  cin >> n >> s;
  for(int i=1;i<=n;i++){
    h[i]=h[i-1]+s[i-1]*p[i];
    h2[i]=h2[i-1]+s[i-1]*p2[i];
  }
  int l=0,r=n-1; 
  while(l<r){
    vector<pair<ll,ll>> mp;
    bool chk=true;
    int mid=(l+r+1)/2;
    ll cnt=0,cnt2=0;
    for(int i=0;i<=n-mid;i++){
      ll x=(h[i+mid]-h[i]+MOD)%MOD;
      ll y=(h2[i+mid]-h2[i]+MOD2)%MOD2;
      cnt=(x*p[n-i])%MOD;
      cnt2=(y*p2[n-i])%MOD2;
      mp.push_back({cnt,cnt2});
    }
    sort(mp.begin(),mp.end());
    for(int i=1;i<mp.size();i++){
      if(mp[i].first==mp[i-1].first && mp[i].second==mp[i-1].second){
        chk=false;
        break;
      }
    }
    if(chk==false) l=mid;
    else r=mid-1;
  }
  cout << l;
}
