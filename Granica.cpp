#include<bits/stdc++.h>
using namespace std;
int a[105];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  set<int> s;
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }
  sort(a+1,a+1+n);
  int ans=0;
  for(int i=2;i<=n;i++){
    ans=__gcd(ans,a[i]-a[i-1]);
  }
  for(int i=2;i*i<=ans;i++){
    if(ans%i==0){
      s.insert(i);
      s.insert(ans/i);
    }
  }
  s.insert(ans);
  for(auto e:s){
  	cout << e << ' ';
  }
}
