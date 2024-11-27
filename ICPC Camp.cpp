#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
const int N=2e5+5;
int a[N],b[N];
multiset<int> sss;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,p,q,s;
  cin >> n >> p >> q >> s;
  for(int i=1;i<=p;i++){
    cin >> a[i];
  }
  for(int i=1;i<=q;i++){
    cin >> b[i];
    sss.insert(b[i]);
    
  }
  sort(a+1,a+1+p);
  //sort(b+1,b+1+q);
  int l=0,r=s+1;
  while(l<r){
    multiset<int> ss=sss;
    //for(int i=1;i<=q;i++) ss.insert(b[i]);
    int mid=(l+r)/2,cnt=0;
    for(int i=p;i>=1;i--){
      auto v=ss.upper_bound(min(s-a[i],a[i]+mid));
      if(v==ss.begin()) continue;
      --v;
      if(a[i]+*v<=s && abs(a[i]-*v)<=mid){
        ss.erase(v);
        cnt++;
        
      }
    }
    if(cnt<n) l=mid+1;
    else r=mid;
  }
  if(l>s) cout << "-1";
  else cout << l;
}

