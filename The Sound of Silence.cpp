#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
multiset<int> s;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m,c;
  cin >> n >> m >> c;
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }
  for(int i=1;i<m;i++){
    s.insert(a[i]);
  }
  bool chk=false;
  for(int i=m;i<=n;i++){
    s.insert(a[i]);
    auto mn=*s.begin();
    auto mx=*(--s.end());
    if(mx-mn<=c) cout << i-m+1 << "\n",chk=true;
    //cout << mn << ' ' << mx << "\n";
    auto v=s.find(a[i-m+1]);
    s.erase(v);
  }
  if(chk==false) cout << "NONE\n";
}

