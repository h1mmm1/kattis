#include<bits/stdc++.h>
using namespace std;
const int N=62505;
int mp[N];


int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  int sum=0;
  while(t--){
    sum++;
    vector<int> pq;
    int n,p,q;
    cin >> n >> p >> q;
    for(int i=1;i<=p+1;i++){
      int a;
      cin >> a;
      mp[a]=i;
    }
    for(int i=1;i<=q+1;i++){
      int b;
      cin >> b;
      b=mp[b];
      if(b==0) continue;
      auto v=upper_bound(pq.begin(),pq.end(),b)-pq.begin();
      if(v==pq.size()) pq.push_back(b);
      else pq[v]=b;
    }
    cout << "Case " << sum << ": " << pq.size() << "\n";
    memset(mp,0,sizeof mp);
  }
}


// 1 7 5 4 8 3 9
// 1 2 3 4 5 6 7



// 1 4 3 5 6 2 10 8 9
// 1 4 6 3 0 0 0 5 7

