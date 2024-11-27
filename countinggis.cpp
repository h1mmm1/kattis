#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7,N=1e6+5;
int a[N];
bool chk[N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=m;i++){
    cin >> a[i];
    chk[a[i]]=true;
    if(a[i]<=a[i-1]){
      cout << "0";
      return 0;
    }
  }
  if(a[m]!=n){
    cout << "0";
    return 0;
  }
  long long int ans=1,cnt=0;
  for(int i=n;i>0;i--){
    if(chk[i]==false){
      auto v=lower_bound(a+1,a+m+1,i)-a;
      ans=(ans*(cnt+m-v+1))%MOD;
      cnt++;
      //cout << v << "\n";
    }
  }
  cout << ans;
}
