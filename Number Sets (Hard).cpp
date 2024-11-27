#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=1e6+1;
int pa[N];
bool a[N];
vector<int> p;

inline int find(int v){
  if(pa[v]==v) return v;
  return pa[v]=find(pa[v]);
}

inline void U(int a,int b){
  a=find(a);
  b=find(b);
  if(pa[a]!=b){
    pa[a]=b;
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  for(int i=2;i*i<=sqrt(N);i++){
    if(a[i]==false){
      for(int j=i*i;j<N;j+=i){
        a[j]=true;
      }
    }
  }
  p.push_back(2);
  for(int i=3;i<N;i+=2){
    if(a[i]==false) p.push_back(i);
  }
  int t;
  cin>>t;
  for(int k=1;k<=t;k++){
    ll a,b;
    int c;
    cin >> a >> b >> c;
    ll ans=b-a+1;
    for(int i=1;i<N;i++) pa[i]=i;
    for(auto e:p){
    	if(e<c) continue;
    	if(e>b) break;
      int cnt=0;
      if(a%e!=0) cnt=1;
      for(ll j=(a/e+cnt)*e;j<=b;j+=e){
        if(find((a/e+cnt)*e-a+1)!=find(j-a+1)){
          U((a/e+cnt)*e-a+1,j-a+1);
          ans--;
//          cout << e << ' ' << j << "\n";
        }        
      }
    }
    cout << "Case #" << k << ": " << ans << "\n";
  }
} 
