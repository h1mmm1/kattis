#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
vector<ll> f;
vector<ll> b;
vector<pair<ll,ll>> p;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    int a;
    cin >> a;
    f.push_back(a);
  }
  for(int i=1;i<=m;i++){
    int a;
    cin >> a;
    b.push_back(a);
  }
  for(auto e:f){
    for(auto r:b){
      p.push_back({e,r});
    //cout << "(" << e << "," << r << ")" << "\n";
    }
  }
  sort(p.begin(),p.end(),[](const pair<ll,ll> a,const pair<ll,ll> b){
    if(a.first*b.second==a.second*b.first){
      return a.first<b.first;
    }
    return a.first*b.second<a.second*b.first;
  });
  for(auto e:p){
    cout << "(" << e.first << "," << e.second << ")" << "\n";
  }
}
